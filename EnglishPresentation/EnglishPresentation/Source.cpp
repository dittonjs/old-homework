#include <iostream>

using namespace std;


void displayWelcome()
{
	cout << "Welcome!" << endl;
}

void displayPay()
{
	for (int i = 0; i < 110000; i += 200)
	{
		cout << i << endl;
	}

	cout << "Thats alot of money." << endl;
}

void displayFact()
{
	cout << "Less than 1/3 of Utah highschools even offer computer science courses." << endl;
}

void displayInvitation()
{
	cout << "I propose that all utah highshools require computer science classes for graduation." << endl;
}

int main()
{
	char a;
	displayWelcome();
	cin >> a;
	displayPay();
	cin >> a;
	displayFact();
	cin >> a;
	displayInvitation();
	cin >> a;
	cout << "Have a nice day!" << endl;
	return 0;
}