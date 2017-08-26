
#ifndef WORD_H
#define WORD_H

class Word
{
public:
	Word();
	
	Word(char a[10], int type, int sub);
	char * getWord();
	int getPartOfSpeech();
	int getSubset();
private:
	char word[10];		
	int partOfSpeech;
	int subSet;
};


#endif