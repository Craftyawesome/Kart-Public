# SRB2Kart

[SRB2Kart](https://srb2.org/mods/) is a kart racing mod based on the 3D Sonic the Hedgehog fangame [Sonic Robo Blast 2](https://srb2.org/), based on a modified version of [Doom Legacy](http://doomlegacy.sourceforge.net/).

This fork aims to support the Nintendo Switch.

## Installation Instructions
1. Make sure your Switch can run homebrew.
2. Extract the contents of the zip to the root of your SD card.
3. Start SRB2Kart via hbmenu (or whatever method you prefer).

NOTE: This game requires full RAM access. This means you can't launch hbmenu from the album applet when running this. With the latest Atmosphere build and its default config, you can hold R while starting any game to open hbmenu with full RAM access.

## Update Instructions
Extract the contents of the update patch to the root of your SD card. Overwrite any files that might conflict.

## Features
- Full online support
- Full mouse/keyboard support
- Full software keyboard support

## Notes
- I've included a kartconfig.cfg that sets the resolution to 800x450 by default. It doesn't really do anything else so you can leave it out if you'd like.
- The game takes a bit to boot. A faster SD card may help with this.
- Without a config file, the game's default resolution is 320x200. I recommend setting it to 800x450 for the best balance of performance and visuals.
- The game continues to run while on the Switch's home screen when you are unable to pause to prevent lag-switching.
- If you want to play the game with mouse/keyboard, you'll have to bind most of the buttons yourself.
- All button bindings are set to match the Xbox controller layout (Xbox A -> Switch B, Xbox X -> Switch Y, etc.)

## Compilation

### Dependencies
- NASM (x86 builds only)
- SDL2 (Linux/OS X only)
- SDL2-Mixer (Linux/OS X only)
- libupnp (Linux/OS X only)
- libgme (Linux/OS X only)

### Compiling

See [SRB2 Wiki/Source code compiling](http://wiki.srb2.org/wiki/Source_code_compiling). The compiling process for SRB2Kart is largely identical to SRB2.

### Switch

Follow the instructions [here](http://wiki.srb2.org/wiki/Source_code_compiling/Makefiles), using the following make command:
```
make -C src/ SWITCH=1
```
Or, if you want to enable network debugging:
```
make -C src/ SWITCH=1 ENABLE_NXLINK=1
```
If you plan on switching flags, make sure to run `make clean` first.

More complete build instructions coming soon(TM).


## Disclaimer
Kart Krew is in no way affiliated with SEGA or Sonic Team. We do not claim ownership of any of SEGA's intellectual property used in SRB2.

I (heyjoeway), STJr, Kart Krew, or the SRB2MB are in no way responsible if this port somehow manages to break your Switch.
