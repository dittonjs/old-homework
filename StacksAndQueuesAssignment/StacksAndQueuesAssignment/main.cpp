//
//  main.cpp
//  LinkedListHomework
//
//  Created by Joseph Ditton on 4/10/15.
//  Copyright (c) 2015 Joseph Ditton. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
#include "LinkedListNode.h"
#include "Queue.h"
#include "OrderedQueue.h"
#include <string>
using namespace std;

//template<class T>
int main() {
	Queue myQueue;
	int a;
	cout << "How many in your queue?" << endl;
	cin >> a;
	cout << endl;
	cout << "Enter the values for " << a << " integers to push to the queue:" << endl;
	for (int i = 0; i < a; i++){
		int b;
		cin >> b;
		myQueue.push(b);
	}
	cout << endl << "Now print the queue" << endl;
	for (int i = 0; i < a; i++){
		cout << "NODE AT " << i << ": " << myQueue.at(i)->myData << endl;
	}
	cout << endl;
	cout << "Now poping the queue..." << endl;
	for (int i = 0; i < a; i++){
		cout << "Popping " << myQueue.pop() << " out of the queue" << endl;
	}
	OrderedQueue myOrdered;
	cout << "How many items would you like to push into your ordered queue?" << endl;
	cin >> a;
	cout << "Please enter " << a << " numbers to enter into you ordered queue" << endl;
	
	for (int i = 0; i < a; i++){
		int b;
		cin >> b;
		myOrdered.push(b);
	}
	cout << endl << "Now printed ordered queue" << endl;
	for (int i = 0; i < a; i++){
		cout << "NODE AT " << i << ": " << myOrdered.at(i+1)->myData << endl;
	}

	cout << endl << "Now poping out of ordered Queue..." << endl;
	for (int i = 0; i < a; i++){
		cout << "Popping " << myOrdered.pop() << " out of the ordered queue" << endl;
	}
	system("pause");
	return 0;
}
