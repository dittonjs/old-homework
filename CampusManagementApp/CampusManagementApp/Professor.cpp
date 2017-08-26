#include "Professor.h"
#include "Person.h"
#include "Course.h"
#include <iostream>

using namespace std;
Professor::Professor(){
	jobTitle = "";
	officeNumber = 0;
	salary = 0.0;
}

Professor::~Professor(){

}

char* Professor::getJobTitle(){
	return jobTitle;
}

int Professor::getOfficeNumber(){
	return officeNumber;
}

double Professor::getSalary(){
	return salary;
}

void Professor::setJobTitle(char* a){
	jobTitle = a;
}

void Professor::setOfficeNumber(int a){
	officeNumber = a;
}

void Professor::setSalary(double a){
	salary = a;
}


void Professor::read(){
	char tempJobTitle[256];
	int tempOffice;
	double tempSalary;

	Person::read();

	cout << "Job Title: ";
	cin.getline(tempJobTitle, 256);
	cout << "Office: ";
	cin >> tempOffice;
	cout << "Salary: ";
	cin >> tempSalary;
	cout << endl;
	this->setJobTitle(tempJobTitle);
	this->setOfficeNumber(tempOffice);
	this->setSalary(tempSalary);
}

void Professor::write(){
	Person::write();
	cout << "Job Title: " << this->getJobTitle() << endl;
	cout << "Office Number: " << this->getOfficeNumber() << endl;
	cout << "Salary: " << this->getSalary() << endl;
}