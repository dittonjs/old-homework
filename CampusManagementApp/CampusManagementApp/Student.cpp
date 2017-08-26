#include "Person.h"
#include "Course.h"
#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){
	major = "";
}

Student::~Student(){

}

char* Student::getMajor(){
	return major;
}

void Student::setMajor(char* a){
	major = a;
}

void Student::read(){
	Person::read();
	char tempMajor[256];
	cout << "Major : ";
	cin.getline(tempMajor, 256);
	cout << endl;
	this->setMajor(tempMajor);
}

void Student::write(){
	Person::write();
	cout << "Major: " << this->getMajor() << endl;
	
}

void Student::addCourse(Course * a){
	courses.push_back(a);
}

double Student::calcGPA(){
	double total = 0;
	for (int i = 0; i < courses.size(); i++)
		total += getGPA(courses[i]->getGrade());
	return total / courses.size();
}

void Student::printTranscript(){
	write();
	cout << endl;
	cout << "COURSES" << endl;
	for (int i = 0; i < courses.size(); i++)
		cout << courses[i]->getName() << endl;
	cout << "GPA: " << calcGPA() << endl;
}

double Student::getGPA(int a){
	switch (a){
	case 10:
		return 4.0;
		break;
	case 9:
		return 3.67;
		break;
	case 8:
		return 3.33;
		break;
	case 7:
		return 3.0;
		break;
	case 6:
		return 2.67;
		break;
	case 5:
		return 2.33;
		break;
	case 4:
		return 2.0;
		break;
	case 3:
		return 1.67;
		break;
	case 2:
		return 1.33;
		break;
	case 1:
		return 1.0;
		break;
	case 0:
		return 0.0;
		break;
	default: 
		return 0;
		break;
	}
}