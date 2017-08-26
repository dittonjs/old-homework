#include "UnionFind.h"
#include <iostream>
#include <time.h>
using namespace std;
const int SIZE1 = 30;
const int SIZE2 = 440; // size of the percolation, extra 2 rows for the data
const int ROW_SIZE = 20;
int main(){
	Pair data[SIZE1];
	UnionFind _uf;
	_uf._initialize(data, SIZE1);
	cout << "DEMONSTRATION 1: " << endl;
	cout << "Union 1 and 2." << endl;
	cout << "Union 4 and 1." << endl;
	cout << "Union 7 and 4." << endl;
	cout << "1, 7 and 4 should have 2 as their parent id and index 2 should have a size of 3" << endl;
	_uf._union(data, 1, 2, SIZE1);
	_uf._union(data, 4, 1, SIZE1);
	_uf._union(data, 7, 4, SIZE1);
	cout << _uf.print(data, SIZE1, SIZE1) << endl;
	cout << "PRESS ENTER TO CONTINUE THE DEMONSTRATIONS" << endl;
	char x;
	cin.ignore();
	cout << "DEMONSTRATION 2: " << endl;
	cout << "Create a second group." << endl;
	cout << "Union 10 and 12" << endl;
	cout << "Union 12 and 16" << endl;
	cout << "Union 16 and 22" << endl;
	cout << "10, 12 and 16 should have 12 as their parent id and index 12 should have a size of 3" << endl;
	cout << "I changed the order that the unions take place to demonstrate that it doesn't matter " << endl;
	cout << "because it is a smart union by size." << endl;
	_uf._union(data, 10, 12, SIZE1);
	_uf._union(data, 12, 16, SIZE1);
	_uf._union(data, 16, 22, SIZE1);
	cout << _uf.print(data, SIZE1, SIZE1) << endl;
	cout << "PRESS ENTER TO CONTINUE THE DEMONSTRATIONS" << endl;
	cin.ignore();
	cout << "DEMONSTRATION 3: " << endl;
	cout << "Union the first and second group together." << endl;
	cout << "To show that union works when unioning leaves of one tree to leaves of another we will" << endl;
	cout << "union 22 and 4 together." << endl;
	cout << "To show again that smart union works I will first union 25 and 22 so that the second tree is bigger.";
	cout << "2 should have 12 as its parent id and 12 should have a size of 8" << endl;
	_uf._union(data, 25, 22, SIZE1);
	_uf._union(data, 22, 4, SIZE1);
	cout << _uf.print(data, SIZE1, SIZE1) << endl;
	cout << "PRESS ENTER TO CONTINUE THE DEMONSTRATIONS" << endl;
	cin.ignore();
	cout << "DEMONSTRATION 4: " << endl;
	cout << "To show that find works with path compression we will do a find on 1." << endl;
	cout << "It should return 12 for its group and then 1 should have a parent id of 12" << endl;
	cout << "1 GROUP IS: " << _uf._find(data, 1) << endl;
	cout << _uf.print(data, SIZE1, SIZE1) << endl;
	cout << "PRESS ENTER TO SHOW PERCOLATION DATA" << endl;
	cin.ignore();

	Pair percolationData[SIZE2];
	_uf._initialize(percolationData, SIZE2);
	_uf.createDummyRows(percolationData, ROW_SIZE, SIZE2);
	cout << "INITIAL GRID" << endl;
	bool hasPercolated = false;
	srand(time(NULL));
	int iter = 0;
	int mod = 50;
	while (!hasPercolated){

		int random = rand() % SIZE2;

		if (percolationData[random].parentId == -1){ // check to see if we are blocked
			if (iter % mod == 0) cout << iter << endl << _uf.printAsGrid(percolationData, SIZE2, ROW_SIZE) << endl << endl << endl;
			_uf._union(percolationData, random, random, SIZE2); // open it;
			if (percolationData[random + 1].parentId != -1) _uf._union(percolationData, random + 1, random, SIZE2); // we can do plus and minus 20 without worry because the 
			if (percolationData[random - 1].parentId != -1) _uf._union(percolationData, random - 1, random, SIZE2); // mod on the random will never give us values withing 20 of
			if (percolationData[random - ROW_SIZE].parentId != -1) _uf._union(percolationData, random - ROW_SIZE, random, SIZE2); // either end
			if (percolationData[random + ROW_SIZE].parentId != -1) _uf._union(percolationData, random + ROW_SIZE, random, SIZE2);
			hasPercolated = _uf._checkPercolation(percolationData, SIZE2);
			if (hasPercolated){
				cout << "PERCOLATION OCCURED AFTER " << iter << "UNBLOCKS" << endl;
				cout << _uf.printAsGrid(percolationData, SIZE2, ROW_SIZE) << endl;
			}
			iter += 1;
		}
	}

	return 0;
}