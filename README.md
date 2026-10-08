# Battleship in C++

A two-player terminal Battleship (Schiffe versenken) game from a university programming exercise. The game uses German prompts and runs locally on one computer.

## Features

- Two players place ships on separate 5 × 5 boards.
- Each player has three ships of lengths 1, 2, and 3.
- Placement checks reject overlapping ships and ships outside the board.
- Players alternate turns; missile types cycle between standard, double, and tumbling missiles.
- The game displays hits, detects a winner, and prints end-of-game statistics.

## C++ concepts

Classes and inheritance, templates, operator overloading, vectors, shared pointers, lambdas, and grid traversal/filtering. CMake separates the application from the Sea and GameObjects libraries.

## Build and run

Requirements: CMake 3.20 or newer and a C++20-capable compiler.

### CLion on Windows

1. Extract the project and open its root folder in CLion.
2. Select a configured C++ toolchain, such as MinGW.
3. Let CLion load CMake, select the `Battleship` target, and build/run it.

### Command line

```sh
cmake -S . -B build
cmake --build build
```

For a single-configuration build, run:

```sh
# Linux / macOS
./build/src/app/Battleship
```

```powershell
# Windows with MinGW
./build/src/app/Battleship.exe
```

Multi-configuration generators may place the executable in an additional `Debug` or `Release` directory.

## How to play

1. Enter the first player's name.
2. For each ship, enter `x y` coordinates from 0 to 4 and an orientation: `r` (right) or `u` (down).
3. Repeat for the second player.
4. Alternate entering target coordinates. The missile type is selected automatically by the round.
5. Sink all opposing ships to win.

The board dimensions and fleet sizes are defined in `src/app/init.cpp`.

## Project structure

- `src/app/`: setup, input, game loop, and exercise tests.
- `src/libSea/`: coordinates, objects, and the generic Grid2D container.
- `src/libGameObjects/`: ships, missiles, player boards, and statistics.

## Project status

The project compiles with GCC using C++20. The existing test for Grid2D's `walk` and `filter` functions passes when enabled. This test is disabled by default in `src/app/test.cpp`.

A full interactive playthrough has not yet been verified as part of this check.

## Possible improvements

- Handle closed or interrupted console input.
- Improve board formatting for long player names.
- Fix the tumbling missile's vertical boundary check for rectangular boards.
