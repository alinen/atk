# atk
Animation Toolkit: lightweight C++ library for character animation and motion analysis

## How to build

You will need to have a C++ build environment, git and cmake installed. 
This repository depends on [GLM](https://github.com/g-truc/glm) which is included with this repository.

**Windows**

Git and cmake can be installed with the following:

* [Download and install git](https://git-scm.com/download/win).
* [Download and install cmake](https://github.com/Kitware/CMake/releases/download/v3.19.4/cmake-3.19.4-win64-x64.msi).

If you do not have a C++ compiler on windows, you can use the community version of visual studio. 

* Download and install [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/).
  
*Important!!* During installation, select: Desktop development with C++ 

Dependencies, such as GLM, are included in this repository under /external.

**macOS**

On macOS, install the C++ compiler with xcode. `cmake` can be installed with brew.

* `command xcode-select --install`
* `brew install cmake`

**Ubuntu**

On linux, install the necessary tools and dependencies using `apt-get`.

* `sudo apt-get install cmake`
* `sudo apt-get install git`
