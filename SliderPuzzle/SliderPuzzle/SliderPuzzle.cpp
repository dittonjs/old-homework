// SliderProject.cpp : Defines the entry point for the console application.
//


#include "GameState.h"
#include "Game.h"   // You need to create your own game class
#include <time.h>
#include <iostream> //for some reason i get a cout is ambiguous error if i leave this in.
#include <string>
#include <sstream>
#include "Board.h"
#include "avlTree.h"

ostream&  operator<<(ostream& ss, const GameState& gs) {
	ss << gs.toString() << endl;  return ss;
}


const int SIZE = 3;       // Dimension of board
using namespace std;
int main()
{
	// AVL TREE TEST
	AvlTree<int> tree;
	tree.insert(1);
	tree.insert(3);
	tree.insert(5);
	tree.insert(7);
	tree.insert(9);
	tree.insert(11);
	tree.insert(2);
	tree.insert(4);
	tree.insert(8);
	int min = 0;
	cout << "AFTER ALL INSERTIONS: " << endl;
	cout << tree.toString("   ") << endl;
	tree.remove(7);
	tree.remove(9);
	cout << "AFTER REMOVING 7 & 9: " << endl;
	cout << tree.toString("   ") << endl;
	tree.removeMin(min);
	cout << "AFTER REMOVEMIN 1" << endl;
	cout << tree.toString("   ") << endl;
	tree.removeMin(min);
	cout << "AFTER REMOVEMIN 2" << endl;
	cout << tree.toString("   ") << endl;
	tree.removeMin(min);
	cout << "AFTER REMOVEMIN 3" << endl;
	cout << tree.toString("   ") << endl;
	tree.insert(17);
	cout << "AFTER ADD 17" << endl;
	cout << tree.toString("   ") << endl;
	cout << "GAME STARTS HERE" << endl;
	srand((int)time(NULL));
	
	// create the game
	bool done = false;
	while (!done){
		
		// create the board

		bool solved = false;
		Board board;
		cout << "[1] Random board" << endl;
		cout << "[2] Make your own board" << endl;
		cout << "Enter the number of your choice" << endl;
		int choice;
		cin >> choice;
		
		// setup random board
		if (choice != 2){
			cout << "How difficult would you like the board to be?" << endl;
			cout << "Enter a number 1 - 50" << endl;
			int seed;
			cin >> seed;
			board.makeBoard(seed);
		}
		// get user input and use their board
		else {
			cout << "Enter numbers 0-8 in the order you would like them to be on the board" << endl;
			cout << "WARNING: If the sequence of numbers is unsolvable the game will continue " << endl;
			cout << "until you explicitly tell the program to stop." << endl;
			cout << "Enter each number 1 by 1, pushing enter between each number";
			int nums[9];
			for (int i = 0; i < 9; i++){
				cout << "Enter a number then press enter, keep track of the numbers you have entered." << endl;
				cout << "To see a good example of when the A* method is faster than the brute force " << endl;
				cout << "Enter 2,3,0,14,8,7,6,5" << endl;
				cin >> nums[i];
			}
			board.makeBoard(nums);
		}

		// erase the moves used to create the board
		board.clearMoves();

		// store a copy of the original board for later;

		// insert the first board into the game
		
		cout << "first board: " << endl;
		cout << board.toString() << endl;
		int res;
		cout << "CHOOSE YOUR METHOD: " << endl;
		cout << "[1] Brute force," << endl;
		cout << "[2] A*" << endl;
		cout << "[3] Both" << endl;
		cin >> res;
		if (res == 1){
			Game game(board);
			game.solveBruteForce();
		}
		else if (res == 2){
			Game game(board);
			game.aStarSolve();
		}
		else {
			Game game1(board);
			Game game2(board);
			game1.solveBruteForce();
			game2.aStarSolve();
		}
		

		cout << "Go Again?? [y][n]" << endl;
		char answer;
		cin >> answer;
		if (answer == 'n'){
			done = true;
		}
	}
	return 0;
}