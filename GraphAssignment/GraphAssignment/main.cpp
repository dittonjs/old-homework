#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

int main(){
	ifstream file("digraph1.txt");
	int size;
	file >> size;
	Graph g(size);
	cout << g.toString() << endl;
	file.close();
	return 0;
}