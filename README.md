<img width="3347" height="2198" alt="image" src="https://github.com/user-attachments/assets/8841c75d-1d5b-43f5-b19e-050b05fb7d08" />

> [!IMPORTANT]
> ReTiP is an unofficial project

> [!NOTE]
> This Repo has a strict no AI rule, No Vibe Coding, No AI generated Assets, No AI assisted Disassembly/Analysis. This isnt out of virtue signaling, I have fun working on this project. I prefer anyone who works on it to know what's going on beyond just testing to see if claude made it work. 

> [!NOTE]
> I do not consent for my work to be used by Ai as reference and or Ai to work on this project. Due to vibecoded forks, I'll not be uploading any of the code for the rexglue fork or the native renderer as they are the bulk backend of what makes the recomp special. If you wish to help work on the backend join my discord and after a while I'll give you access. Its still possible to build the project on normal rexglue and play on the xenia renderer to develop any PRs or Mods. 

# ReTiP

ReTiP recompiles and hooks Viva Pinata Trouble in Paradise in order to better mod support, and QoL features.

This project features a native renderer post 1.13.0, it also fixes every issue xenia has with rendering. it runs better then emulation by a large margin and is fully recommended to play this recomp over xenia.

Showcase Video: https://youtu.be/Kih42KlocII?si=WeSh2FvBYrwQuNB-

Currently only supports windows, Linux, and soon to be MacOS (MacBook Neo)

## Hardware Requirements

Requires the retail Viva Pinata Trouble in Paradise disc.

### Minimum

- OS: Windows, Linux, Mac
- Processor: Intel Core i5-4460 3.2 GHz 4 Core or AMD Ryzen 3 1200, or equivalent
- Memory: 6 GB RAM
- GPU: Nvidia GTX 1050 Ti or better
- Storage: 15 GB available space
- IO: A controller or a gaming mouse with forward and back buttons

### Recommended
- OS: Windows 11, Linux, Mac
- Processor: Intel Core i7-9700K or AMD Ryzen 7 3700X, or equivalent
- Memory: 16 GB RAM
- GPU: Nvidia RTX 3050 or AMD RX 6600 or better
- Storage: 15 GB available space
- IO: A controller or a gaming mouse with forward and back buttons

## How to Install
You can download and install the game from https://gamejolt.com/games/retip/1087631 If you use their launcher you will get trophies on GameJolt for the actual achievements you would get on Xbox Live.
Otherwise you can download it here, Its the same build just without GameJolt.

Once downloaded and ran, you will be prompted to select a Iso file, This should be a copy of the disk from a legitimate copy of the game. You can follow https://github.com/xenia-canary/xenia-canary/wiki/Quickstart#how-to-rip-games for more details.

After extracting, you can press F5 to manage the mods, The latest 1.12.1 update includes a ThunderStore mod browser that allows you to download user made mods directly from the recomp. Im looking into getting r2modman support so that the external Thunderstore Mod manager works.

## Features

Everything below is new to ReTiP. Most of it is configurable via F4 Menu. Id do ingame menus but all the Viva Pinata menus are hardcoded.

### Graphics

- Custom Aspect ratios via "AspectRatio" value in F4 menu.
- Four quality presets, Low through Ultra via launch menu.
- Graphics toggles to help low end hardware by cutting off Shadows, Ambient Occlusion, Post Processing etc.
- Unlocked FPS with optional caps and VSync.
- Texturepacks.

### Quality of Life

- Unlocked frame rate with a way to cap the fps back to the original fps or vsync.
- Field of view adjustment, By adjusting the aspect ratio the FOV will change as well.
- Skip the in-game cutscenes with a mod I uploaded to thunderstore.
- Partial Unlimited Garden space, Its not complete but it does work with store items. (included and enabled by default)
- Ill need to update this list more later... 
- Shovel Qol mods
- other general improvements like to the camera

### Mods

- Built-in mod manager
- TexturePacks
- AudioPacks
- DataPacks
- Lua Script mods

### Platforms and Languages

- Windows on DX12
- Linux, on Vulkan
- macOS, on MkVulkan
- Language can be changed using a cvar (I'll update this readme later with instructions)

## Credits
- [Franksy32](https://https://github.com/Franksy32) For providing the unlimited garden space patches
- [Smash-chu](https://smash-chu.carrd.co/) For the Title Artwork
- [birabittoh](https://github.com/birabittoh) For the Github Building Workflows
- [Zorkats](https://github.com/Zorkats) For Mouse and Keyboard Support
