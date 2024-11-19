# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## New Features added to the game

1. Allow players to enter their names and save their high scores to a text file -  player names are sorted in descending player score order.
* Assumptions: 
  * The text file format is PlayerName Score (e.g., John 100).
  * Each line represents a different player's score and size.
  * The player's name is unique in the file.


## Project Rubrics
## README (All Rubric Points REQUIRED):
- [x] A README with instructions is included with the project.
- [x] The README indicates which project is chosen.
- [x] The README includes information about each rubric point addressed.
## Compiling and Testing (All Rubric Points REQUIRED)
- [x] The submission must compile and run.
## Loops, Functions, I/O
- [x] The project demonstrates an understanding of C++ functions and control structures.
- [x] The project reads data from a file and process the data, or the program writes data to a file - The project reads data from an external file or writes data to a file as part of the necessary operation of the program.
- [x] The project accepts user input and processes the input.
- [x] The project uses data structures and immutable variables.
## Object Oriented Programming
- [x] One or more classes are added to the project with appropriate access specifiers for class members.
- [x] Class constructors utilize member initialization lists.
- [x] Classes abstract implementation details from their interfaces.
- [ ] Overloaded functions allow the same function to operate on different parameters.
- [ ] Classes follow an appropriate inheritance hierarchy with virtual and override functions.
- [ ] Templates generalize functions or classes in the project.
## Memory Management
- [x] The project makes use of references in function declarations.
- [ ] The project uses destructors appropriately.
- [x] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
- [ ] The project follows the Rule of 5.
- [x] The project uses move semantics to move data, instead of copying it, where possible.
- [x] The project uses smart pointers instead of raw pointers.
## Concurrency
- [ ] The project uses multithreading.
- [ ] A promise and future is used in the project.
- [ ] A mutex or lock is used in the project.
- [ ] A condition variable is used in the project.
    
## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
