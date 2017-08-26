#ifndef ORDERED_QUEUE_H
#define ORDERED_QUEUE_H
#include "LinkedList.h"
#include "LinkedListNode.h"
#include "Queue.h"

class OrderedQueue: public Queue{
public:
	OrderedQueue() :Queue(){ head = new LinkedListNode(-9999); head->next = new LinkedListNode(9999); }
	//OrderedQueue(int item) :Queue(item){}
	int removeAt(int pos);
	void push(int item);
	void insert(int item);
	int pop();

private:
};
#endif