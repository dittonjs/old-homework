#include "TermTable.h"

using namespace std;


// INITIALIZE ALL ELEMEMTS TO 0
TermTable::TermTable()
{
	for (int i = 0; i < 10000; i++)
	{
		termArray[i] = 0;
		frequencyArray[i] = 0;
	}

	numOfTerms = 0;
}

	// BINARY SORT METHOD
int TermTable::BinarySearch(int searchNum, int size)
{
	int first, last, middle, location;
	bool found = false;
	first = 0; last = size - 1;  location = -1;
	middle = (first + last) / 2;
	while (last >= first && !found)
	{
		
		if (termArray[middle] == searchNum)
		{
			location = middle;
			found = true;
		}
		else if (termArray[middle] > searchNum)
		{
			last = middle - 1;
		}
		else if (termArray[middle] < searchNum)
		{
			first = middle + 1;
		}
		middle = (first + last) / 2;

	}
	return location;
}

	//---------------------------------------------
	// THIS FUNCTION DOES 2 THINGS
	// IF NEEDTOINSERT IS TRUE THEN IT WILL ADD THE VALUE PROVIDED
	// TO THE THE ARRAY AT THE PRIVIDED INDEX AND INCREMENT THE NUMBER OF THAT TERM 
	// FOUND IN THE ARRAY.
	// IF NEEDTOINSERT IS FALSE THEN IT WILL JUST INCREMENT THE FREQUENCY AT THE GIVE INDEX
	//---------------------------------------------

void TermTable::Insert(int index, int value, bool needToInsert)
{
	if (needToInsert){
		termArray[index] = value;
		numOfTerms++;
	}
	frequencyArray[index] += 1;
	
}

int TermTable::getTerm(int index)
{
	return termArray[index];
}

int TermTable::getFreq(int index)
{
	return frequencyArray[index];
}

/*=========================================
	THE SORT FUNCTION DOES TWO THINGS:
	1: IT DUALS SORTS BOTH OF THE ARRAYS BASED OFF THE ORDED OF THE TERM ARRAY
		OR THE ORDER OF THE FREQUENCY ARRAY
	2: IT ENSURES THAT THE INDEX OF THE TERM ARRAY AND THE CORRESPONDING FREQUENCY ARRAY
		ARE ALWAYS THE SAME. AS LONG AS YOU DO THE SAME THING TO EACH ARRAY EVERY TIME YOU MOVE SOMETHING
		THEN THE ARRAYS SHOULD ALWAYS LINE UP
	- THIS FUNCTION WILL BE RUN EVERYTIME A NEW ELEMENT IS INSERTED TO SORT THE TERMS FROM SMALLEST TO GREATEST
	- THEN ONCE ALL THE TERMS HAVE BEEN ENTERED IT WILL SORT BOTH THE ARRAYS BY THE FREQUENCY OF EACH TERM FROM GREATEST TO LEAST

===========================================*/

void TermTable::Sort(int size, bool isDone)
{
	int a = 0;
	bool swapped = true;
	
	if (isDone)
	{
		while (swapped){
			swapped = false;
			for (int i = 0; i < (size -1) ; i++)
			{
				if (frequencyArray[i]<frequencyArray[i + 1])
				{
					a = frequencyArray[i + 1];
					frequencyArray[i + 1] = frequencyArray[i];
					frequencyArray[i] = a;
					a = termArray[i + 1];
					termArray[i + 1] = termArray[i];
					termArray[i] = a;
					swapped = true;
				}
				
			
			}
			//size--;
		}
	}
	else 
	{
		while (swapped)
		{
			swapped = false;
			for (int i = 0; i < (size - 1); i++)
			{
				
				if (termArray[i]>termArray[i + 1])
				{
					a = frequencyArray[i + 1];
					frequencyArray[i + 1] = frequencyArray[i];
					frequencyArray[i] = a;
					a = termArray[i + 1];
					termArray[i + 1] = termArray[i];
					termArray[i] = a;
					swapped = true;
				}
				
				
			}
			//size--;
		}
	}
}

int TermTable::GetNumOfTerms()
{
	return numOfTerms;
}

TermTable::~TermTable() 
{

}