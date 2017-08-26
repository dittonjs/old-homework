#include "Calculator.h"
#include <iostream>

using namespace std;

Calculator::Calculator()
{
	total = 0;
}

Calculator::~Calculator()
{
	cout << "Have a great day!" << endl;
}
void Calculator::add(double num)
{
	total += num;
}

void Calculator::divide(double num)
{
	total = total / num;
}

void Calculator::subtract(double num)
{
	total = total - num;
}

void Calculator::multiply(double num)
{
	total *= num;
}

double Calculator::getTotal()
{
	return total;
}