#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
public:
	Calculator();
	~Calculator();
	void add(double value);
	void subtract(double value);
	void multiply(double value);
	void divide(double value);
	double getTotal();


private:
	double total;
};


#endif