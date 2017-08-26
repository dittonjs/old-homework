#ifndef CONNECT_N_GAME_H
#define CONNECT_N_GAME_H


struct Position
{
	int x;
	int y;
};

class ConnectNGame
{
public:
	ConnectNGame(int num);
	~ConnectNGame();
	void Play();


private:
	int numNeededToWin;
	int rows, cols;
	char ** gameBoard;
	void DisplayGameBoard();
	Position PlayerMove();
	Position ComputerMove();
	bool CheckRowWin(Position pos);
	bool CheckColumnWin(Position pos);
	bool CheckRightDiagonalWin(Position pos);
	bool CheckLeftDiagonalWin(Position pos);
	bool CheckTie(Position pos);

};



#endif