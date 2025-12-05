# TwixT – Phase 1

**UNDER THE GNU PUBLIC LICENSE - FREE FOR USE**

---

Turn-based TwixT variant in C. Players place pins, automatically form knight-move links, and win by completing a border-to-border chain.

---
## UNIQUE FEATURES

THIS VERSION USES ANSI ESCAPE SEQUENCES TO NAVIGATE THE TERMINAL.

(Although it has some issues in minimised windows, it is the most time-efficient way of modifying the console without rerendering)
---
## Objectives
- 24×24 fixed board
- O connects **TOP → BOTTOM**
- X connects **LEFT → RIGHT**
- Links auto-generate on valid knight moves
- Blocked segments prevent link creation
- Connectivity updates after every move
- Win is detected automatically

---

## Rules
- O starts
- Input: `row column`
- Only two integers are read; anything after is ignored
- Out-of-range or occupied positions are rejected
- Corners are not allowed
- O may not play on left/right edges
- X may not play on top/bottom edges
- Max moves: **240**

---

## Win Detection
Each pin propagates connectivity through mutual links:
- O wins on a continuous path from top to bottom
- X wins on a path from left to right

Game ends immediately when either is achieved.

---

## Build (Windows)
Requires `make` and GCC.

## Build mac/linux 
change the target file from a.exe to a.out for LINUX / a.app for mac
the rest is same
requires GCC and MAKE

```bash
make       # build and run
make clean # remove build files
