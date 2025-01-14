# Vox
Vox engine is an open source voxel engine that is written in C++ and OpenGL and can be used to create easy and fast voxel based games and applications. The engine is written to be highly functional and very efficient at allowing voxel game creation and provides a simple framework for creating 3D voxel games.

## Features
* 3D voxel engine with cuboid and box-based rendering aesthetic. 
* GLSL shader support.
* Support for deferred or forward rendering.
* Fully dynamic and unlimited lighting system using deferred lighting model.
* Advanced graphics shaders included - SSAO, shadow mapping, dynamic lighting, FXAA.
* Full 3D math and geometry library (vector, matrix, quaternion, plane, bezier).
* Extensive camera functionality, either 3rd person or 1st person.
* In-built GUI that can be easily hooked up to gameplay functioanlity. (re-skinable)
* Qubicle Binary (.qb) voxel model loading.
* Polygon model loading via ms3d and obj files.
* Keyframe and skeleton animation support.
* Basic 'player' functionality - movement, controls, animation.
* 'Voxel character' encapsulating character behaviours - idle looking, breathing, etc.
* Facial animation support for voxel characters.
* Voxel scenery and world items.
* Block/cube particle effect system.
* Modding and scripting support via LUA.
* Gamepad and controller support.
* Voxel world and terrain generation.
* Procedural content creation.
* *[coming soon!]* In-built voxel editor for creation/editing of in-game assets.
* *[coming soon!]* Audio and music playback.

## Gameplay Features
Some parts of the Vox gameplay logic are also incorporated into this source code repo, to better facilitate code sharing and the different sub-systems that make up the game. Some of the gameplay features of Vox are as follows:
* Player movement and controls.
* Inventory and item management.
* NPC AI and player interations.
* Quets and gameplay objectives.
* Enemies and monsters.
* Combat using melee and ranged weapons, magic and spellcasting.
* Farming and crop management.
* Character creation and player generation.
* World customization and creation elements.

## Setup
Setting up and compiling the project is a fairly simple process. Cmake can be used to build the project files for each environment and for different platforms, depending on what you are developing on. Just run CMake on the root level of the project.

## Building the Source Code

There are various different methods for building the Vox executable from the source, the recommended method is to use CMake on your desired OS and platform. Various project files are also inculded and can be used to build the Vox executable without CMake, but note however that there is no guarantee that these project files will always be updated and contain the latest changes to the source tree, to be absoutely sure that you are building using the latest source, always create your own project and solution files using CMake.

**CMake**

Run CMake from the root directory level of ```/Vox```.

**Windows**

Visual Studio projects are included inside the ```\project``` sub-folder (VS2012, VS2013, VS2015).

**Linux**

Various project files are included inside the ```\project\linux``` sub folder. (TODO: Add more Linux project and solution files)

**Mac**

// Todo //

## Running
The Vox executable needs to be run from the root directory so that it has access at the top level to the ```\media``` folder that contains all the game content files. If you want to run the game's executable from within the Visual Studio projects then you will need to set the working directy in the Debugging options to ```'..\..\'``` since the visual studio projects files reside various in sub-directories above the root.

Alternatively you can run the pre-built executable ```VoxGame.exe``` that is containted within this github repo. For running the prebuilt executable on Linux you can simply run ```./VoxGame``` from within the root ```/Vox``` directory. *(Please note however that there is no guarantee that this exe will contain the latest code from the repo.)*

## License
This software is provided under the **GNU General Public License**, more information is provided in the [license file](https://github.com/AlwaysGeeky/Vox/blob/master/LICENSE.md).

## How To Contribute
Contributions are always welcome, either reporting issues/bugs or forking the repository and then issuing pull requests when you have completed some additional coding that you feel will be beneficial to the main project. If you are interested in contributing in a more dedicated capacity, then please contact me.

## Contact
You can contact me via twitter at http://www.twitter.com/AlwaysGeeky. I am always happy to answer questions or help with any issues you might have, and please be sure to share any additional work or your creations with me, I love seeing what other people are making.

## Screenshots
![Vox](http://i.imgur.com/usPCqJt.png)
![Vox](http://i.imgur.com/mZ85dWP.png)
![Vox](http://i.imgur.com/o2toMnf.png)

## Videos
Various videos are avilable at http://www.youtube.com/AlwaysGeeky
