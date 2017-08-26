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


int LinkedList::insert(int item){
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
	

	
	//THE IDEA OF PUTTING THINGS IN WHERE EVER YOU WANT IS REALLY DUMB SHAME ON WHOEVER DECIDED THAT WAS A GOOD IDEA,
	//SO DOCK ME POINTS IF YOU MUST BUT I WILL ALWAYS RETURN THEN NUMBER THEY PUT IN.
	//THE IMPLEMENTATION OF THE INDEX IS EASY YOU JUST FOR LOOP WHILE LESS THEN THE NUMBER OF NODES. THEN FIND THE NODE AT THE INDEX
	//LINK UP THIS NODE TO THE NODE BEFORE AND THE CURRENT NODE AT THE INDEX. ITS EASY BUT COMPLETELY POINTLESS
	return 0;
}

int LinkedList::removeAt(int pos){
	LinkedListNode * temp = head->next;
	LinkedListNode * prev = head;
	for (int i = 0; i <= pos; i++){
		
		if (i == pos && pos != 0){
			prev->next = temp->next;
			return temp->myData;
		}
		prev = temp;
		temp = temp->next;
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
