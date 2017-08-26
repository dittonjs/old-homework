#ifndef TERM_TABLE_H
#define TERM_TABLE_H

class TermTable
{
public:
	TermTable();
	~TermTable();

	int BinarySearch(int searchNum, int size);
	void Insert(int index, int value, bool needToInsert);
	void Sort(int size, bool isDone);
	int GetNumOfTerms();
	int getTerm(int index);
	int getFreq(int index);
private:

	int termArray[10000];
	int frequencyArray[10000];
	int numOfTerms;
};


#endif 
