#include "Game.h"

#include <iostream>

void Game::solveBruteForce(){
	Queue *boardQueue = new Queue();
	boardQueue -> insert(firstBoard);
	bool solved = false;
	Board finalBoard;
	while (!solved){
		// we set game back to new head because we delete the old one.
		for (QueueNode *temp = boardQueue->head; temp != NULL; temp = boardQueue->head){
			// check the board to see if its solved
			solved = temp->element.checkSolution();
			if (solved) {
				finalBoard = temp->element;
				break;
			}
			else {
				// if board is not the solution the get all the possible next boards from the current one.
				Board nextBoard1 = temp->element.getNextBoard(temp->element, 'U');
				Board nextBoard2 = temp->element.getNextBoard(temp->element, 'D');
				Board nextBoard3 = temp->element.getNextBoard(temp->element, 'L');
				Board nextBoard4 = temp->element.getNextBoard(temp->element, 'R');

				if (!temp->element.isEqual(nextBoard1)){
					boardQueue->insert(nextBoard1);
				}
				if (!temp->element.isEqual(nextBoard2)){
					boardQueue->insert(nextBoard2);
				}
				if (!temp->element.isEqual(nextBoard3)){
					boardQueue->insert(nextBoard3);
				}
				if (!temp->element.isEqual(nextBoard4)){
					boardQueue->insert(nextBoard4);
				}
				// remove the current board because its not the solution
				boardQueue->remove();
			}
		}


			// use the copy of the original board to show the moves to get the final board.
		cout << "METHOD: BRUTE FORCE" << endl;
		firstBoard.showMe(finalBoard.moves);
		cout << "MOVES TO REACH: " << finalBoard.moves << endl;
		cout << finalBoard.toString() << endl;
		cout << "TOTAL BOARDS ADDED: " << boardQueue->size << endl;
		cout << "BOARDS REMOVED FROM THE QUEUE: " << boardQueue->removedCount << endl;

		// empty the queue of all remaining boards
		boardQueue->removeAll();
		delete boardQueue;
	}
}

void Game::aStarSolve(){
	AvlTree<GameState> gameTree;
	GameState firstState(firstBoard, 0);
	gameTree.insert(firstState);
	Board finalBoard;
	bool solved = false;
	while (!solved){
		
		GameState state;
		gameTree.removeMin(state);
		//cout << "=====================" << endl;
		//cout << "Priority: " << state.priority << endl;
		//cout << state.gameBoard.toString() << endl;
		if (state.gameBoard.checkSolution()){
			solved = true;
			finalBoard = state.gameBoard;
			continue;
		}
		else {
			Board nextBoard1 = state.gameBoard.getNextBoard(state.gameBoard, 'U');
			Board nextBoard2 = state.gameBoard.getNextBoard(state.gameBoard, 'D');
			Board nextBoard3 = state.gameBoard.getNextBoard(state.gameBoard, 'L');
			Board nextBoard4 = state.gameBoard.getNextBoard(state.gameBoard, 'R');

			if (!state.gameBoard.isEqual(nextBoard1)){
				GameState nextState(nextBoard1, state.costSoFar + 1);
				nextState.estimateCost();
				nextState.calculatePriority();
				//cout << "Priority for nextState 1: " << nextState.priority << endl;
				gameTree.insert(nextState);
			}
			if (!state.gameBoard.isEqual(nextBoard2)){
				GameState nextState(nextBoard2, state.costSoFar + 1);
				nextState.estimateCost();
				nextState.calculatePriority();
				//cout << "Priority for nextState 2: " << nextState.priority << endl;
				gameTree.insert(nextState);
			}
			if (!state.gameBoard.isEqual(nextBoard3)){
				GameState nextState(nextBoard3, state.costSoFar + 1);
				nextState.estimateCost();
				nextState.calculatePriority();
				//cout << "Priority for nextState 3: " << nextState.priority << endl;
				gameTree.insert(nextState);
			}
			if (!state.gameBoard.isEqual(nextBoard4)){
				GameState nextState(nextBoard4, state.costSoFar + 1);
				nextState.estimateCost();
				nextState.calculatePriority();
				//cout << "Priority for nextState 4: " << nextState.priority << endl;
				gameTree.insert(nextState);
			}
		}
	}

	cout << "METHOD: A* METHOD" << endl;
	firstBoard.showMe(finalBoard.moves);
	cout << "MOVES TO REACH: " << finalBoard.moves << endl;
	cout << finalBoard.toString() << endl;
	cout << "TOTAL BOARDS ADDED: " << gameTree.size << endl;
	cout << "BOARDS REMOVED FROM THE TREE: " << gameTree.removedCount << endl;
	gameTree.makeEmpty();
}
