### OpenLGR
*An enhancement/loader of the 1999 Game ["Lego Racers"](https://en.wikipedia.org/wiki/Lego_Racers_(video_game))*

It is based on [OpenSWE1R](https://github.com/OpenSWE1R/openswe1r) and developed with the help of [JayFoxRox](https://github.com/JayFoxRox)

The state of the project is not as impressive as it's origins.
![Screenshot of OpenLGR running on Linux](https://krul.finf.uni-hannover.de/~janknittel/images/ingame_hype.png)

The Rest of the README is copied from [OpenSWE1R](https://github.com/OpenSWE1R/openswe1r) and is only pratially applicable.

### Details

This project is a mix of console emulation and something like [WINE](https://www.winehq.org/).
It implements the subset of Windows functions used by the game.
OpenLGR also contains x86 CPU emulation.
The original games code is replaced by open-source code which is patched into the game at runtime.
This is similar to the approach used by [OpenRCT2](https://openrct2.website/), but more emphasis is put on emulation and platform independence.

Currently, not all functions are implemented in the open-source portion.
Therefore, this project also still relies on the original games code.
Even if not all code is patched, the game will still work cross-platform due to the API and CPU abstraction.

You will still need the original game for its art assets: levels, sounds, ...

### Goals

The goal is to eventually replace all of the original code with an open-source equivalent.
The code is supposed to be clean, accurate and portable.
It's not a goal to fix any bugs or modify the games behaviour.
If you want to do such things, they should stay in a fork.

An exception is platform-independence and improvements to the overall code quality.
Some compromises are acceptable.
Please talk to the maintainers if you have a specific case.

It's possible that support for other versions (Mac / Dreamcast / N64) will be added later.
For now, the goal is to support the x86 Windows Version of the game.

### Requirements

**System**

* OpenGL 3.3 Core

**Toolchain**

* [git](https://git-scm.com/)
* [CMake](https://cmake.org/)
* C11 toolchain

**Libraries**

* [Unicorn-Engine](http://www.unicorn-engine.org/)
* [SDL2](https://www.libsdl.org/)
* [GLEW](http://glew.sourceforge.net/)
* [OpenAL](https://www.openal.org/)

### Building

From your desired project folder, run:

```
git clone https://github.com/james-knippes/openlgr.git
cd openlgr
mkdir build
cd build
cmake ..
make
```

### Running

The `openlgr` binary contained in the build directory is a drop-in replacement for `swep1rcr.exe`.
Copy it to your game folder and run it.

### Development

Development happens on GitHub at https://github.com/james-knippes/openlgr
You can help by reviewing other peoples Pull-Requests or sending your own after forking.

---

**© 2017 OpenSWE1R Maintainers**

Licensed under GPL version 2 or later.
