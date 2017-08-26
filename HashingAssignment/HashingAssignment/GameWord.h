#ifndef GAME_WORD_H
#define GAME_WORD_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class GameWord { // this is my pair class
public:
	string word;
	int count = 1;
	string toString();
	GameWord();
	GameWord(string newWord, int newCount = 1){
		word = newWord;
		count = newCount;
	}

};

string GameWord::toString(){
	stringstream ss;
	ss << "WORD: " << word << " OCCURRENCE: " << count;
	return ss.str();
}
#endif