#ifndef LIFE_H
#define LIFE_H
const int ROWS = 25;
const int COLS = 25;

// Simulte one generation of Conways Game of Life
// 
// Given: 
//        a constant 2D bool array called "current" where each true element
//        indicates a live cell and each false element indicates a dead cell.
//
//        an empty  2D bool array called "next"
//
// Desired:
//        the next generation of the game of life written into the "next" array
//
//        "current" should remain unchanged
//
// The rules of the Game Of Life are as follows:
//
//        1. Any live cell with fewer than two live neighbours dies, as if
//           caused by under-population.
//
//        2. Any live cell with two or three live neighbours lives on to the
//           next generation.
//
//        3. Any live cell with more than three live neighbours dies, as if by
//           overcrowding.
//
//        4. Any dead cell with exactly three live neighbours becomes a live cell,
//           as if by reproduction.

void life(const bool current[ROWS][COLS], bool next[ROWS][COLS]);
#endif