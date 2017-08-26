#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "RobotGame.h"

using namespace std;



RobotGame::RobotGame(int r, int c)
{
	diamondCount = 0;
	goldCount = 0;
	rows = r;
	myDiamonds = 0;
	cols = c;
	myGolds = 0;
	gameOver = false;
	rowsFull = 0;
	map = new char*[rows];
	
	for (int i = 0; i < rows; i++)
	{
		map[i] = new char[cols];
	}

}

RobotGame::~RobotGame()
{
	delete[] map;
	map = NULL;
}

void RobotGame::Play(istringstream &com)
{
	char temp[10];
	com >> temp;
	//cout << temp;

	
	if (rowsFull < rows)
	{
		//cout << rowsFull;

		LoadRow(rowsFull, temp);
		rowsFull++;
	}
	else 
	{
		string oTemp = temp;
		
		if (oTemp == "ROBOT")
		{
			
			com >> temp;
			int a = atoi(temp) -1;
			cout << temp;
			com >> temp;
			int b = atoi(temp) -1;
			cout << temp;
			com >> temp;
			cout << temp << endl;
			int c = GetDir(temp);
			x = a;
			y = b;
			myDirection = c;
			//cout << "Robot is facing " << printDirection() << " at position (" << y << "," << x << ")" <<endl;
			cout << "Board is:" << endl;
			DisplayGameBoard();
		}
		else if (oTemp == "MOVE")
		{
			com >> temp;
			int a = MoveRobot(atoi(temp));
			cout << "Command is Move " << temp << " space" << endl;
			cout << "Board is:" << endl;
			DisplayGameBoard();
		}
		else if (oTemp == "ROTATE")
		{
			com >> temp;
			double a = atof(temp);
			RotateRobot(a);
			cout << "Command is Rotate " << temp << " Degrees" << endl;
			cout << "Board is:" << endl;
			DisplayGameBoard();
		}
		else if (oTemp == "PICKUP")
		{
			cout << "Command is Pickup " << temp << " space" << endl;
			
			PickUp();
			DisplayGameBoard();
		}
		else if (oTemp == "QUIT")
		{
			gameOver = true;
		}
		else 
		{
			cout << "NOT A VALID COMMAND" << endl;
			
			DisplayGameBoard();
		}

	}
	
}

void RobotGame::DisplayGameBoard()
{
	
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == x && j == y) 
			{
				cout << "R" << " ";
				continue;
			}
			cout << map[i][j] << " ";
		}
		cout << endl;
	} 

	cout << "Gold Left: " << goldCount << "Golds Possesed: " << myGolds << endl;
	cout << " Diamonds Left: " << diamondCount << "Diamonds possesed: " << diamondCount;
}

int RobotGame::MoveRobot(int dist)
{
	cout << myDirection << endl;
	int dir = myDirection;
	switch (dir)
	{
	case 0:
		x -= dist;
		if (x < 0) x = 0;
		if (x > rows) x = rows;
		break;
		
	case 1:
		x -= dist;
		y += dist;
		if (x < 0)x = 0;
		if (y < 0) y = cols;
		if (x > rows )x = rows;
		if (y > cols) y = cols;
		break;
	case 2:
		y += dist;
		if (y > cols) y = cols;
		if (y < 0) y = 0;
		break;
	case 3:
		cout << "Am I Here?" << endl;
		x += dist;
		y += dist;
		if (x < 0)x = 0;
		if (y < 0) y = cols;
		if (x > rows)x = rows;
		if (y > cols) y = cols;
		break;
	case 4:
		x += dist;
		if (x < 0) x = 0;
		if (x > rows) x = rows;
		break;
	case 5:
		x += dist;
		y -= dist;
		if (x < 0)x = 0;
		if (y < 0) y = cols;
		if (x > rows)x = rows;
		if (y > cols) y = cols;
		break;
	case 6:
		y -= dist;
		if (y < 0) y = 0;
		if (y > rows) y = rows;
		break;
	case 7:
		x -= dist;
		y -= dist;
		if (x < 0)x = 0;
		if (y < 0) y = cols;
		if (x > rows)x = rows;
		if (y > cols) y = cols;
		break;
	default:
		break;
	}
	return 0;
}

void RobotGame::RotateRobot(double deg)
{
	double turn = deg / 45;
	myDirection += turn;
	if (myDirection > 7) myDirection -= 8;
	if (myDirection < 0) myDirection = 8 - myDirection;
}

void RobotGame::PickUp()
{
	if (map[x][y] == 'D'){
		diamondCount--; map[x][y] = '_';
		myDiamonds++;
		cout << "found diamond" << endl;
	}

	 else if (map[x][y] == 'G'){
		goldCount--; map[x][y] = '_';
		myGolds++;
		cout << "Found Gold" << endl;
	 }
	 else 
	 {
		 cout << "Found Nothing" << endl;
	 }
	if (goldCount == 0 && diamondCount == 0)
	{
		gameOver = true;
	}

	
}

void RobotGame::LoadRow(int a, char *b)
{
		for (int i = 0; i < strlen(b)+1;i++)
		{
			map[a][i] = b[i];
			
			if (map[a][i] == 'D') diamondCount++;
			if (map[a][i] == 'G') goldCount++;
		}
		
}

int RobotGame::GetDir(char *b)
{
	string a = b;
	
	if (a == "NORTH")
		return 0;
	if (a == "NORTHEAST")
		return 1;
	if (a == "EAST")
		return 2;
	if (a == "SOUTHEAST")
		return 3;
	if (a == "SOUTH")
		return 4;
	if (a == "SOUTHWEST")
		return 5;
	if (a == "WEST")
		return 6;
	if (a == "NORTHWEST")
		return 7;
}

string RobotGame::printDirection()
{
	
	if ( myDirection == 0)
		return "North";
	if (myDirection == 1)
		return "Northeast";
	if (myDirection == 2)
		return "East";
	if (myDirection == 3)
		return "SouthEast";
	if (myDirection == 4)
		return "South";
	if (myDirection == 5)
		return "SouthWest";
	if (myDirection == 6)
		return "West";
	if (myDirection == 7)
		return "Northwest";
}

bool RobotGame::GetGameOver()
{
	return gameOver;
}

