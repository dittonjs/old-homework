// BSTree.cpp

#include "BSTree.h"
#include <fstream>

// Constructors for the TreeNode class
TreeNode::TreeNode()
{
	ptrLeft = NULL ;
	ptrRight = NULL ;
	freq = 0;
}

TreeNode::TreeNode(string s)
{
	name = s ;
	freq = 0;
	ptrLeft = NULL ;
	ptrRight = NULL ;
}

BSTree::BSTree()
{
	root = NULL ;
	
}

BSTree::~BSTree()
{	
	// TO DO BY YOURSELF
}

void BSTree::Insert (string s)
{	
	size++;
	RInsert (s, root);
}

void BSTree::Delete (string s)
{   
	RDelete (s, root);
}

bool BSTree::Search (string s)
{
	return RSearch(s, root) ;
}

string BSTree::Traverse ()
{	
	//cout << "Postoder traversal " << endl ;
	return RTraverse(root);
}

void BSTree::copyTo(BSTree& tree, TreeNodeptr& ptr){
	
	string ls, rs;

	if (ptr == NULL)
		return;
	else
	{
		for (int i = 0; i <= ptr->freq; i++)
			tree.RInsert(ptr->name, tree.root);
		copyTo(tree, ptr->ptrRight);
		copyTo(tree, ptr->ptrLeft);
		//cout << "Intermediate Result: " << ptr->name << endl;
		
		return;
	}
}

// Steps for recursively inserting a new node
// If node ptr is NULL, assign a new node to it and done.
// Else, if value is less than the node value, insert node on the left pointer
// Else, insert node on the right pointer 

void BSTree::RInsert (string s, TreeNodeptr& ptr)
{	
	if (ptr == NULL)  // Base Case
	{
		ptr = new TreeNode(s);
	}
	else if (ptr -> name == s) {
		ptr->freq++;
	}
	else
	{
		if (s <= ptr->name)
		{
			RInsert (s, ptr->ptrLeft);  // Recursive Case
		}
		else // s > ptr->name
		{
			RInsert (s, ptr->ptrRight);  // Recursive Case
		}
	}
}

// Steps for recursively searching for a node
// If node ptr is NULL, return false and done.
// Else, if value is equal to the node value, return true and done.
// Else, if value is larger than the node value, search node on the right pointer
// Else, search node on the left pointer

bool BSTree::RSearch (string s, TreeNodeptr& ptr)
{
	if (ptr == NULL)
		return false ;
	else if (s == ptr->name)
		return true ;
	else if (s > ptr->name)
		return RSearch(s, ptr->ptrRight) ;
	else // s <= ptr->name
		return RSearch(s, ptr->ptrLeft) ;
}


// Steps for recursively deleting a node
// If value is the same as the node value, deleting operations happen.  Back to here later
// Else, if value is less than or equal to the node value, delete node on the left pointer
// Else, delete node on the right pointer

void BSTree::RDelete (string s, TreeNodeptr& ptr)
{	
	if (ptr != NULL)
	{	
		if (s == ptr->name)	
		{
			DelNode(ptr);
		}
		else if (s <= ptr->name)
		{
			RDelete(s, ptr->ptrLeft);
		}
		else // s > ptr->name
		{
			RDelete(s, ptr->ptrRight);
		}
	}
}

// Steps for recursively traversing a binary search tree in the post order
// Node's left subtree is traversed
// Node's right subtree is traversed
// Node's data is processed

string BSTree::RTraverse (TreeNodeptr ptr)
{	
	string ls, rs;
	
	if (ptr == NULL)
		return " " ;
	else
	{	
		ls = RTraverse(ptr->ptrLeft);
		rs = RTraverse(ptr->ptrRight);
		cout << "Intermediate Result: " << ptr->name << endl ;
		cout << "Freq " << ptr->freq << endl;
		return (ls + ptr->name + " " + rs);
	}	
}

// Deleting a node function considers three scenarios:
// 1. Delete one leaf node
// 2. Delete a node with one child
// 3. Delete a node with two children
//    Attach right subtree
//    Find new location by going all the way left

void BSTree::DelNode(TreeNodeptr& ptr)
{	
	if (ptr->ptrLeft == NULL && ptr->ptrRight == NULL)	// delete a leaf node
	{	
		delete ptr;			
		ptr = NULL;
	}

	else if (ptr->ptrLeft == NULL)	// delete a node with one right child
	{	
		TreeNodeptr here = ptr;
		ptr = ptr->ptrRight;
		delete here;	
	}

	else if (ptr->ptrRight == NULL)	// delete a node with one left child
	{	
		TreeNodeptr here = ptr;
		ptr = ptr->ptrLeft;
		delete here;
	}

	else							// delete a node with two children
	{	
		string successor;
		DeleteSuccessor (ptr, successor);
		ptr->name = successor;
	}
}

void BSTree::DeleteSuccessor(TreeNodeptr ptr, string& s) 
{	
	TreeNodeptr parent = ptr ;

	ptr = ptr->ptrRight;		// one to the right
	int count = 0 ;
	while (ptr->ptrLeft != NULL)
	{	
		count ++ ;
		parent = ptr ;
		ptr = ptr->ptrLeft;		// all the way to the left
	}
	s = ptr->name;
	cout << "The node used to replace value in the removed node contains the value of " << s << endl ;
	
	if (count == 0) // the smallest node in the right subtree of the deleted node is the deleted node's right child
	{
		parent->ptrRight = ptr->ptrRight ;
		delete ptr ;
		ptr = NULL ;
	}
	else
	{
		parent->ptrLeft = ptr->ptrRight ;  // attach the right subtree
		delete ptr ;
		ptr = NULL ;
	}
}
void BSTree::save(string fileName){
	fout.open(fileName);
	STraverse(root, fileName);
	fout.close();
}

void BSTree::load(string fileName){
	ifstream fin;
	fin.open(fileName);
	string a;
	while (!fin.eof){
		getline(fin, a);
		Insert(a);
	}
}

void BSTree::STraverse(TreeNodeptr& ptr, string fileName){
	string ls, rs;

	if (ptr == NULL)
		return;
	else
	{
		
		STraverse(ptr->ptrLeft, fileName);
		STraverse(ptr->ptrRight, fileName);
		fout << ptr->name << " ";
		fout << ptr->freq << endl;
		
	}
}