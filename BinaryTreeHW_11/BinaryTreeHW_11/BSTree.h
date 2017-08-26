// BSTree.h
#ifndef BSTREE_H
#define BSTREE_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std ;

class TreeNode
{  
public:
	string name ;
	TreeNode *ptrLeft, *ptrRight ;
	int freq;
	TreeNode() ;
	TreeNode(string s) ;
} ;

// Create an alias that can be used anywhere in place of a (possibly complex) type name
typedef TreeNode* TreeNodeptr ;

class BSTree
{
	
public:	
	BSTree() {}
	~BSTree() { delete[] root; }  // TO DO BY YOURSELF
	TreeNodeptr root;
	void Insert (string s) ;
	void Delete (string s) ;  
	bool Search (string s) ;
	void copyTo(BSTree& tree, TreeNodeptr& ptr);
	string Traverse () ;
	void load(string fileName);
	void save(string fileName);
	void STraverse(TreeNodeptr& ptr, string fileName);
	ofstream fout;
	int size;
private:	
	// Recursive Functions
	// These recursive functions require the functions' arguments to be references to the pointer
	// The reason is that these functions want to change the pointer, i.e., where it points to.

	void RInsert (string s, TreeNodeptr& ptr) ;
	void RDelete (string s, TreeNodeptr& ptr) ;
	bool RSearch (string s, TreeNodeptr& ptr) ;
	string RTraverse (TreeNodeptr ptr) ;

    void DelNode (TreeNodeptr& ptr) ;
    void DeleteSuccessor(TreeNodeptr ptr, string & s) ;  // s will be returned to the called via reference.
} ;
#endif
