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

int binarySearch(BNKIndex * ind, int start, int size, int key)
{
	int middle, first, last, index;
	first = start;
	last = size-1;
	middle = (first + last) / 2;
	while (ind[middle].accountNumber != key && first <= last)
	{
		if (ind[middle].accountNumber > key)               // If the number is > key, ..
		{                                                       // decrease position by one.
			//
			//cout << "NUMBER IS LESS" << endl;
			last = middle - 1;
		}
		else if (ind[middle].accountNumber < key)
		{                                                        // Else, increase position by one.
			//cout << "NUMBER IS MORE" << endl;
			first = middle + 1;
		}
		middle = (first + last) / 2;
	}
	
	if (first <= last)
	{
		return middle;
	}
	
	return -1;
}
int main()
{
	// GET ALL OF THE INFO FROM THE FILE
	fstream fin;
	//ofstream fout;
	fin.open("accounts.BNK", ios::binary | ios::in | ios::out);
	//fout.open("accounts.BNK", ios::binary | ios::out | ios::app);
	if (fin.fail())
	{
		cout << "FILE NOT FOUND" << endl;
		return 0;
	}
	int numOfLines = 0;

	// GET THE BANK FILE
	BNKHeader bnk;
	BNKIndex *index;
	fin.read((char *)&bnk, sizeof(bnk));
		//PRINT FOR DEBUG
	//cout << bnk.signature << " " << bnk.numOfAccounts << endl;
	// CHECK TO SEE IF MATCHES SIGNATURE
	if (bnk.signature[0] != 'B'){ cout << "SIGNATURE IS WRONG1"; return 0; }
	if (bnk.signature[1] != 'A'){ cout << "SIGNATURE IS WRONG2"; return 0; }
	if (bnk.signature[2] != 'N'){ cout << "SIGNATURE IS WRONG3"; return 0; }
	if (bnk.signature[3] != 'K'){ cout << "SIGNATURE IS WRONG4"; return 0; }
	index = new BNKIndex[bnk.numOfAccounts];
	// FILL UP THE INDEX ARRAY
	fin.clear();
	fin.seekg(sizeof(BNKHeader) + (bnk.numOfAccounts * sizeof(BNKAccount)));
	for (int i = 0; i < bnk.numOfAccounts; i++)
	{
		fin.read((char *)&index[i], sizeof(index[i]));
	}

	/*for (int i = 0; i < bnk.numOfAccounts; i++)
	{
		cout << index[i].accountNumber << endl;
	}*/
	int i = binarySearch(index, 0, bnk.numOfAccounts, 333);
	//cout << i << endl;
	fin.clear();
	char r = 'x';
	while (r != 'q')
	{
		cout << "'d':    Display an account" << endl;
		cout << "'a':    Deposit to account" << endl;
		cout << "'w': Withdraw from account" << endl;
		cout << "'q':                  Quit" << endl;
		cin >> r;
		int i = 0;
		BNKAccount j;
		int num;
		switch (r)
		{
		case 'd':
			cout << "FOR WHICH ACCOUNT?" << endl;
			
			cin >> num;
			i = binarySearch(index, 0, bnk.numOfAccounts, num);
			if (i == -1)
			{
				cout << "NO SUCH ACCOUNT" << endl;
				break;
			}
			fin.clear();
			fin.seekg(index[i].filePosition);
			fin.read((char *)&j, sizeof(j));
			cout << "NUMBER: " << j.number << endl;
			cout << "NAME: " << j.name << endl;
			cout << "BALANCE: " << j.balance << endl;

			break;
		case 'a':
			cout << "FOR WHICH ACCOUNT?" << endl;
			
			cin >> num;
			i = binarySearch(index, 0, bnk.numOfAccounts, num);
			if (i == -1)
			{
				cout << "NO SUCH ACCOUNT" << endl;
				break;
			}
			fin.clear();
			fin.seekg(index[i].filePosition);
			fin.read((char *)&j, sizeof(j));
			cout << "HOW MUCH TO DEPOSIT?" << endl;
			double deposit;
			cin >> deposit;
			if (deposit < 0)
			{
				cout << "Can't deposit negetive" << endl;
				break;
			}
			j.balance += deposit;
			fin.clear();
			fin.seekg(index[i].filePosition);
			fin.write((char*)&j, sizeof(j));
			cout << "BALANCE UPDATED" << endl;

			break;
		case 'w':
			cout << "FOR WHICH ACCOUNT?" << endl;

			cin >> num;
			i = binarySearch(index, 0, bnk.numOfAccounts, num);
			if (i == -1)
			{
				cout << "NO SUCH ACCOUNT" << endl;
				break;
			}
			fin.clear();
			fin.seekg(index[i].filePosition);
			fin.read((char *)&j, sizeof(j));
			cout << "HOW MUCH TO WITHDRAW?" << endl;
			double withdraw;
			cin >> withdraw;
			if (withdraw < 0)
			{
				cout << "Can't withdraw negetive" << endl;
				break;
			}
			j.balance -= withdraw;
			fin.clear();
			fin.seekg(index[i].filePosition);
			fin.write((char*)&j, sizeof(j));
			cout << "BALANCE UPDATED" << endl;
			break;
		case 'q':
			break;
		default:
			cout << "Invalid Entry" << endl;
			break;
		}
		
	}
	fin.close();
	return 0;
}