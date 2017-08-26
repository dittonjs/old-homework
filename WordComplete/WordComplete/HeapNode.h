#ifndef HEAPNODE_H
#define HEAPNODE_H
#include "term.h"
class HeapNode {
public:
	HeapNode *left;
	HeapNode *right;
	Term value;
	int nullPathLength = 0;
	HeapNode(Term a){
		value = a;
	}
};

#endif