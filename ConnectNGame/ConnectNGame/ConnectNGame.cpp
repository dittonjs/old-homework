#include "ConnectNGame.h"
#include <iostream>
#include <iomanip>

using namespace std;



ConnectNGame::ConnectNGame(int num)
{
	numNeededToWin = num;
	rows = numNeededToWin + 2;
	cols = numNeededToWin + 3;
	gameBoard = new char*[rows];
	
	for (int i = 0; i < rows; i++){
		
		*(gameBoard+i) = new char[cols];
		
		for (int j = 0; j < cols; j++){
			
			*(*(gameBoard + i) + j) = ' ';
			
		}
	}
}

void ConnectNGame::Play()
{
	bool gameOver = false;
	bool playerWins = false;
	bool tie = false;
	Position myMove;
	Position computerMove;

	while (!gameOver){
		DisplayGameBoard();
		myMove = PlayerMove();
		if (CheckRowWin(myMove)){ playerWins = true; gameOver = true;  continue; }
		if (CheckColumnWin(myMove)){ playerWins = true; gameOver = true;  continue; }
		if (CheckLeftDiagonalWin(myMove)){ playerWins = true; gameOver = true;  continue; }
		if (CheckRightDiagonalWin(myMove)){ playerWins = true; gameOver = true;  continue; }
		if (CheckTie(myMove)){ tie = true; gameOver = true;  continue; }
		DisplayGameBoard();
		computerMove = ComputerMove();
		if (CheckRowWin(computerMove)){ playerWins = false; gameOver = true;  continue; }
		if (CheckColumnWin(computerMove)){ playerWins = false; gameOver = true;  continue; }
		if (CheckLeftDiagonalWin(computerMove)){ playerWins = false; gameOver = true;  continue; }
		if (CheckRightDiagonalWin(computerMove)){ playerWins = false; gameOver = true;  continue; }
		if (CheckTie(computerMove)){ tie = true; gameOver = false;  continue; }
	}
	DisplayGameBoard();

	if (playerWins) cout << endl << endl << "Player Wins!!" << endl;
	else if (tie) cout << endl << endl << "Its a tie" << endl;
	else cout << endl << endl << "Computer wins..." << endl;
	
}

void ConnectNGame::DisplayGameBoard()
{
	cout << "*** CONNECTnGAME ***" << endl << endl;
	for (int i = 0; i < rows; i++){
		cout << "   |";
		for (int j = 0; j < cols; j++){
			cout << *(*(gameBoard+i)+j) << "|";
		}
		cout << endl;
	}
	cout << " ____________________ " << endl;
}

Position ConnectNGame::PlayerMove()
{
	// GET PLAYER INPUT HERE ON WHAT COLUMN HE/SHE WANTS TO MOVE
	int myCol;
	
	cout << "WHICH COLUMN DO YOU WANT TO PLACE YOUR PIECE? (1 - " << cols << ")";
	cin >> myCol;
	Position move;
	move.x = -1;
	move.y = -1;
	for (int i = rows - 1; i > -1; i--)
	{
		if (*(*(gameBoard + i) + (myCol - 1)) != 'p' && *(*(gameBoard + i) + (myCol - 1)) != 'c')
		{
			*(*(gameBoard + i) + (myCol - 1)) = 'p';
			move.x = i;
			move.y = myCol - 1;
			return move;
		}
	}
	
	
	return move;
}

Position ConnectNGame::ComputerMove()
{
	//RANDOMLY GENERATE THE COMPUTER MOVE
	srand(static_cast<unsigned int>(time(NULL)));
	int compCol = rand()%cols;
	Position move;
	move.x = 0;
	move.y = 0;
	for (int i = rows - 1; i > -1; i--)
	{
		if (*(*(gameBoard + i) + compCol) != 'p' && *(*(gameBoard + i) + compCol) != 'c')
		{
			*(*(gameBoard + i) + compCol) = 'c';
			move.x = i;
			move.y = compCol;
			return move;
		}
	}

	return move;
}

bool ConnectNGame::CheckColumnWin(Position pos)
{
	bool iWin = false;
	bool foundP = false;
	int inARowP = 0;
	int inARowC = 0;
	for (int i = rows - 1; i > -1; i--)
	{
		if (*(*(gameBoard+i)+pos.y) == 'p') { inARowP++; inARowC = 0; }
		if (inARowP == numNeededToWin){ iWin = true; return iWin; }
		if (*(*(gameBoard + i) + pos.y) == 'c') { inARowC++; inARowP = 0; }
		if (inARowC == numNeededToWin){ iWin = true; return iWin; }
	}

	return iWin;
}

bool ConnectNGame::CheckRowWin(Position pos)
{
	bool iWin = false;
	bool foundP = false;
	int inARowP = 0;
	int inARowC = 0;
	for (int i = cols - 1; i > -1; i--)
	{
		if (*(*(gameBoard + pos.x) + i) == 'p') { inARowP++; inARowC = 0; }
		if (inARowP == numNeededToWin){ iWin = true; return iWin; }
		if (*(*(gameBoard + pos.x) + i) == 'c') { inARowC++; inARowP = 0; }
		if (inARowC == numNeededToWin){ iWin = true; return iWin; }
		if (*(*(gameBoard + pos.x) + i) != 'p' && *(*(gameBoard + pos.x) + i) != 'c'){ inARowC = 0; inARowP = 0; }
	}

	return iWin;
}

bool ConnectNGame::CheckLeftDiagonalWin(Position pos)
{
	bool iWin = false;
	bool foundP = false;
	int inARowP = 0;
	int inARowC = 0;
	
	
	for (int i = rows - 1; i > 3 - (5-numNeededToWin); i--) 
	{
		for (int j = cols - 1; j > 3 - (5-numNeededToWin); j--)  
		{
			if (*(*(gameBoard+i)+j) == 'p') inARowP++;
			if (*(*(gameBoard + i - 1) + j-1) == 'p') inARowP++;
			if (*(*(gameBoard + i-2) + j-2) == 'p') inARowP++;
			if (numNeededToWin>3 && *(*(gameBoard + i-3) + j-3) == 'p') inARowP++;
			if (numNeededToWin>4 && *(*(gameBoard + i-4) + j-4) == 'p') inARowP++;
			if (inARowP == numNeededToWin){ iWin = true; return iWin; }
			if (*(*(gameBoard + i) + j) == 'c') inARowC++;
			if (*(*(gameBoard + i - 1) + j - 1) == 'c') inARowC++;
			if (*(*(gameBoard + i - 2) + j - 2) == 'c') inARowC++;
			if (numNeededToWin>3 && *(*(gameBoard + i - 3) + j - 3) == 'c') inARowC++;
			if (numNeededToWin>4 && *(*(gameBoard + i - 4) + j - 4) == 'c') inARowC++;
			if (inARowC == numNeededToWin){ iWin = true; return iWin; }
			inARowP = 0;
			inARowC = 0;

		}
	}

	return iWin;

}

bool ConnectNGame::CheckRightDiagonalWin(Position pos)
{
	bool iWin = false;
	bool foundP = false;
	int inARowP = 0;
	int inARowC = 0;


	for (int i = rows - 1; i > 3 - (5 - numNeededToWin); i--)
	{
		for (int j = 0; j < (cols - numNeededToWin + 1); j++)    
		{
			if (*(*(gameBoard+i)+j) == 'p') inARowP++;
			if (*(*(gameBoard + i-1) + j+1) == 'p') inARowP++;
			if (*(*(gameBoard + i-2) + j+2) == 'p') inARowP++;
			if (numNeededToWin>3 && *(*(gameBoard + i-3) + j+3) == 'p') inARowP++;
			if (numNeededToWin>4 && *(*(gameBoard + i-4) + j+4) == 'p') inARowP++;
			if (inARowP == numNeededToWin){ iWin = true; return iWin; }
			
			if (*(*(gameBoard + i) + j) == 'c') inARowC++;
			if (*(*(gameBoard + i - 1) + j + 1) == 'c') inARowC++;
			if (*(*(gameBoard + i - 2) + j + 2) == 'c') inARowC++;
			if (numNeededToWin>3 && *(*(gameBoard + i - 3) + j + 3) == 'c') inARowC++;
			if (numNeededToWin>4 && *(*(gameBoard + i - 4) + j + 4) == 'c') inARowC++;
			if (inARowC == numNeededToWin){ iWin = true; return iWin; }
			inARowP = 0;
			inARowC = 0;

		}
	}

	return iWin;
}

bool ConnectNGame::CheckTie(Position pos)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (*(*(gameBoard + i) + j) != 'p'&& *(*(gameBoard + i) + j) != 'c')
				return false;
		}
	}
	return true;
}

ConnectNGame::~ConnectNGame()
{
	delete[] gameBoard;
	gameBoard = NULL;
}
