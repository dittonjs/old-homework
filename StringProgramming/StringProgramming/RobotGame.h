#ifndef ROBOT_GAME_H
#define ROBOT_GAME_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class RobotGame
{
public:
	RobotGame(int r, int c);
	~RobotGame();
	void Play(istringstream &com);
	bool GetGameOver();

private:
	char ** map;
	int x, y;
	int myDirection;
	int rows, cols;
	int myGolds, myDiamonds;
	int diamondCount, goldCount;
	int rowsFull;
	void DisplayGameBoard();
	int MoveRobot(int dist);
	void RotateRobot(double deg);
	void PickUp();
	void LoadRow(int a, char *b);
	int GetDir(char *a);
	bool gameOver;
	string printDirection();

	 
};



#endif