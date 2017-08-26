#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;



struct BNKHeader 
{
	char signature[4];
	int numOfAccounts;
	char reserved[24];
};

struct BNKAccount
{
	int number;
	char name[20];
	double balance;
	char reserved[96];

};

struct BNKIndex 
{
	int accountNumber;
	long filePosition;
};

void bubbleSort(BNKIndex * ind, int size)
{
	bool sorted = false;
	bool swapped = false;
	while (!sorted)
	{
		swapped = false;
		for (int i = 0; i < size; i++)
		{
			
			if (i != size-1){
				if (ind[i].accountNumber > ind[i + 1].accountNumber)
				{
					BNKIndex a = ind[i];
					ind[i] = ind[i + 1];
					ind[i + 1] = a;
					//cout << "            " << ind[i].accountNumber << " " << ind[i].filePosition << endl; // THIS IS FOR DEBUGGING
					swapped = true;
				}
			}
		}
		if (!swapped)
			sorted = true;
		
	}
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("accounts.CSV");
	fout.open("accounts.BNK", ios::binary | ios::out);
	int numOfLines = 0;
	BNKHeader bHead;
	BNKIndex * index;
	if (fin.fail())
	{
		cout << "FILE NOT FOUND" << endl;
	}

	char c[32];

	while (fin.getline(c, 32))
	{
		numOfLines++;
	}

	
	cout << numOfLines << endl;
	fin.close();
	fin.open("accounts.CSV");
	bHead.numOfAccounts = numOfLines - 1;
	index = new BNKIndex[numOfLines - 1];
	bHead.signature[0] = 'B';
	bHead.signature[1] = 'A';
	bHead.signature[2] = 'N';
	bHead.signature[3] = 'K';
	fout.write((char*)&bHead, sizeof(bHead));
	fin.getline(c, 32);

	for (int i = 0; i < (numOfLines - 1); i++)
	{
		char num[10];
		char bal[30];
		BNKAccount b;
		fin.getline(num, 10, ',');
		//cout << num << endl;
		b.number = atoi(num);
		fin.getline(b.name, 32, ',');
		fin.getline(bal, 30);
		b.balance = atof(bal);
		//FOR DEBUGGING
		//cout << b.number << " " << b.name << " " << b.balance << endl;
		index[i].accountNumber = b.number;
		index[i].filePosition = fout.tellp();
		fout.write((char *)&b, sizeof(b));
		
		//cout << index[i].accountNumber << " " << index[i].filePosition << endl;
	}
	cout << "----------------------" << endl;
	bubbleSort(index, (numOfLines - 1));
	for (int i = 0; i < numOfLines-1; i++)
	{
		fout.write((char *)&index[i], sizeof(index[i]));
		//cout << index[i].accountNumber << " " << index[i].filePosition << endl; // THIS IS FOR DEBUGGING

	}
	fin.close();
	fout.close();
	
	//THIS IS ALL FOR DEBUGGING
	//fin.open("accounts.BNK", ios::binary | ios::in);
	//BNKHeader head;
	//BNKAccount one;
	//BNKAccount two;
	//BNKAccount three;
	//BNKIndex ind;
	//fin.clear();
	//fin.read((char*)&head, sizeof(head));
	//fin.read((char*)&one, sizeof(one));
	//fin.read((char*)&two, sizeof(two));
	//fin.read((char*)&three, sizeof(three));
	//fin.read((char*)&ind, sizeof(ind));

	//
	//// COMMENT THIS OUT IF YOU DONT WANT TO OUTPUT TO SCREEN
	//cout << "THIS IS WHAT I READ FROM THE BINARY FILE AFTER WRITING IT" << endl;
	//cout << "BALANCE    NAME    ACCOUNT NUMBER" << endl;
	//cout << one.balance << " " << one.name << " " << one.number << endl;
	//cout << two.balance << " " << two.name << " " << two.number << endl;
	//cout << three.balance << " " << three.name << " " << three.number << endl;
	////cout << ind.accountNumber << " " << ind.filePosition << endl;
	//
	//fin.close();
	return 0;

}

