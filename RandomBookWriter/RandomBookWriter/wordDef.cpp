#include "Word.h"


Word::Word()
{
	word[0] = 'a';
	subSet = 0;
	partOfSpeech = 0;

}
Word::Word(char name[10], int partOf, int sub)
{
	for (int i = 0; i < 10; i++)
	{
		word[i] = name[i];
	}

	partOfSpeech = partOf;
	subSet = sub;
}

int Word::getPartOfSpeech()
{
	return partOfSpeech;
}

char * Word::getWord()
{
	return word;
}

int Word::getSubset()
{
	return subSet;
}