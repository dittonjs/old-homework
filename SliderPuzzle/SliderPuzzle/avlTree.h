#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <iostream> 
#include <assert.h>
#include <sstream>
using namespace std;

// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x  
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// Comparable  removeMin  -->  You are not allowed simply to do a find Min and then a remove on that value.  
//                            That would require that you traverse the tree twice  (once to find and once to delete).  We want a true removeMin that 
//                            only traverses in order to delete.
// ******************ERRORS********************************


//HINT:   The class you use as Comparable must have overloaded operators for > == and <.
//        nullptr is another way of saying NULL.  It has some interesting properties for implicit conversions.
//        && is an "rvalue reference".  They are beyond the scope of this class.  A good explanation is at http://thbecker.net/articles/rvalue_references/section_01.html



template <typename Comparable>
class AvlTree
{
public:

	int size = 0;
	int removedCount = 0;

	AvlTree() : root{ nullptr }
	{ }

	AvlTree(const AvlTree & tree) : root{ nullptr }
	{
		root = clone(tree.root);
	}

	AvlTree(AvlTree && tree) : root{ tree.root }
	{
		tree.root = nullptr;
	}

	~AvlTree()
	{
		makeEmpty();
	}

	/**
	* Deep copy.
	*/
	AvlTree & operator=(const AvlTree & tree)
	{
		AvlTree copy = tree;
		std::swap(*this, copy);
		return *this;
	}

	/**
	* Move.
	*/
	AvlTree & operator=(AvlTree && tree)
	{
		std::swap(root, tree.root);

		return *this;
	}

	/**
	* Find the smallest item in the tree.
	* Throw UnderflowException if empty.
	*/
	const Comparable & findMin() const
	{
		assert(!isEmpty()) :
			return findMin(root)->element;
	}

	void removeMin(Comparable & element){ // this is kindof obscure but this is how we are returning the element
		removeMin(root, element);
	}

	/**
	* Find the largest item in the tree.

	*/
	const Comparable & findMax() const
	{
		assert(!isEmpty()) :
			return findMax(root)->element;
	}

	string toString(string indent){
		return toString(root, indent, nullptr);
	}
	

	/**
	* Returns true if x is found in the tree.
	*/
	bool contains(const Comparable & x) const
	{
		return contains(x, root);
	}

	/**
	* Test if the tree is logically empty.
	* Return true if empty, false otherwise.
	*/
	bool isEmpty() const
	{
		return root == nullptr;
	}

	/**
	* Print the tree contents in sorted order.
	*/
	void printTree() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
			printTree(root);
	}

	/**
	* Make the tree logically empty.
	*/
	void makeEmpty()
	{
		makeEmpty(root);
	}

	/**
	* Insert x into the tree; duplicates are ignored.
	*/
	void insert(Comparable & element)
	{
		insert(element, root);
	}

	/**
	* Insert x into the tree; duplicates are ignored.
	* && is termed an rvalue reference.
	* a good explanation is at http://thbecker.net/articles/rvalue_references/section_01.html
	*/
	void insert(Comparable && element)
	{
		insert(std::move(element), root);
	}

	/**
	* Remove x from the tree. Nothing is done if x is not found.
	*/
	void remove(const Comparable & element)
	{
		remove(element, root);
	}

private:
	struct AvlNode
	{
		Comparable element;
		AvlNode   *left;
		AvlNode   *right;
		int       height;

		AvlNode(const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0, int lnc = 0, int rnc = 0)
		: element{ ele }, left{ lt }, right{ rt }, height{ h }{}

		AvlNode(Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0, int lnc = 0, int rnc = 0)
			: element{ std::move(ele) }, left{ lt }, right{ rt }, height{ h } { }
	};

	AvlNode *root;


	string toString(AvlNode * & node, string indent, AvlNode * parent) const
	{
		stringstream ss;

		if (node == nullptr) return "";
		ss << toString(node->right, indent + "   ", node);
		if (parent == nullptr){
			ss << indent << node->element << endl;
		}
		else {
			ss << indent << node->element << endl;
		}

		ss << toString(node->left, indent + "   ", node);


		return ss.str();
	}
	/**
	* Internal method to insert into a subtree.
	* x is the item to insert.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void insert(Comparable & element, AvlNode * & node)
	{
		if (node == nullptr){
			node = new AvlNode{ element, nullptr, nullptr };
			size++;
		}
		else if (element < node->element){
			insert(element, node->left);
		}
		else if (node->element < element){	
			insert(element, node->right);
		}
		else if (node->element == element){
			++element;
			insert(element, node->right);
		}

		balance(node);
	}

	/**
	* Internal method to insert into a subtree.
	* x is the item to insert.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void insert(Comparable && element, AvlNode * & node)
	{
		if (node == nullptr){
			node = new AvlNode{ std::move(element), nullptr, nullptr };
			size++;
		}
		else if (element < node->element){
			insert(std::move(element), node->left);
		}
		else if (node->element < element){
			insert(std::move(element), node->right);
		}
		else if (node->element == element){
			++element;
			insert(std::move(element), node->right);
		}
		balance(node);
	}

	/**
	* Internal method to remove from a subtree.
	* x is the item to remove.
	* t is the node that roots the subtree.
	* Set the new root of the subtree.
	*/
	void remove(const Comparable & element, AvlNode * & node)
	{
		if (node == nullptr)
			return;   // Item not found; do nothing

		if (element < node->element)
			remove(element, node->left);
		else if (node->element < element)
			remove(element, node->right);
		else if (node->left != nullptr && node->right != nullptr) // Two children
		{
			node->element = findMin(node->right)->element;
			remove(node->element, node->right);
		}
		else
		{
			AvlNode *oldNode = node;
			node = (node->left != nullptr) ? node->left : node->right;
			delete oldNode;
			removedCount++;
		}

		balance(node);
	}

	static const int ALLOWED_IMBALANCE = 1;

	// Assume t is balanced or within one of being balanced
	void balance(AvlNode * & node)
	{
		if (node == nullptr)
			return;

		if (height(node->left) - height(node->right) > ALLOWED_IMBALANCE)
			if (height(node->left->left) >= height(node->left->right))
				rotateWithLeftChild(node);
			else
				doubleWithLeftChild(node);
		else
			if (height(node->right) - height(node->left) > ALLOWED_IMBALANCE)
				if (height(node->right->right) >= height(node->right->left))
					rotateWithRightChild(node);
				else
					doubleWithRightChild(node);

		node->height = max(height(node->left), height(node->right)) + 1;
	}

	/**
	* Internal method to find the smallest item in a subtree t.
	* Return node containing the smallest item.
	*/
	AvlNode * findMin(AvlNode *node) const
	{
		if (node == nullptr)
			return nullptr;
		if (node->left == nullptr)
			return node;
		return findMin(node->left);
	}

	// the tree should never be empty when this is called
	void removeMin(AvlNode * & node, Comparable & element){
		if (node->left == nullptr){

			AvlNode *oldNode = node;
			element = oldNode->element;
			node = node->right;
			delete oldNode;
			removedCount++;
		}
		else {
			removeMin(node->left, element);
		}
		balance(node);
	}



	/**
	* Internal method to find the largest item in a subtree t.
	* Return node containing the largest item.
	*/
	AvlNode * findMax(AvlNode *node) const
	{
		if (node != nullptr)
			while (node->right != nullptr)
				node = node->right;
		return node;
	}


	/**
	* Innodeernal method to test if an item is in a subtree.
	* x is item to search for.
	* t is the node that roots the tree.
	*/
	bool contains(const Comparable & element, AvlNode *node) const
	{
		if (node == nullptr)
			return false;
		else if (element < node->element)
			return contains(element, node->left);
		else if (node->element < element)
			return contains(element, node->right);
		else
			return true;    // Match
	}
	/****** NONRECURSIVE VERSION*************************
	bool contains( const Comparable & x, AvlNode *t ) const
	{
	while( t != nullptr )
	if( x < t->element )
	t = t->left;
	else if( t->element < x )
	t = t->right;
	else
	return true;    // Match

	return false;   // No match
	}
	*****************************************************/

	/**
	* Internal method to make subtree empty.
	*/
	void makeEmpty(AvlNode * & node)
	{
		if (node != nullptr)
		{
			makeEmpty(node->left);
			makeEmpty(node->right);
			delete node;
		}
		node = nullptr;
	}

	/**
	* Internal method to print a subtree rooted at t in sorted order.
	*/
	void printTree(AvlNode *node) const
	{
		if (node != nullptr)
		{
			printTree(node->left);
			cout << node->element << endl;
			printTree(node->right);
		}
	}

	/**
	* Internal method to clone subtree.
	*/
	AvlNode * clone(AvlNode *node) const
	{
		if (node == nullptr)
			return nullptr;
		else
			return new AvlNode{ node->element, clone(node->left), clone(node->right), node->height };
	}
	// Avl manipulations
	/**
	* Return the height of node t or -1 if nullptr.
	*/
	int height(AvlNode *t) const
	{
		return t == nullptr ? -1 : t->height;
	}

	int max(int lhs, int tree) const
	{
		return lhs > tree ? lhs : tree;
	}

	/**
	* Rotate binary tree node with left child.
	* For AVL trees, this is a single rotation for case 1.
	* Update heights, then set new root.
	*/
	void rotateWithLeftChild(AvlNode * & node2)
	{
		AvlNode *node1 = node2->left;
		node2->left = node1->right;
		node1->right = node2;
		node2->height = max(height(node2->left), height(node2->right)) + 1;
		node1->height = max(height(node1->left), node2->height) + 1;
		node2 = node1;
	}

	/**
	* Rotate binary tree node with right child.
	* For AVL trees, this is a single rotation for case 4.
	* Update heights, then set new root.
	*/
	void rotateWithRightChild(AvlNode * & node1)
	{
		AvlNode *node2 = node1->right;
		node1->right = node2->left;
		node2->left = node1;
		node1->height = max(height(node1->left), height(node1->right)) + 1;
		node2->height = max(height(node2->right), node1->height) + 1;
		node1 = node2;
	}

	/**
	* Double rotate binary tree node: first left child.
	* with its right child; then node node3 with new left child.
	* For AVL trees, this is a double rotation for case 2.
	* Update heights, then set new root.
	*/
	void doubleWithLeftChild(AvlNode * & node3)
	{
		rotateWithRightChild(node3->left);
		rotateWithLeftChild(node3);
	}

	/**
	* Double rotate binary tree node: first right child.
	* with its left child; then node node1 with new right child.
	* For AVL trees, this is a double rotation for case 3.
	* Update heights, then set new root.
	*/
	void doubleWithRightChild(AvlNode * & node1)
	{
		rotateWithLeftChild(node1->right);
		rotateWithRightChild(node1);
	}
};

#endif

