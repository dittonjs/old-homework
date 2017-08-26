#include "TUStack.h"
#include <iostream>
#include <string>

using namespace std;
int main(){
	int sizeA, sizeB;
	cout << "How many in your string stack?" << endl;
	cin >> sizeA;
	cout << "How many in your int stack?" << endl;
	cin >> sizeB;
	TUStack<string> stringStack(sizeA);
	TUStack<int> intStack(sizeB);

	cout << "====================================" << endl;
	cout << "PUSHING TO THE INT AND STRING STACKS" << endl;
	cout << "====================================" << endl << endl;
	int response = 9;
	int numToAdd;
	string message;
	int popedItem;
	string poppedString;
	while (response != 6){
		cout << "1: add to int stack" << endl;
		cout << "2: remove from int stack" << endl;
		cout << "3: add to string stack" << endl;
		cout << "4: pop from string stack" << endl;
		cout << "5: print info from both stacks" << endl;
		cout << "6: exit" << endl;
		cin >> response;
		switch (response)
		{
		case 1:
			cout << "what number would you like to push?" << endl;
			cin >> numToAdd;
			intStack.Push(numToAdd); \
				cout << "Done" << endl;
			break;
		case 2: 
			popedItem = intStack.Pop();
			cout << "You popped " << popedItem << " out of the stack." << endl;
			break;
		case 3: 
			cout << "Write a message to add to the string stack" << endl;
			cin.ignore();
			getline(cin, message);
			stringStack.Push(message);
			cout << "Done" << endl;
			break;
		case 4: 
			poppedString = stringStack.Pop();
			cout << "You popped \"" << poppedString << "\" out of the stack." << endl;
			break;
		case 5: 
			cout << "INT DATA: " << endl;
			intStack.PrintMyData();
			cout << endl;
			cout << "String Data: " << endl;
			stringStack.PrintMyData();
			break;
		default:
			break;
		}
		
		
	}
	cout << "THANKS FOR COMING!" << endl;



}