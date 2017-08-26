#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Board.h"
const int DIMENSION = 3;

class GameState {
public:
	 GameState& operator++(){
		++priority;
		return *this;
	}
	Board gameBoard;
	int costSoFar;
	int priority = 0;
	int estimatedCost = 0;
	GameState(){};
	// moves is stored in the board itself
	GameState(Board b, int cost){ gameBoard = b; costSoFar = cost; }

	void calculatePriority(){
		priority = costSoFar + estimatedCost;
	};

	void estimateCost(){
		int numberOutOfPlace = 0;
		int val = 1;
		for (int i = 0; i < DIMENSION; i++){
			for (int j = 0; j < DIMENSION; j++){
				if (gameBoard.board[i][j] != val && val != 9){
					numberOutOfPlace++;
				}
				val++;
			}
		}
		estimatedCost = numberOutOfPlace;
	}

	const string toString() const{
		stringstream ss;
		ss << "P: " << priority;
		return ss.str();
	}
	bool operator==(const GameState &other) const {
		if (priority == other.priority) return true;
		return false;
	}
	bool operator<(const GameState &other) const {
		if (priority < other.priority) return true;
		return false;
	}
	bool operator>(const GameState &other) const {
		if (priority > other.priority) return true;
		return false;
	}
};
#endif






