#include "Board.h"
using namespace std;
// Create a printable representation of the Board class
// The stringstream allows you to use the power of output commands in creating a string
string Board::toString(){
	stringstream ss;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			ss << board[i][j] << " ";
		ss << endl;
	}
	//ss << "[" << blankRow << "," << blankCol << "]\n";
	return ss.str();
};



// return true if board is identical to b
bool Board::operator==(Board &b) {

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (board[i][j] != b.board[i][j]) return false;
	return true;
}

//Create a board by performing legal moves on a board
//jumbleCt indicates the number of moves that may be required
//if jumbleCt ==0, return the winning board
void Board::makeBoard(int jumbleCt) {
	int val = 1;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = val++;
	blankRow = SIZE - 1;
	blankCol = SIZE - 1;
	board[blankRow][blankCol] = 0;
	jumble(jumbleCt);
}

//Create a board from a given set of values
void Board::makeBoard(int values[]) {
	int c = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++){
		if (values[c] == 0){
			blankRow = i;
			blankCol = j;
		}
		board[i][j] = values[c++];
		}
}

//Copy constructor
Board::Board(const Board & b) {
	//cout << "Just Copied Board\n" << b.toString() << endl;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = b.board[i][j];
	blankRow = b.blankRow;
	blankCol = b.blankCol;
	moves += b.moves;
}


bool Board::slideUp()  // If possible, slides a tile up into the blank position.  Returns success of operation.
{
	if (blankRow == SIZE - 1) return false;
	swap(board[blankRow][blankCol], board[blankRow + 1][blankCol]);
	blankRow += 1;
	return true;
}

// reset the moves to an 'empty' string
void Board::clearMoves(){
	moves = " ";
}

bool Board::slideDown()  // If possible, slides a tile down into the blank position.  Returns success of operation.
{
	if (blankRow == 0) return false;
	swap(board[blankRow][blankCol], board[blankRow - 1][blankCol]);
	blankRow -= 1;
	return true;
}
bool Board::slideLeft()  // If possible, slides a tile left into the blank position.  Returns success of operation.
{
	if (blankCol == SIZE - 1) return false;
	swap(board[blankRow][blankCol], board[blankRow][blankCol + 1]);
	blankCol += 1;
	return true;
}
bool Board::slideRight()  // If possible, slides a tile right into the blank position.  Returns success of operation.
{
	if (blankCol == 0) return false;
	swap(board[blankRow][blankCol], board[blankRow][blankCol - 1]);
	blankCol -= 1;
	return true;
}


// Randomly apply ct moves to the board, makingsure they are legal and don't undo the previous move
void Board::jumble(int ct) {
	string moveStr = "UDLR";  // Moves representing Up, Down, Left, Right
	char lastMove = ' ';
	char thisMove = ' ';
	for (int i = 0; i < ct; i++)
	{
		thisMove = ' ';
		while (thisMove == ' ')
		{
			thisMove = moveStr[rand() % 4];
			thisMove = makeMove(thisMove, lastMove);
		}
		lastMove = thisMove;
		cout << "JUMBLE Moves" << thisMove << '\n';
	}
}

// Make the move indicated by m (L Left, R Right, U Up, D Down) if it is legal and if it doesn't undo the move specified by lastmove
// Return a blank if the move could not be made, otherwise return the move
char Board::makeMove(char m, char lastmove)
{
	if (lastmove == 'A'){
		bool moved = false;
		switch (m)
		{
		case 'R': if (true) { moved = slideRight(); } break;
		case 'L': if (true) { moved = slideLeft(); } break;
		case 'D': if (true) { moved = slideDown(); } break;
		case 'U': if (true) { moved = slideUp(); }  break;
		}
		if (!moved)
			return ' ';
		return m;
	}

	bool moved = false;
	switch (m)
	{
	case 'R': if (lastmove != 'L') { moved = slideRight(); } break;
	case 'L': if (lastmove != 'R') { moved = slideLeft(); } break;
	case 'D': if (lastmove != 'U') { moved = slideDown(); } break;
	case 'U': if (lastmove != 'D') { moved = slideUp(); }  break;
	}
	if (!moved)
		return ' ';
	moves += m; // keep track of the moves to get to this board.
	return m;
}

// create a new board using the old board and a move then return it.
Board Board::getNextBoard(Board board, char move){
	//cout << "INITIAL BOARD: " << board->toString() << endl;

	Board temp(board);
	char m = temp.makeMove(move, moves.back());
	//game->insert(temp);
	if (m != ' ') {
		//cout << m << " " << "==> " << endl;
		//cout << temp->toString() << endl << endl;
		return temp;
	}
	return board;
}

bool Board::isEqual(Board otherBoard){
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			if (board[i][j] != otherBoard.board[i][j]){
				return false;
			}
		}
	}
	return true;
}

// takes a list of moves and prints out where the board would go.
void Board::showMe(string myMoves){
	for (int i = 0; i < myMoves.length(); i++){
		if (myMoves[i] == ' ') continue;
		char m = makeMove(myMoves[i], 'A');
		//game->insert(temp);

		if (m != ' ') {
			cout << "==> " << m << endl;
			cout << toString() << endl;
		}
	}
}

// checks to see if the board is at the solution
bool Board::checkSolution(){
	bool finished = true;
	int val = 1;
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			if (board[i][j] != val && val != 9){
				finished = false;
				break;
			}
			val++;
		}
	}
	return finished;
}

