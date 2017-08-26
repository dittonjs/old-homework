#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "QueueNode.h"

class Queue {
public:
	int size = 0; // not the current size but the total number of elements added
	int removedCount = 0; // how many elements we have removed from the queue
	QueueNode *head; // pointer to the head of the queue
	QueueNode *tail; // pointer to the tail
	void insert(Board board); // insert a new board
	void remove(); // remove the first board
	void removeAll(); // empty the queue
};
#endif