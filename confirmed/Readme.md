# TwixT – CPRO PROJECT (Phase 1)

## Overview
This is the first phase of Project.  
Current functionality focuses on board setup, player turns, move handling, and automatic link/pin marking.  
Win detection is not implemented yet. Each run supports a maximum of 40 moves.

## Build Requirements
- Make  
- No external dependencies

## Building
Inside the project directory:

A new executable is produced and launched automatically in a maximized window.
To clean: make clean


## Running the Game
- After the executable opens, press **Enter** once to start.
- Enter moves in the format:
**"row column"** and then press enter
  do not press enter between/before row column
  Single line. Do **not** press Enter between row and column.
- Links/pins are updated automatically after each move.
- Max 40 moves per session.
- To exit, close the window or terminate the process normally.

## Gameplay Details
- Two-player turn-based input.
- Board size is fixed in this phase.
- Input validation covers out-of-range moves.
- No win detection.


## File Structure
- `main.c` – entry point, game loop
- `var.h` - incuded files
- `depn.h` - header file for main 
- `begin.c / begin.h` – initial visual startup screen
- `link.c / link.h` – link auto-marking logic
- `check/block` - validity of links
- `print` - custom print function
- `move` - pin placement on board
- `display` - renders the board initially
- `utils.c / utils.h` – validation and helpers  
- `Makefile` – build and run targets

