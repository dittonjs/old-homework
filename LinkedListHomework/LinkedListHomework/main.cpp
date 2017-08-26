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
#include <string>
using namespace std;

//template<class T>
int main() {
	cout << "CREATING LIST NOW" << endl;
	//LinkedList<string> oLink(); // THIS IS THE STRING LINKED LIST
	LinkedList iLink;// THIS IS THE INT
	
	cout << "Linked Lists Created" << endl << endl;
	

	cout << "Please Enter 5 ints to store in the int linked list" << endl;
	for (int i = 0; i < 5; i++){
		int a;
		cin >> a;
		a = iLink.insert(a);
	}
	cout << endl;

	cout << "Now displaying all values" << endl;
	for (int i = 0; i <= 5; i++)
	{
		//cout << "String " << i << " " << oLink.at(i) << endl;
		if(iLink.at(i)->myData != -9999)cout << "Int " << i << " ==== " << iLink.at(i)->myData << endl;
		//cout << "Double " << i << " ==== " << iLink.at(i)->myData << endl;
	}
	cout << endl;
	cout << "Now Showing first elements of all" << endl;
	//cout << "String " <<  " " << sLink.begin()->head << endl;
	cout << "Int " << " " << iLink.begin()->myData << endl;
	//cout << "Double " << " " << iLink.begin()->myData << endl;
	cout << endl << endl;
	cout << "Enter a number to search for" << endl;
	int a;
	cin >> a;
	a = iLink.Find(a);
	if (a != -1)cout << "That number found at index " << a << endl;
	else cout << "That number is not found in the array" << endl;
	cout << endl;
	cout << "Now removing the 2nd index" << endl;
	//cout << sLink.removeAt(2);
	cout << iLink.removeAt(1);
	
	
	cout << "Now displaying all values" << endl;
	for (int i = 0; i <=4; i++)
	{
		//cout << "String " << i << " " << sLink.at(i) << endl;
		if (iLink.at(i)->myData != -9999)cout << "Int " << i << " ==== " << iLink.at(i)->myData << endl;
		
	}
	cout << endl;
	cout << "Now Clearing all values" << endl;
	//sLink.clear();
	iLink.clear();

	
	cout << "Now displaying all values(You shouldnt see anything)" << endl;
	for (int i = 0; i <= 5; i++)
	{
		//cout << "String " << i << " " << sLink.at(i) << endl;
		if (iLink.at(i)->myData != -9999)cout << "Int " << i << " " << iLink.at(i)->myData << endl;
		
	}

	
	cout << "GoodBye" << endl;

	return 0;
}
