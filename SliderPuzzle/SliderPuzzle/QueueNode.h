#pragma once
#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H

#include <string.h>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <sstream>
#include "Board.h"

using namespace std;
class QueueNode {
public:
	// we are using the boards as nodes in our linked list
	QueueNode *next;
	QueueNode *previous;
	Board element;
	QueueNode(Board board){ element = board; }
};
#endif