# Snake Game

This project is a C++ implementation of the classic Snake game. The game features multiple levels, where players navigate the snake to collect fruit and avoid hitting the walls or its own tail. The game ends when the snake collides with itself or the walls (in certain levels). This project also demonstrates the use of Object-Oriented Programming (OOP) techniques to structure the game logic.

## Features:
- **Multiple Levels**:
  - **Level 1**: Standard Snake game.
  - **Level 2**: Includes poison fruits that reduce the score if consumed.
  - **Level 3**: Adds additional challenges and obstacles.
- **Score Tracking**: Score increases as the snake consumes fruit.
- **Object-Oriented Programming**: The game is structured using OOP principles, making the code modular and maintainable.
- **Dynamic Tail Management**: The snake's tail grows as it consumes fruit, managed through arrays and class methods.

## OOP Techniques Used:
- **Classes**:
  - **Fruit Class**: Handles the position and generation of fruits within the game.
  - **Snake Class**: Manages the tail growth and movement of the snake.
- **Encapsulation**: The `Fruit` and `Snake` classes encapsulate the properties and behaviors related to fruits and the snake, respectively, keeping the game logic organized and easy to manage.
- **Methods**:
  - **Fruit Class Methods**: `get_x()`, `get_y()`, `get_fruit_x()`, `get_fruit_y()` are used to generate and retrieve the position of fruits.
  - **Snake Class Methods**: `push()` and `pop()` manage the tail of the snake, simulating the addition and removal of tail segments.

## Controls:
- **Move Up**: Press `W` or `w`
- **Move Down**: Press `S` or `s`
- **Move Left**: Press `A` or `a`
- **Move Right**: Press `D` or `d`

## How to Play:
1. Start the game and choose a level.
2. Use the controls to navigate the snake to collect fruit and avoid obstacles.
3. The game ends if the snake collides with itself or the walls (in some levels).
4. Try to achieve the highest score possible by collecting fruits!

## Getting Started:
- Compile and run the game using a C++ compiler on a Windows machine.
- The game runs in the console with simple ASCII graphics.

## Additional Information:
- The game uses Windows API functions for handling console input and output.
- The logic for different levels is implemented using modular functions to ensure the code is reusable and easy to modify.
