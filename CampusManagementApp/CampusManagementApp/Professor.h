#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Person.h"
#include "Course.h"

class Professor : public Person
{
public:
	Professor();
	~Professor();

	void setJobTitle(char* a);
	void setOfficeNumber(int a);
	void setSalary(double a);

	char* getJobTitle();
	int getOfficeNumber();
	double getSalary();
	void read();
	void write();
private:
	char* jobTitle;
	int officeNumber;
	double salary;
};



#endif