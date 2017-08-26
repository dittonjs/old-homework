#include "OrderedQueue.h"

void OrderedQueue::insert(int item){
	
	LinkedListNode * temp = new LinkedListNode(item);
	LinkedListNode * here = head->next;
	LinkedListNode * prev = head;
	// << here->myData << endl;
	while (item > here->myData){
		prev = here;
		here = here->next;
		//cout << "AM I BEING CALLED?" << endl;
	}

	prev->next = temp;
	temp->next = here;
	totalNodes++;
}

void OrderedQueue::push(int item){
	insert(item);
}

int OrderedQueue::pop(){
	return removeAt(0);
}

int OrderedQueue::removeAt(int pos){
	LinkedListNode * temp = head->next;
	LinkedListNode * prev = head;
	
		for (int i = 0; i <= totalNodes; i++){

			if (i == pos){
				prev->next = temp->next;
				return temp->myData;
			}
			prev = temp;
			temp = temp->next;
		}
	
	
	return -1;
}