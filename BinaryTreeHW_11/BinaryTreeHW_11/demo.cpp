// Example for Chapter 19: Binary Trees
// This program demonstrates several basic operations of the Binary Search Tree
// All these basic operations are implemented using recursive functions
// Note: The delete function implements the better solution as explained in slide 16 to maintain the height of the tree
// For simplicity, we assume that there are no whitespaces in the name

#include "BSTree.h"

int main()
{	
	

	BSTree tree;
	BSTree tree2;
	tree.load("fileIn.txt");
	tree.copyTo(tree2, tree.root);
	tree2.save("fileOut.txt");

	cout << "SIZE OF TREE 1: " << tree.size << endl;
	cout << "SIZE OF TREE 2: " << tree2.size << endl;
	system("pause") ;

	return 0 ;
}