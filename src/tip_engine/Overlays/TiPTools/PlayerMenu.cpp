#include "PlayerMenu.h"
#include "../TiPTools.h"
#include "src/tip_engine/Types/VivaTags.h"
#include "src/tip_engine/rex_macros.h"
#include "src/tip_engine/Globals.h"

inline int pendingcoins = 0;
inline int pendingexp = 0;
inline int pendinglevel = 0;
inline int playerMainPtr = 0;
// Scene the pointer was captured in; a new garden makes the old player object stale.
inline uint32_t playerMainScene = 0;

REX_PPC_EXTERN_IMPORT(player_playerMainUpdateHighestAndLowestCredits_8252EDA0);
int player_playerMainUpdateHighestAndLowestCredits_8252EDA0_Hook(int playerMain) {
    int result = GuestToHostFunction<int>(__imp__rex_player_playerMainUpdateHighestAndLowestCredits_8252EDA0, playerMain);

    playerMainPtr = playerMain;
    playerMainScene = scene;

    return result;
}
REX_PPC_HOOK(player_playerMainUpdateHighestAndLowestCredits_8252EDA0);

void PlayerMenuPage::OnDraw() {
    auto input = TiPWidgets::PollInput(inputTimer, 0.18f);

    if (input.back) {
        wantsClose = true;
    }

    static constexpr int kOptionCount = 3;

    if(playerMainPtr <= 0 || playerMainScene != scene) {
         ImGui::TextUnformatted("Earn or spend coins once in this garden to detect the player.");
         return;
    }

    coins = std::byteswap(*reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 4));
    experience = std::byteswap(*reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 16));
    int level = std::byteswap(*reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 20));

    // Accelerated up/down navigation
    int vertDir = TiPWidgets::GetHeldDir(SDL_GAMEPAD_BUTTON_DPAD_UP, SDL_GAMEPAD_BUTTON_DPAD_DOWN,
                                          ImGuiKey_UpArrow, ImGuiKey_DownArrow);
    int vertDelta = TiPWidgets::AccelTick(vertAccel, vertDir, 15.0f, 1.0f);
    focusIndex += vertDelta;
    TiPWidgets::WrapIndex(focusIndex, kOptionCount);

    // Reset slider acceleration on focus change
    if (focusIndex != prevFocusIndex) {
        sliderAccel.Reset();
        prevFocusIndex = focusIndex;
    }

    float width = ImGui::GetContentRegionAvail().x;

    TiPWidgets::PushListStyle();
    bool coinsChanged = TiPWidgets::IntSlider("Coins", coins, 0, 999999, focusIndex == 0, width, sliderAccel);
    bool experienceChanged = TiPWidgets::IntSlider("Experience", experience, 0, 999999, focusIndex == 1, width, sliderAccel);
    bool levelChanged = TiPWidgets::IntSlider("Level", level, 0, 196, focusIndex == 2, width, sliderAccel);
    TiPWidgets::PopListStyle();

    // Write only what the user changed. Writing every frame raced the game thread: a level-up
    // was overwritten with the old level, so the game levelled up again, endlessly.
    if (coinsChanged) *reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 4) = std::byteswap(coins);
    if (experienceChanged) *reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 16) = std::byteswap(experience);
    if (levelChanged) *reinterpret_cast<int*>(0x100000000ull + playerMainPtr + 20) = std::byteswap(level);

}
