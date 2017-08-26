
#include <Windows.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
	int main(void){
		
		string myStr = "Hello world";
		
		istringstream istr1(myStr);
		ostringstream ostr;
		string first;
		string second;
		istr1 >> first >> second;

		ostr << first << " " << second << endl;
		cout << ostr.str() << endl;
		return 0;
		
	}