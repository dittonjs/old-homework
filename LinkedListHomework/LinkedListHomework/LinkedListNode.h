//
//  LinkedListNode.h
//  LinkedListHomework
//
//  Created by Joseph Ditton on 4/10/15.
//  Copyright (c) 2015 Joseph Ditton. All rights reserved.
//

#ifndef LinkedListHomework_LinkedListNode_h
#define LinkedListHomework_LinkedListNode_h
#include <iostream>
#include <string>
using namespace std;
//template <class T>
class LinkedListNode {
protected:
    
public:
    LinkedListNode(){
        myData = 0;
        next = NULL;
    }
    LinkedListNode(int thisValue){
        myData = thisValue;
        next = NULL;
    }
 
	~LinkedListNode(){ delete next; }
	int myData;
    LinkedListNode* next;
};


#endif
