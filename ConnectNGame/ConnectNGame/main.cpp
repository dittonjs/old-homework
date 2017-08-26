#include "ConnectNGame.h"
#include <iostream>

using namespace std;


int main()
{
	int num;
	cout << "How many pieces needed to win?";
	cin >> num;
	ConnectNGame connectN(num);
	connectN.Play();
	
}