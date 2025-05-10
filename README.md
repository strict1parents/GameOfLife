
![Game of Life Preview](https://i.imgur.com/LcvSqFa.gif)


# Game of Life Simulation

A simple and efficient implementation of Conway's **Game of Life** using **C** and **SDL3**.  
This project visualizes cellular automata with real-time rendering and smooth performance.

---

## Features

- High-performance simulation written in C.
- Real-time graphical output using **SDL3**.
- Adjustable simulation speed via keyboard controls.

---

## About Conway's Game of Life

Conway's Game of Life is a cellular automaton where each cell evolves based on simple rules:

1. A living cell with 2 or 3 neighbors stays alive.
2. A living cell with fewer than 2 or more than 3 neighbors dies.
3. A dead cell with exactly 3 neighbors becomes alive.

---

## Build Instructions

### Prerequisites:
- C Compiler (tested with **MinGW**).
- **SDL3** development libraries installed.

### Build:

```bash
git clone https://github.com/yourname/GameOfLife.git
cd GameOfLife
make
```
