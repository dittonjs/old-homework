#include <iostream>
#include "Calculator.h"

using namespace std;

int main()
{
	Calculator calc;
	char selection = 'x';
	double number = 0;
	while (selection != 'Q' && selection != 'q')
	{
		cout << endl << endl;
		cout << "*** CALCULATOR ***" << endl;
		cout << "A: Add Value" << endl;
		cout << "S: Subtract Value" << endl;
		cout << "M: Multiply Value" << endl;
		cout << "D: Divide Value" << endl;
		cout << "T: Get the Total" << endl;
		cout << "Q: Quit" << endl;
		
		cout << "CURRENT TOTAL: " << calc.getTotal() << endl;
		cout << "SELECTION: ";
		cin >> selection;
		switch (selection)
		{
		case 'a':
		case 'A':
			cout << "*** ADD VALUE ***" << endl;
			cout << "ENTER NUMBER ";
			cin >> number;
			cout << calc.getTotal() << " + " << number << " = ";
			calc.add(number);
			cout << calc.getTotal() << endl;
			cout << "******" << endl;
			break;
		case 's':
		case 'S':
			cout << "*** SUBTRACT VALUE ***" << endl;
			cout << "ENTER NUMBER ";
			cin >> number;
			cout << calc.getTotal() << " - " << number << " = ";
			calc.subtract(number);
			cout << calc.getTotal() << endl;
			cout << "******" << endl;
			break;
		case 'm':
		case 'M':
			cout << "*** MULTIPLY VALUE ***" << endl;
			cout << "ENTER NUMBER ";
			cin >> number;
			cout << calc.getTotal() << " * " << number << " = ";
			calc.multiply(number);
			cout << calc.getTotal() << endl;
			cout << "******" << endl;
			break;
		case 'd':
		case 'D':
			cout << "*** DEVIDE VALUE ***" << endl;
			cout << "ENTER NUMBER ";
			cin >> number;
			cout << calc.getTotal() << " / " << number << " = ";
			calc.divide(number);
			cout << calc.getTotal() << endl;
			cout << "******" << endl;
			break;
		case 't':
		case 'T':
			cout << "TOTAL: " << calc.getTotal() << endl;
			cout << "******" << endl;
			break;
		case 'q':
		case 'Q':
			cout << "THANKS FOR COMING" << endl;
			break;
		
		default:
			cout << "INVALID SELECTION" << endl;
			break;
		}

	}

}