# PA4: MODEL LOADING

## IMPORTANT NOTE:
The output is seen using command line arguments.
The count of arguments passed should be 2.

The first argument passed should be given as:
      random - for random color applied to the object.
      material - for the color to be read from the material file.
      
The second argument passed should be given as:
      box - for the box made from blender.
      dragon - for the dragon object.
      
That is, the command line arguments can be:

./Tutorial random box - for the box to appear with randomly generated colors.
./Tutorial random dragon - for the dragon to appear with randomly generated colors.
./Tutorial material box - for the box to have the material colors from blender.
./Tutorial material dragon - for the dragon to have material colors from blender.
      
 
The material file should be in the build folder.


# Dependencies, Building, and Running

## Dependency Instructions
For both of the operating systems to run this project installation of these three programs are required [GLEW](http://glew.sourceforge.net/), [GLM](http://glm.g-truc.net/0.9.7/index.html), and [SDL2](https://wiki.libsdl.org/Tutorials).

This project uses OpenGL 3.3. Some computers, such as virtual machines in the ECC, can not run this version. In in order to run OpenGL 2.7 follow the instructions at [Using OpenGL 2.7](https://github.com/HPC-Vis/computer-graphics/wiki/Using-OpenGL-2.7)

### Ubuntu/Linux
```bash
sudo apt-get install libglew-dev libglm-dev libsdl2-dev
```

### Mac OSX
Installation of brew is suggested to easily install the libs. Ensure that the latest version of the Developer Tools is installed.
```bash
brew install glew glm sdl2
```



### Makefile Instructions 
The makefile works as expected and must be updated with new files added in.

```bash
mkdir build
cd build
cp ../makefile .
make
./Tutorial
```


