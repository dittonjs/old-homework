#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include "RobotGame.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file;
	int r, c;
	if (argc != 2)
	{
		cout << "usage: %s filename" << argv[0]; // argv[0] contains the name of the executable file generated after compiling
	}

	else
	{
		file.open(argv[1]); // argv[1] contains the name of the file to be read.
	}

	char temp[30];  // assume that each line has at most 29 characters
	
	// get the map dimensions
	while (file.getline(temp, 30))
	{
		//cout << temp << endl;  // debugging purpose
		istringstream inputData(temp);
		string i;

		while (inputData >> i)
		{
			
			if (i == "MAP")
			{
				
				inputData >> i;
				r = atoi(i.c_str());
				inputData >> i;
				
				c = atoi(i.c_str());
				break;
			}
		}
		break;
	}
	// CREATE THE ROBOT
	RobotGame game(r, c);
	// GET THE MAP AND PLAY
	cout << "Loading Map" << endl;
	while (file.getline(temp, 30)&& !game.GetGameOver())
	{
		// THIS WORKS!!!!
		for (int i = 0; i < strlen(temp); i++)
		{
			temp[i] = toupper(temp[i]);
		}
		istringstream inputData(temp);
		
		game.Play(inputData);
		char a;
		cout << endl << "PRESS ENTER TO GET NEXT LINE" << endl;
		cin.get(a);
		
	}

	file.close();
	cout << "GOODBYE" << endl;
	return 0;
	
	// READ FROM FILE INTO CONSTUCTOR AND FILL UP THE ARRAY
	// PRINT OUT THE ARRAY EVERY TURN WITH THE UDATES FROM FILE

}