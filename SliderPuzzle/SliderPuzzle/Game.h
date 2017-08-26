#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Queue.h"
#include "QueueNode.h"
#include "Board.h"
#include "avlTree.h"
#include "GameState.h"

class Game {
public:
	Board firstBoard;
	void solveBruteForce();
	void aStarSolve();
	Game(Board board){ firstBoard = board; }
};
#endif