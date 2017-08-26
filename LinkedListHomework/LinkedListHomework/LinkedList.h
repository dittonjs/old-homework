//
//  LinkedList.h
//  LinkedListHomework
//
//  Created by Joseph Ditton on 4/10/15.
//  Copyright (c) 2015 Joseph Ditton. All rights reserved.
//

#ifndef LinkedListHomework_LinkedList_h
#define LinkedListHomework_LinkedList_h
#include "LinkedListNode.h"
#include <string>
using namespace std;

class LinkedList {
protected:
    
public:
    LinkedListNode* head;
    LinkedList();
	~LinkedList(){ delete head; }
    int totalNodes;
    int insert(int item);
    int removeAt(int pos);
    int Find(int item);
    void clear();
    int getSize();
    LinkedListNode* begin();
    LinkedListNode* at(int pos);
};

#endif
