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
2. Add another snake to the game that is controlled by the computer using the A* search algorithm. -  An additional snake has been added to the game that is contolled
by the AStar search algorithm.
* The snake controlled by the human and the snake controlled by the computer compete for the same food
* The scores of both the computer and the player are tracked throughout the game


## Project Rubrics
## README (All Rubric Points REQUIRED):
- [x] A README with instructions is included with the project -  Yes!
- [x] The README indicates which project is chosen - Yes.
- [x] The README includes information about each rubric point addressed - Yes!!
## Compiling and Testing (All Rubric Points REQUIRED)
- [x] The submission must compile and run -  project compiles and runs on the Udacity workspace.
## Loops, Functions, I/O
- [x] The project demonstrates an understanding of C++ functions and control structures -  use of functions, loops, switch-cases, if statements used throughout the project.
- [x] The project reads data from a file and process the data, or the program writes data to a file - The project reads data from an external file 
highest_scores.txt and writes data to the file after a game has ended
- [x] The project accepts user input and processes the input - the program asks for username at the end of the game and this is used to update highest_scores.txt file.
- [x] The project uses data structures and immutable variables - const variables, std::vectors, classes, enum classes is used in the project.
## Object Oriented Programming
- [x] One or more classes are added to the project with appropriate access specifiers for class members -  added classes trackScores to handle keeping track of the highest scores in the game 
and AStar to control the second snake in the game
- [x] Class constructors utilize member initialization lists - the constructor of the  Astar class initialises init and goal points.
- [x] Classes abstract implementation details from their interfaces - classes used hide implementation details from the user.
- [ ] Overloaded functions allow the same function to operate on different parameters.
- [ ] Classes follow an appropriate inheritance hierarchy with virtual and override functions.
- [ ] Templates generalize functions or classes in the project.
## Memory Management
- [x] The project makes use of references in function declarations -  references are used in different function declarations throughout the project.
- [ ] The project uses destructors appropriately.
- [x] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate -  using smart pointers in
the project that use RAII and make sure that when they go out of scope, the destructors are called automatically.
- [ ] The project follows the Rule of 5.
- [x] The project uses move semantics to move data, instead of copying it, where possible - use move semantics when passing controller unique pointer in the threads.
- [x] The project uses smart pointers instead of raw pointers - I have implemented renderer and controller unique pointers that are used in 
Game::Run instead of objects .
## Concurrency
- [x] The project uses multithreading. -  I have implemented 3 additional threads to handle input for the 2 snakes
- [ ] A promise and future is used in the project.
- [x] A mutex or lock is used in the project. - A mutex is locked by unique_lock when the worker thread is accessing data in the event queue (critical section)
- [x] A condition variable is used in the project.  - I am using a CV and a unique lock to make a worker thread sleep and wait for 
keyboard key events for the snake to implement 
    
## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
