#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
#include "LinkedListNode.h"

class Queue : public LinkedList{
public:
	Queue(){ totalNodes = 0; };
	Queue(int item){ head = new LinkedListNode(item); totalNodes = 1; }
	int pop();
	
	void push(int item);
protected:

};
#endif