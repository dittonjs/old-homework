#include <iostream>
#include "Word.h"
#include <ctime>
using namespace std;

const int LENGTH = 200;


void writeStory(int wordLength, Word vocab[100])
{
	srand(time(0));
	int lastPartOfSpeach = 0;
	int lastSub = 0;
	Word myNouns[100];
	Word myVerbs[100];
	Word myDescript[100];
	int randomWordNum;
	int randomSubNum;
	int counter = 0;
	int wordCount = 0;
	while (wordCount < wordLength){
		switch (lastPartOfSpeach)
		{
		case 0: // START OF SENTANCE
			for (int j = 0; j < 100; j++)
			{
				if (vocab[j].getPartOfSpeech() == 1)
				{
					myNouns[counter] = vocab[j];
					counter++;
				}
				
			}

			if(counter!=0) randomWordNum = rand() % counter;
			if (counter == 0) randomWordNum = 0;
			cout << myNouns[randomWordNum].getWord() << " ";
			counter = 0;
			lastPartOfSpeach = 1;
			lastSub = 1;
			wordCount++;
			break;
		case 1: // NOUN 
			// CHOOSE WHAT TYPE OF VERB
			randomSubNum = (rand() % 4) + 1;
			// find all the verbs that meet that demand
			for (int j = 0; j < 100; j++)
			{
				if (vocab[j].getPartOfSpeech() == 2 && vocab[j].getSubset() == randomSubNum)
				{
					myVerbs[counter] = vocab[j];
					counter++;
				}
			}

			if(counter!=0)randomWordNum = rand()%counter;
			if (counter == 0) randomWordNum = 0;
			cout << myVerbs[randomWordNum].getWord() << " ";
			counter = 0; 
			lastPartOfSpeach = 2;
			lastSub = randomSubNum;
			wordCount++;
			break;

		case 2:
			switch (lastSub)
			{
			case 1: 
				cout << "the ";
				wordCount++;
				for (int j = 0; j < 100; j++)
				{
					if (vocab[j].getPartOfSpeech() == 1 && vocab[j].getSubset() == 3)
					{
						myNouns[counter] = vocab[j];
						counter++;
					}
				}

				if(counter != 0)randomWordNum = rand() % counter;
				if (counter == 0) randomWordNum = 0;
				cout << myNouns[randomWordNum].getWord() << ". ";
				randomWordNum = 0;
				counter = 0;
				lastPartOfSpeach = 0;
				wordCount++;
				break;

			case 4: 
				for (int j = 0; j < 100; j++)
				{
					if (vocab[j].getPartOfSpeech() == 3)
					{
						myDescript[counter] = vocab[j];
					}
				}

				if(counter!=0)randomWordNum = rand() % counter;
				if (counter == 0) randomSubNum = 0;
				cout << myDescript[randomWordNum].getWord() << ". ";
				counter = 0;
				lastPartOfSpeach = 0;
				wordCount++;
				break;
			case 2: 
				cout << "nothing. ";
				counter = 0;
				lastPartOfSpeach = 0;
				wordCount++;
			default:
				cout << "well. ";
				counter = 0;
				lastPartOfSpeach = 0;
				wordCount++;
				break;
			}

		default:
			break;
		}
	}
}

int main()
{
	//WORD TYPES
	//1 = NOUNS
		//1 = PERSON
		//2 = PRONOUN
		//3 = PLACE
		//4 = THING
	//2 = VERBS
		//1 TRAVEL 
		//2 INTERACTION
		//3 ACTION
		//4 STATE
	//3 = DESCRIPTIVE
		//1 = GOOD
		//2 = BAD
	//4 THE 
	Word catelyn("Catelyn", 1, 1);
	Word was("was", 2, 4);
	Word went("went to", 2, 1);
	Word did("did", 2, 3);
	Word she("she", 1, 2);
	Word it("it", 1, 2);
	Word the("the", 4, 4);
	Word store("store", 1, 3);
	Word quickly("quickly", 3, 1);
	Word slowly("slowly", 3, 2);
	Word good("good", 3, 1);
	Word sexy("sexy", 3, 1);
	Word beautiful("beautiful", 3, 1);
	Word amazing("amazing", 3, 1);
	Word vocab[100] = { catelyn, was, went, did, she, it, the, store, quickly, slowly, amazing, beautiful, good, sexy };

	writeStory(LENGTH, vocab);

	return 0;

}