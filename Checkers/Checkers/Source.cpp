#include <iostream>

using namespace std;
#define DIM 8

void createBoard(int board[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			board[i][j] = 0;
		}
	}
}

void placePeices(int board[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (i == 0 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j] = 1;
			if (i == 1 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j] = 1;
			if (i == 2 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j] = 1;
			if (i == 5 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j] = 2;
			if (i == 6 && (j == 0 || j == 2 || j == 4 || j == 6)) board[i][j] = 2;
			if (i == 7 && (j == 1 || j == 3 || j == 5 || j == 7)) board[i][j] = 2;
		}
	}
}

void printBoard(int board[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (board[i][j] == 0) cout << "*";
			if (board[i][j] == 1) cout << "X";
			if (board[i][j] == 2)cout << "O";
			if (board[i][j] == 3)cout << "K";
			if (board[i][j] == 4)cout << "R";
			cout << " ";
		}
		cout << endl;
	}
}

int getRemaining(int team, int board[DIM][DIM])
{
	if (team == 1)
	{
		int pLeft = 0;
		for (int i = 0; i < DIM; i++)
		{
			for (int j = 0; j < DIM; j++)
			{
				if (board[i][j] == 1 || board[i][j] == 3) pLeft++;
			}
			
		}
		return pLeft;
	}
	else
	{
		int pLeft = 0;
		for (int i = 0; i < DIM; i++)
		{
			for (int j = 0; j < DIM; j++)
			{
				if (board[i][j] == 2 || board[i][j] == 4) pLeft++;
			}

		}
		return pLeft;
	}
}

void movePeice(int pr, int pc, int tr, int tc, int team, int board[DIM][DIM])
{
	// FIRST CHECK IF THE PEICE IS ACTUALLY A PEICE
	if (board[pr][pc] == 1 || board[pr][pc] == 2 || board[pr][pc] == 3 || board[pr][pc] == 4)
	{
		// Then check and make sure that the space where you are moving is blank
		if (board[tr][tc] == 0)
		{
			// check and see if we jumped someone
			if (abs(tr - pr) >= 2)
			{
				// DOWN RIGHT
				if (tr>pr&&tc > pc&&board[pr + 1][pc + 1] != 0)
				{
					board[tr][tc] = team;
					board[pr][pc] = 0;
					board[pr + 1][pc + 1] = 0;
					if (team == 1 && tr == 7) board[tr][tc] = 3;
					if (team == 2 && tr == 0) board[tr][tc] = 4;
				}
				//DOWN LEFT
				if (tr>pr&&tc < pc&&board[pr + 1][pc - 1] != 0)
				{
					board[tr][tc] = team;
					board[pr][pc] = 0;
					board[pr + 1][pc - 1] = 0;
					if (team == 1 && tr == 7) board[tr][tc] = 3;
					if (team == 2 && tr == 0) board[tr][tc] = 4;
				}
				//UP RIGHT
				if (tr<pr&&tc > pc&&board[pr - 1][pc + 1] != 0)
				{
					board[tr][tc] = team;
					board[pr][pc] = 0;
					board[pr - 1][pc + 1] = 0;
					if (team == 1 && tr == 7) board[tr][tc] = 3;
					if (team == 2 && tr == 0) board[tr][tc] = 4;
				}
				// UP LEFT
				if (tr<pr&&tc < pc&&board[pr - 1][pc - 1] != 0)
				{
					board[tr][tc] = team;
					if (board[pc][pr] == 3) board[tr][tc] = 3;
					if (board[pc][pr] == 4) board[tr][tc] = 4;
					board[pr][pc] = 0;
					board[pr - 1][pc - 1] = 0;
					if (team == 1 && tr == 7) board[tr][tc] = 3;
					if (team == 2 && tr == 0) board[tr][tc] = 4;
				}
			}
			board[tr][tc] = team;
			if (board[pr][pc] == 3) board[tr][tc] = 3;
			if (board[pr][pc] == 4) board[tr][tc] = 4;
			board[pr][pc] = 0;
		}
	}
}

int main()
{
	int gameBoard[DIM][DIM];
	createBoard(gameBoard);
	placePeices(gameBoard);
	printBoard(gameBoard);
	int row, col, tRow, tCol, teamN;
	while (getRemaining(1, gameBoard) != 0 && getRemaining(2, gameBoard))
	{
		cout << "ENTER: THE ROW AND COL OF THE PEICE." << endl;
		cin >> row;
		cin >> col;
		cout << "ENTER THE ROW AND COL WHERE YOU WANT TO MOVE AND YOUR TEAM." << endl;
		cin >> tRow;
		cin >> tCol;
		cin >> teamN;
		movePeice(row, col, tRow, tCol, teamN, gameBoard);
		printBoard(gameBoard);
	}

	
	return 0;
}