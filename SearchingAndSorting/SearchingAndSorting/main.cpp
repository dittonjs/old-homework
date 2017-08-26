/*============================
1: READ IN THE FILE
2: WITH EVERY INPUT CHECK AND SEE IF ITS IN THE ARRAY
3: IF INPUT IS NOT FOUND IN THE ARRAY THEN ADD IT, IF IT
   IS FOUND THEN RETURN THE INDEX THEN INCREMENT THE FREQUENCY AT THAT INDEX
4: SORT THE FREQUENCY ARRAY AND ADJUST THE TERM ARRAY BASED OFF OF ITS FREQUENCY
5: OUT THE ARRAYS TO THE FILE

==============================*/

#include <iostream>
#include <fstream>
#include "TermTable.h"
using namespace std;

int main()
{
	TermTable termTable;
	ifstream fin("input.txt");
	int term;
	int indexNumber;
	int zeroCount = 0;;
	

	cout << "*** PLEASE WAIT UNTIL FINISHED RUNNING ***" << endl;
	/*==================================
			READ IN THE FILE
	===================================*/
	while (fin >> term)
	{
		
		//------------------------------------
		// FIRST CHECK IF THE TERM IS 0, BECAUSE THE ARRAY IS INITIALIZED TO ALL 0
		// IT WILL INCREMENT THE AMMOUNT OF 0'S AT THE WRONG INDEX SO WE KEEP TRACK OF THEM SEPARATELY
		// IF IT IS 0 THEN INCREMENT THE 0 COUNT AND SKIP TO THE NEXT ITERATION OF THE LOOP
		//------------------------------------
		if (term == 0)
		{
			zeroCount++;
			continue;
		}

		//-------------------------------
		// SEE IF THE NON 0 TERM EXISTS ALREADY
		//-------------------------------
		indexNumber = termTable.BinarySearch(term, 10000);
		if (indexNumber == -1)
		{
			//---------------------------------
			// IF IT DOESN'T EXSIT THEN ADD IT TOO THE ARRAY THEN SORT IT
			//---------------------------------
			termTable.Insert(0, term, true);
			termTable.Sort(10000, false);
			
		}
		else
		{
			//------------------------------
			// IF IT ALREADY EXSISTS THEN INCREMENT THE VALUE AT THE INDEX
			//------------------------------
			termTable.Insert(indexNumber, 0, false);
		}
		
	}

	/*============================================
			NOW THE ARRAYS ARE FILLED
	=============================================*/
	
	//--------------------------------------------
	// NOW INCREMENT THE AMMOUNT OF 0'S
	//--------------------------------------------
	for (int i = 0; i < zeroCount; i++)
	{
		termTable.Insert(0, 0, false);
	}

	/* ============================================
			SORT THE ARRAY BASED ON FREQUENCY
	===============================================*/

	termTable.Sort(10000, true);
	
	/*==============================================
				 WRITE IT TO THE FILE
	===============================================*/
	ofstream fout("output.txt");
	for (int i = 0; i < 10000; i++)
	{
		fout << termTable.getTerm(i) << " " << termTable.getFreq(i) << endl;
	}

	
	fout.close();
	
	return 0;
}