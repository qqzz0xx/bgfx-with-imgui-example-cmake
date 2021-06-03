# Project template BGFX + ImGui + CMAKE

This is a boilerplate for starting a project with [bgfx](https://github.com/bkaradzic/bgfx) and [dear-imgui](https://github.com/ocornut/imgui) using [cmake](https://cmake.org/) build system generator.


## Usage

```
> git clone https://github.com/mnesarco/bgfx-with-imgui-example-cmake
> cd bgfx-with-imgui-example-cmake
> git submodule update --init --recursive
>
> mkdir build
> cd build
> cmake ..
> cmake --build .
```

# IMPORTANT

* This repo is just an example of how I use bgfx with a dear-imgui version different from the one included in bgfx.
* I have only tested it in my environment: Linux Mint 19.3 and clang 11.0.1
* I do not offer any support, if you find problems I will be happy to accept your solution as a pull request.

## Features

* Vanilla bgfx (via [bgfx.cmake](https://github.com/bkaradzic/bgfx.cmake))
* Valilla imgui (so you can replace it with your own version)
* cmake based (doh)
* External dependencies are git submodules

## Disclaimer

This is the layout I am using in an internal project, I have published this here because it can be useful for someone else, but I do not plan to maintain this activelly. Anyway there is nothing novelty here, so it can be easilly adapted.

My main goal with this layout was to keep untouched versions of bgfx and imgui, everything in a nice cmake structure.

## Notes to self

* bgfx comes with its own version of imgui in `3rdparty/dear-imgui`, that version will not be used by this project.
* Core files of dear-imgui are not modified but some additional files needs to be added, so this is what this project do internally into a temporal dir.
* bgfx integration requires some files from the `examples/common` dir, so I copied them locally. I do not use the files from bgfx directly because these files are just examples so they may need modifications.
* I have added a small file `imgui_bgfx_extra.cpp` to maintain small adjustments depending on the selected imgui branch.
* Current imgui branch is **docking**, if you change it, you may need to comment out everything in `imgui_bgfx_extra.cpp`
* Only tested on linux mint 19.3