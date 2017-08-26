#include <iostream>
#include "Hashtable.h"
#include "string"
#include "GameWord.h" // this is my pair class
#include "fstream"
using namespace std;
int TABLE_SIZE = 977; // use this to change table size
int OUTPUT_FREQUENCE = 10; // change how often you want score data to print out.
int TO_STRING_AMOUNT = 50; // change how many table entries you want to see.
string GAME_NAME = "game4.txt";

int getBonus(int count){
	if (count < 1) return 5;
	if (count < 6) return 4;
	if (count < 11) return 3;
	if (count < 16) return 2;
	return 1;
};

int getLengthScore(string word){
	int length = word.length();
	if (length < 3) return 0;
	if (length >= 8) return 6;
	return length - 2;
};

int getLetterScore(char letter){
	switch (toupper(letter))
	{
	case 'G':
	case 'D':
		return 2;
	case 'M':
	case 'B':
	case 'C':
	case 'P':
		return 3;
	case 'F':
	case 'W':
	case 'H':
	case 'Y':
	case 'V':
		return 4;
	case 'K':
		return 5;
	case 'X':
	case 'J':
		return 8;
	case 'Q':
	case 'Z':
		return 10;
	default:
		return 1;
		break;
	}
}


int getWordScore(string word){
	int score = 0;
	for (int i = 0; i < word.length(); i++)
	{
		score += getLetterScore(word[i]);
	}
	return score;
};

int calculateScore(GameWord* gameWord){
	int score = 0;
	score = score + (getWordScore(gameWord->word) * getBonus(gameWord->count - 1) * getLengthScore(gameWord->word));
	
	
	return score;
};


int main(){

	ifstream myfile;
	myfile.open(GAME_NAME);
	HashTable<string, GameWord> table(TABLE_SIZE);
	string word;

	// insert all of the words into the hash
	int index = 0;
	int score = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, word))
		{
			GameWord * gameWord = table.find(word);
			if (gameWord != NULL){
				gameWord->count++;
				score += calculateScore(gameWord);
			}
			else {
				gameWord = new GameWord(word);
				score += calculateScore(gameWord);
				table.insert(word, new GameWord(word));
			}
			if (index % OUTPUT_FREQUENCE == 0){
				cout << "SCORE AT INSERT NUMBER: " << index << " = " << score << endl;
				cout << "FIND COUNT SO FAR: " << table.findCount << endl;
				cout << "PROBES SO FAR: " << table.probeCount << endl;
				cout << "SIZE SO FAR: " << table.size << endl;
			}
			index++;
		}
	}
	
	cout << table.toString(TO_STRING_AMOUNT) << endl;
	cout << "THIS GAMES SCORE: " << score << endl;
	cout << "TOTAL FIND COUNT: " << table.findCount << endl;
	cout << "TOTAL PROBE COUNT: " << table.probeCount << endl;
	cout << "TOTAL SIZE: " << table.size << endl;
	myfile.close();

	return 0;
}

