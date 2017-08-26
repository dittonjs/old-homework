#include "Queue.h"
#include <iostream>

// takes a board and sets inserts it at the end of the queue
void Queue::insert(Board board){
	if (head == NULL){
		head = new QueueNode(board);
		tail = head;
		size++;
		return;
	}

	QueueNode * temp = tail;
	temp->next = new QueueNode(board);
	temp->next->previous = temp;
	tail = temp->next;
	size++;
}

// removes the first board from the list
void Queue::remove(){
	QueueNode *temp = this->head;
	head = temp->next;
	head->previous = NULL;
	removedCount++;
	delete temp;
}

// removes all boards from the queue
void Queue::removeAll(){
	if (head == NULL) return;
	QueueNode *temp = head;
	while (temp->next != NULL){
		QueueNode *toDelete = temp;
		temp = temp->next;
		delete toDelete;
	}
	head = NULL;
	tail = NULL;
	removedCount = 0;
	size = 0;
}
