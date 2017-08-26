#ifndef HEAP_H
#define HEAP_H
#include "HeapNode.h"
#include <string>
#include <sstream>
class LeftistHeap
{
public:
	HeapNode * root;
	LeftistHeap(){}
	
	LeftistHeap(Term term){
		root = new HeapNode(term);
	}
	
	void merge(LeftistHeap heap){
		root = merge(root ,heap.root);
	}

	void merge(LeftistHeap *heap){
		root = merge(root, heap->root);
	}

	void merge(HeapNode *otherRoot){
		root = merge(root, otherRoot);
	}

	string toString(){
		return toString(root, "   ", root);
	}

	void printInOrder(int total){
		for (int i = 0; i < total; i++){
			if (root == NULL) return;
			Term a = removeMax();
			cout << a.word << endl;
		}
	}

	string toString(HeapNode * & node, string indent, HeapNode * parent)
	{
		stringstream ss;

		if (node == nullptr) return "";
		ss << toString(node->right, indent + "   ", node);
		if (parent == nullptr){
			ss << indent << node->value.toString() << " NPL: " << node->nullPathLength << endl << endl;
		}
		else {
			ss << indent << node->value.toString() << " NPL: " << node->nullPathLength << endl << endl;
		}

		ss << toString(node->left, indent + "   ", node);


		return ss.str();
	}

	HeapNode * merge(HeapNode * firstRoot, HeapNode *otherRoot){
		HeapNode * largest;
		if (firstRoot == NULL)  return otherRoot;
		if (otherRoot == NULL) return firstRoot; 
		if (firstRoot->value < otherRoot->value) {
			otherRoot->right = merge(otherRoot->right, firstRoot);
			largest = otherRoot;
		}
		else {
			firstRoot->right = merge(firstRoot->right, otherRoot);
			largest = firstRoot;
		} if (notLeftist(largest)) swapKids(largest); 
		setNullPathLength(largest); 
		return largest;
	}

	bool notLeftist(HeapNode *node){
		if (node == NULL) return false;
		if (node->left == NULL && node->right != NULL) return true;
		if (node->left != NULL && node->right == NULL) return false;
		if (node->left->nullPathLength >= node->right->nullPathLength) return false;
		return true;
	}

	void setNullPathLength(HeapNode * node){
		if (node == NULL) return;
		if (node->right == NULL){
			node->nullPathLength = 0;
		}
		else {
			node->nullPathLength = node->right->nullPathLength + 1;
		}
	}

	void swapKids(HeapNode * parent){
		HeapNode * temp = parent->left;
		parent->left = parent->right;
		parent->right = temp;
	}
	
	void insert(Term term){
		HeapNode *temp = new HeapNode(term);
		merge(temp);
	}

	void deleteAll(HeapNode * node){	
		if (node == NULL) return;
		HeapNode *temp = node;
		deleteAll(node->left);
		deleteAll(node->right);
		delete temp;
	}
	
	Term removeMax(){
		HeapNode *temp = root;

		root = merge(root->left, root->right);
		return temp->value;
	}

};

#endif