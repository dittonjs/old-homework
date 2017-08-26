#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <assert.h>
using namespace std;

template <class Etype>
class TreeNode
{
public:
	Etype element;
	int leftNodeCount = 0;
	int rightNodeCount = 0;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
	TreeNode(Etype e = 0, TreeNode *l = NULL, TreeNode *r = NULL, TreeNode *p = NULL) :
		element(e), left(l), right(r), parent(p) {}
};

template <class Etype>
class BinarySearchTree
{
protected:
	TreeNode<Etype> *root;
	bool insert(Etype & x, TreeNode<Etype> * & t, TreeNode<Etype>*  p);
	string toString(TreeNode<Etype> * t, string indent, TreeNode<Etype> *parent) const;
	string traverse(TreeNode<Etype> * t) const;
	int recursiveCount(TreeNode<Etype> *t);
	void copyInsert(BinarySearchTree<Etype> &newTree, TreeNode<Etype> * node);
	void recursiveDelete(TreeNode<Etype> *t);
	int recursiveCountLeaves(TreeNode<Etype> *t);
	Etype recursiveFindPredecessor(Etype val, TreeNode<Etype> *node, TreeNode<Etype> *parent, TreeNode<Etype> *root);
	Etype recursiveFindMostRightNode(TreeNode<Etype> *node);
	int recursiveFindNodesInLevel(int level, TreeNode<Etype> *node, int currentLevel);
	Etype recursiveFindKthInOrder(int val, TreeNode<Etype> *node, int currentOrder);
	int findRecursiveWidth(TreeNode<Etype> *node, int& heigth);
	bool recursiveIsIsomorphic(TreeNode<Etype> *node, TreeNode<Etype> *otherNode);
	bool recursiveIsQuasiIsomorphic(TreeNode<Etype> *node, TreeNode<Etype> *otherNode);
	TreeNode<Etype>* recursiveFindCommonAncestor(Etype first, Etype second, TreeNode<Etype> *node);
public:

	BinarySearchTree() : root(NULL) { }
	BinarySearchTree clone(){
		BinarySearchTree<Etype> newTree;
		copyInsert(newTree, root);
		return newTree;
	};
	string toString(string msg = "") const
	{
		return msg + "\n" + toString(root, "   ", NULL);
	}
	virtual int insert(Etype & x) { return insert(x, root, NULL); }
	string traverse(string msg) const
	{
		return msg + "\n" + traverse(root);
	}
	int count(){
		return recursiveCount(root);
	}
	void makeEmpty(){
		recursiveDelete(root);
	}
	int countFringe(){
		return recursiveCountLeaves(root);
	}
	int nodesInLevel(int level){
		return recursiveFindNodesInLevel(level, root, 0);
	}
	int width(){
		int leftHeight = 0;
		int rightHeight = 0;
		int leftWidth = findRecursiveWidth(root->left, leftHeight);
		int rightWidth = findRecursiveWidth(root->left, rightHeight);
		int rootWidth = leftHeight + rightHeight + 1;
		return max(rootWidth, max(leftWidth, rightWidth));
	}
	Etype findKthInOrder(int val){
		return recursiveFindKthInOrder(val, root, 0);
	}
	bool isIsomorphic(BinarySearchTree<Etype> tree){
		return recursiveIsIsomorphic(root, tree.root);
	}
	bool isQuasiIsomorphic(BinarySearchTree<Etype> tree){
		return recursiveIsQuasiIsomorphic(root, tree.root);
	}
	TreeNode<Etype>* lca(Etype first, Etype second);
	Etype predecessor(Etype val);
	void makeTree(vector<Etype> all);
	
};




// returns the elements of the tree in order
// COMPLEXITY O(n)
template <class Etype>
string BinarySearchTree<Etype>::traverse(TreeNode<Etype> *t) const
{
	stringstream ss;
	if (t == NULL) return "";
	ss << traverse(t->left);
	ss << t->element << " ";
	ss << traverse(t->right);
	return ss.str();
}


// prints out the tree using indentation to show levels, also prints out the number
// of child nodes for each node and the parent node for each node.
// COMPLEXITY O(n)
template <class Etype>
string BinarySearchTree<Etype>::toString(TreeNode<Etype> *t, string indent, TreeNode<Etype> *parent) const
{
	stringstream ss;

	if (t == NULL) return "";
	ss << toString(t->right, indent + "   ", t);
	if (parent == NULL){
		ss << indent << t->element << "(no parent)" << "[" << t->leftNodeCount << "," << t->rightNodeCount << "]" << endl;
	}
	else {
		ss << indent << t->element << "(" << parent->element << ")" << "[" << t->leftNodeCount << ", " << t->rightNodeCount << "]" << endl;
	}
	
	ss << toString(t->left, indent + "   ", t);

	
	return ss.str();
}

// Return true if insertion is successful and increments number of child nodes
// COMPLEXITY O(logn)
template <class Etype>
bool BinarySearchTree<Etype>::insert(Etype & x, TreeNode<Etype> * & t, TreeNode<Etype> *  p)
{
	if (t == NULL)
	{
		t = new TreeNode<Etype>(x, NULL, NULL, p);
		if (t == NULL) return false;
		return true;
	}
	bool succeed = false;
	if (x < t->element){
		succeed = insert(x, t->left, t);
		if (succeed) t->leftNodeCount++;
	}
	else if (x > t->element) {
		succeed = insert(x, t->right, t);
		if (succeed) t->rightNodeCount++;
	}
	// cout << "Warning, duplicate ignored " << x << endl;

	return succeed;  // does not allow duplicate insertions
}

// builds a tree
// COMPLEXITY O(n^2)
template <class Etype>
void BinarySearchTree<Etype>::makeTree(vector<Etype> all)
{
	//makeEmpty(root);
	for (unsigned i = 0; i < all.size(); i++)
		insert(all[i]);
}

// counts the nodes in a tree
// COMPLEXITY O(n)
template <class Etype>
int BinarySearchTree<Etype>::recursiveCount(TreeNode<Etype> *t)
{
	if (t == NULL) return 0;
	return 1 + recursiveCount(t->left) + recursiveCount(t->right);
}

// inserts the nodes into the copied tree.
// COMPLEXITY O(n^2)
template <class Etype>
void BinarySearchTree<Etype>::copyInsert(BinarySearchTree<Etype> &tree, TreeNode<Etype> *node)
{
	if (node == NULL)return;
	tree.insert(node->element);
	copyInsert(tree, node->left);
	copyInsert(tree, node->right);
}

//empties the tree
// COMPLEXITY O(n)
template <class Etype>
void BinarySearchTree<Etype>::recursiveDelete(TreeNode<Etype> *node)
{
	if (node == NULL) return;;
	recursiveDelete(node->left);
	recursiveDelete(node->right);
	delete node;
	root = NULL;
}

// counts the leaf nodes
// COMPLEXITY O(n)
template <class Etype>
int BinarySearchTree<Etype>::recursiveCountLeaves(TreeNode<Etype> *node)
{
	if (node == NULL){
		return 0;
	}
	if (node->right == NULL && node->left == NULL){
		return 1;
	}
	return recursiveCountLeaves(node->right) + recursiveCountLeaves(node->left);
}

// triggers the find predecessor function
template <class Etype>
Etype BinarySearchTree<Etype>::predecessor(Etype val)
{
	Etype temp = recursiveFindPredecessor(val, root, root, root);
	return temp;
}


// finds the the element the comes in order before the given element
// COMPLEXITY O(logn)
template <class Etype>
Etype BinarySearchTree<Etype>::recursiveFindPredecessor(Etype val, TreeNode<Etype> *node, TreeNode<Etype> *parent, TreeNode<Etype> *root)
{
	if (node == NULL) return NULL;
	if (val == node->element){
		if (val > parent->element){ 
			if (node->left != NULL){
				Etype temp = recursiveFindMostRightNode(node->left);
					return temp;
			}
			else {
				return parent->element;
			}
		}
		else if (val < parent->element){
			if (node->left == NULL) { 
				TreeNode<Etype> *temp = node->parent;
				while (temp != NULL){
					if (temp->element < val) return temp->element;
					temp = temp->parent;
				}
				return NULL;
			}
			Etype temp = recursiveFindMostRightNode(node->left);
			return temp;
		}

		return NULL;
	}
	if (val > node->element){
		return recursiveFindPredecessor(val, node->right, node, root);
	}
	if (val < node->element){
		return recursiveFindPredecessor(val, node->left, node, root);
	}

	return NULL;
}
// used as a helper for recursiveFindPredecessor, finds the most right child of given node, if no children returns the node.
// COMPLEXITY O(logn)
template <class Etype>
Etype BinarySearchTree<Etype>::recursiveFindMostRightNode(TreeNode<Etype> *node)
{
	if (node->right == NULL) return node->element;
	return recursiveFindMostRightNode(node->right);
}

// finds the number of nodes in a given level
// COMPLEXITY O(n)
template <class Etype>
int BinarySearchTree<Etype>::recursiveFindNodesInLevel(int level, TreeNode<Etype> *node, int currentLevel)
{
	if (node == NULL) return 0;
	if (currentLevel == level){
		return 1;
	}
	return recursiveFindNodesInLevel(level, node->left, currentLevel+1) + recursiveFindNodesInLevel(level, node->right, currentLevel+1);
}

// finds the element in order at the given index, uses the number of children nodes to determine whether to check left or right
// COMPLEXITY O(logn)
template <class Etype>
Etype BinarySearchTree<Etype>::recursiveFindKthInOrder(int val, TreeNode<Etype> *node, int currentOrder)
{
	if(node == NULL) return NULL;
	if (currentOrder + node->leftNodeCount + 1 == val) return node->element;
	if (val > node->leftNodeCount + currentOrder){
		return recursiveFindKthInOrder(val, node->right, currentOrder + node->leftNodeCount + 1);
	}
	if (val < node->leftNodeCount + currentOrder){
		return recursiveFindKthInOrder(val, node->left, currentOrder);
	}
	return NULL;
}

// finds the width of the tree
// COMPLEXITY O(n)
template <class Etype>
int BinarySearchTree<Etype>::findRecursiveWidth(TreeNode<Etype> *node, int &height)
{
	if (node == NULL) return 0;
	int leftHeight = height;
	int rightHeight = height;
	height++;
	int leftWidth = findRecursiveWidth(node->left, height);
	int rightWidth = findRecursiveWidth(node->right, height);
	leftHeight = height - leftHeight;
	rightHeight = height - rightHeight;
	int rootWidth = leftHeight + rightHeight + 1;
	return max(rootWidth, max(leftWidth, rightWidth));
}

// checks to see if the two trees are isomorphic
// COMPLEXITY O(n)
template <class Etype>
bool BinarySearchTree<Etype>::recursiveIsIsomorphic(TreeNode<Etype> *node, TreeNode<Etype> *otherNode)
{
	if (node == NULL && otherNode == NULL) return true;
	if (node == NULL) return false;
	if (otherNode == NULL) return false;
	return recursiveIsIsomorphic(node->left, otherNode->left) && recursiveIsIsomorphic(node->right, otherNode->right);
}
// checks to see if the two trees are quasi-isomorphic
// COMPLEXITY O(n)
template <class Etype>
bool BinarySearchTree<Etype>::recursiveIsQuasiIsomorphic(TreeNode<Etype> *node, TreeNode<Etype> *otherNode)
{
	if (node == NULL && otherNode == NULL) return true;
	if (otherNode == NULL) return false;
	if (node == NULL) return false;
	if (node->left == NULL && otherNode->left != NULL){
		return recursiveIsQuasiIsomorphic(node->right, otherNode->left) && recursiveIsQuasiIsomorphic(node->left, otherNode->right);
	}
	if (node->right == NULL && otherNode->right != NULL){
		return recursiveIsQuasiIsomorphic(node->left, otherNode->right) && recursiveIsQuasiIsomorphic(node->right, otherNode->left);
	}
	return recursiveIsQuasiIsomorphic(node->left, otherNode->left) && recursiveIsQuasiIsomorphic(node->right, otherNode->right);
}

// triggers the recursiveFindCommonAncestor function
template <class Etype>
TreeNode<Etype>* BinarySearchTree<Etype>::lca(Etype first, Etype second){
	return recursiveFindCommonAncestor(first, second, root);
}

// finds the most common ansestor of two given elements
// COMPLEXITY O(logn)
template <class Etype>
TreeNode<Etype>* BinarySearchTree<Etype>::recursiveFindCommonAncestor(Etype first, Etype second, TreeNode<Etype> *node)
{
	if (node == NULL) return NULL;
	if (node->element == first || node->element == second) return node;
	if (!((first > node->element && second > node->element) || (first < node->element && second < node->element))) return node;
	if (first > node->element){ // we only need to check if one is greater than the element because we have already determined if both are greater or less than.
		return recursiveFindCommonAncestor(first, second, node->right);
	}
	else { 
		return recursiveFindCommonAncestor(first, second, node->left);
	}
}