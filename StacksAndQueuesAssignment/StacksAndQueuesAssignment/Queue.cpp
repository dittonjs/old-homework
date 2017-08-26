#include "LinkedList.h"
#include "LinkedListNode.h"
#include "Queue.h"

int Queue::pop(){
	int a = removeAt(0);
	return a;
}

void Queue::push(int item){
	insert(item, totalNodes);
}