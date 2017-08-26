#ifndef TUSTACK_H
#define TUSTACK_H
#include <iostream>
#include <string>

template <class T>
class TUStack
{
public:
	TUStack();
	TUStack(int nSize);
	//TUStack(const TUStack<T> &stack);
	void Push(T item);
	T Pop();
	int Size();
	int Position();
	void PrintMyData();
	T & operator[ ] (int index);
	~TUStack();

private:


	int maxSize;
	int currentPosition;
	T *stack;
	int CheckIfExsists(T newItem);


	class NegetiveInitialValueException{
	public: 
		NegetiveInitialValueException(){
			cout << "YOU CANNOT HAVE AN INTIAL VALUE OF A NEGETIVE NUMBER" << endl;
		}
	};

	class DuplicateItemException{
	public:
		T dubItem;
		int a;
		DuplicateItemException(T d, int found, int size){
			dubItem = d;
			a = found;
			cout << "Item " << d << " already exsits in stack at " << a << endl;
			cout << "Current Stack Size: " << size + 1 << endl;
		}
	};

	class FullStackException{
	public:
		T item;
		FullStackException(T i){
			item = i;
			cout << "Cannot insert " << item << " into stack because stack is full" << endl;
			cout << "Max Size:" << maxSize << endl;
			cout << "Current Size" << currentPosition << endl;
		}
	};
	
	class IllegalIndexException{
	public:
		int pos;
		IllegalIndexException(int index, int size){
			pos = index;
			cout << "Index at " << pos << " does not exsist" << endl;
			cout << "Max Size: " << size << endl;
			
		}
	};

	class EmptyPopException{
	public:
		EmptyPopException(){
			cout << "You cannot pop because the stack is empty" << endl;
		}
	};
	
	
};

template <class T>
TUStack<T>::TUStack(){
	maxSize = 1;
	currentPosition = -1;
	stack = new T[maxSize];
}

template <class T>
TUStack<T>::TUStack(int size){
	if (size < 0){
		throw NegetiveInitialValueException();
	}
	maxSize = size;
	currentPosition = -1;
	//cout << "Am I getting Called?" << endl;
	stack = new T[maxSize];
}

//template <class T>
//TUStack<T>::TUStack(const TUStack<T> &oldStack)
//{
//	maxSize = oldStack.maxSize;
//	stack = new T[maxSize];
//
//	for (int i = 0; i < maxSize; i++)
//	{
//		stack[i] = oldStack.cells[i];
//	}
//}

template <class T>
void TUStack<T>::Push(T item){
	//CHECK TO MAKE SURE WE HAVENT POPPED OUT THE ONLY ELEMENT
	currentPosition++;
	
	if(currentPosition+1 > maxSize){
		currentPosition--;
		throw IllegalIndexException(currentPosition, maxSize);
	}
	else if(CheckIfExsists(item) != -1){
		int a = CheckIfExsists(item);
		throw DuplicateItemException(item, a, currentPosition);
	}
	else{
		stack[currentPosition] = item;
	}
	//cout << "CURRENT POSITION: " << currentPosition << endl;
}

template <class T>
int TUStack<T>::CheckIfExsists(T item){
	for (int i = 0; i < currentPosition+1; i++){
		if (stack[i] == item) return i;
	}
	return -1;
}

template <class T>
void TUStack<T>::PrintMyData(){
	for (int i = 0; i < currentPosition + 1; i++){
		cout << "At index: " << i << ": " << stack[i] << endl;
	}
	cout << "Max Size: " << maxSize << endl;
	cout << "Current Size" << currentPosition + 1 << endl;
}

template <class T>
T TUStack<T>::Pop(){
	if (currentPosition < 0){
		cout << currentPosition << endl;
		throw EmptyPopException();
	}
	else{
		
		
		T toReturn = stack[currentPosition];
		stack[currentPosition] = NULL;
		currentPosition--;
		return toReturn;
	}
	
}

template <class T>
T & TUStack<T>::operator[ ] (int index)
{
	if (index < 0)
		throw IllegalIndexException(index, maxSize);  
	else if (index >= maxSize)
		throw IllegalIndexException(index, maxSize);  
	else return stack[index];
}

template <class T>
int TUStack<T>::Size(){
	return maxSize;
}

template <class T>
int TUStack<T>::Position(){
	//THIS ALSO HAPPENS TO BE THE NUMBER OF ELEMENTS IN THE ARRAY -1
	return currentPosition;
}

template <class T>
TUStack<T>::~TUStack(){
	if (maxSize > 0);
	delete[] stack;
}



#endif