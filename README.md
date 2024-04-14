# Blaze Engine [![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

<img src="https://github.com/BlazeTechDev/BlazeEngine/blob/master/github/blaze_logo_text.svg">

# Project Overview
Blaze Engine is an engine designed to be as lightweight as possible with minimal overhead and the ability to run on older and weaker hardware. This is a passion project that is meant to help teach the developer (me) better code legibility, graphics api usage, and game engine architecture. Full transparency, this project is made by someone with no perfessional experience or education and should not be used as such. Feel free to contribute!

> [!IMPORTANT]
> Much of the code in this project was written following The Cherno's game engine series on youtube. The code base (at the moment) is almost identical to Hazel Engine's early source (check out his amazing engine [here](https://github.com/TheCherno/Hazel)). This is planned to change once the project grows

> [!WARNING]
> Blaze Engine currently only supports windows (sorry linux and mac) and runs on MSVC for Visual Studio 2022, other versions of Visual Studio have not been tested

> [!WARNING]
> Blaze Engine is a project made by an ammature developer as a LEARNING PROJECT. Much of this code is unoptomised and flat out messy. If you want to improve the code quality and performance of this project, don't be afraid to get a pull request going ;)

# Building Blaze Engine from source
to build the engine:
- clone the source using:
  - `git clone --recursive https://github.com/BlazeTechDev/BlazeEngine.git`
- build the Visual Studio 2022 project by running the `generate_projects.bat` file
  - this build process if highly untested and may require manually editing the linker and include files in Visual Studio or the premake5.lue file
- open the Visual Studio solution, build the solution, and run!
