#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(){
	courseID = "";
	name = "";
	numOfCredits = 0;
	grade = 0;
	semester = 0;
	year = 0;
}

Course::~Course(){
	// DO SOMETHING HERE
}

char* Course::getCourseID(){
	return courseID;
}

char* Course::getName(){
	return name;
}

int Course::getNumOfCredits(){
	return numOfCredits;
}

int Course::getGrade(){
	return grade;
}

int Course::getSemester(){
	return semester;
}

int Course::getYear(){
	return year;
}

void Course::setCourseID(char* a){
	courseID = a;
}

void Course::setName(char* a){
	strcpy_s(name, 30, a);
}

void Course::setNumOfCredits(int a){
	numOfCredits = a;
}

void Course::setGrade(int a){
	grade = a;
}

void Course::setSemester(int a){
	semester = a;
}

void Course::setYear(int a){
	year = a;
}

void Course::read(){
	
	int tempYear, tempCredits;
	char tempCourseID[256];
	char tempCourseName[256];
	int tempSemester;
	int tempGrade;

	cout << "Course ID: ";
	cin.getline(tempCourseID, 256);
	cout << "Course name: ";
	cin.getline(tempCourseName, 256);
	cout << "Semester: ";
	cin >> tempSemester;
	cout << "Year: ";
	cin >> tempYear;	
	cout << "Number of credits: ";
	cin >> tempCredits;
	cout << "Grade: ";
	cin >> tempGrade;
	
	cout << endl;

	this->setCourseID(tempCourseID);
	this->setName(tempCourseName);
	this->setSemester(tempSemester);
	this->setYear(tempYear);
	this->setNumOfCredits(tempCredits);
	this->setGrade(tempGrade);
}

void Course::write(){
	cout << "Course ID: " << this->getCourseID() << endl;
	cout << "Course Name: " << this->getName() << endl;
	cout << "Number of Credits: " << this->getNumOfCredits() << endl;
	cout << "Course Grade: " << this->getGrade() << endl;
	cout << "Course Semester: " << this->getSemester() << endl;
	cout << "Course Year: " << this->getYear() << endl;
}


