# AGENTS.md - Crazy Circus Game Project

## Build Commands
- `gcc -o crazy src/*.c` - Build the main executable
- `./crazy PLAYER1 PLAYER2` - Run with 2+ player names as arguments
- No formal test framework - manual testing required

## Code Style Guidelines
- **Headers**: Use `#pragma once` in all .h files
- **Documentation**: Doxygen comments with @brief, @param, @return for all functions
- **Naming**: snake_case for functions, PascalCase for types, UPPER_CASE for constants
- **Structure**: Separate .h/.c files, include own header first in .c files
- **Formatting**: 5-space indentation (as seen in existing code)
- **Error handling**: Return 0/1 or -1 for errors, print informative messages
- **Memory**: Use dynamic_array.h for generic collections, manage allocation carefully
- **Dependencies**: Minimal external dependencies, only stdio.h, stdlib.h, string.h, ctype.h

## Project Structure
- Main game logic in jeu.c/h
- Core data structures: podium, cartes, joueur, dynamic_array
- Game flow controlled from main.c
- Configuration read from crazy.cfg