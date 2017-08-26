//
//  LinkedList.cpp
//  LinkedListHomework
//
//  Created by Joseph Ditton on 4/10/15.
//  Copyright (c) 2015 Joseph Ditton. All rights reserved.
//

#include "LinkedList.h"
#include "LinkedListNode.h"
#include <iostream>
#include <string>
using namespace std;


LinkedList::LinkedList(){
	head = new LinkedListNode(-9999);
	head->next = new LinkedListNode(9999);
	totalNodes = 0;
}

int LinkedList::Find(int item){
	LinkedListNode * temp = head->next;
	LinkedListNode * prev = head;
	for (int i = 0; i <= totalNodes; i++){

		if (item == temp->myData){
			
			return i;
		}
		prev = temp;
		temp = temp->next;
	}
	return -1;
}

 
int LinkedList::getSize(){
	return totalNodes;
}


void LinkedList::clear(){
	if (totalNodes == 0)return;
	LinkedListNode * temp = head;
	LinkedListNode * prev;
	for (int i = 0; i < totalNodes; i++){
		prev = temp;
		if (i == totalNodes && temp->next!=NULL){
			
			delete temp;
		}
		temp = temp->next;
	}
	totalNodes--;
	clear();
}


LinkedListNode* LinkedList::begin(){
	return head;
}


int LinkedList::insert(int item, int pos){
	LinkedListNode * temp = new LinkedListNode(item);
	LinkedListNode * here = head;
	LinkedListNode * prev = head;
	// << here->myData << endl;
	if (pos != -1 && totalNodes!=0){
		for (int i = 0; i < pos; i++){
			prev = here;
			here = here->next;
			//cout << "AM I BEING CALLED?" << endl;
		}
	}
	if (totalNodes == 0){
		head = temp;
		totalNodes++;
		head->next = NULL;
		return 0;
	}

	
		prev->next = temp;
		temp->next = here;
		totalNodes++;

	return totalNodes;
}

int LinkedList::removeAt(int pos){
	LinkedListNode * temp = head;
	LinkedListNode * prev = head;
	if (pos != 0){
		for (int i = 0; i <= totalNodes; i++){

			if (i == pos){
				prev->next = temp->next;
				return temp->myData;
			}
			prev = temp;
			temp = temp->next;
		}
	}
	else {
		int a = head->myData;
		head = head->next;
		return a;
	}
	return -1;
}



LinkedListNode * LinkedList::at(int pos){
	LinkedListNode * temp = head;
	LinkedListNode * prev;
	for (int i = 0; i < totalNodes; i++){
		prev = temp;
		if (i == pos){
			//prev->next = temp->next;
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}
