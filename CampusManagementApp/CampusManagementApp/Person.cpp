#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(){
	ID = 0;
	name = "";
	DOB = 000000;
	gender = 0;
	address = "";
}

Person::~Person(){

}

int Person::getID(){
	return ID;
}

char* Person::getName(){
	return name;
}

int Person::getDOB(){
	return DOB;
}

int Person::getGender(){
	return gender;
}

char* Person::getAddress(){
	return address;
}

void Person::setID(int a){
	ID = a;
}

void Person::setName(char* a){
	name = a;
}

void Person::setDOB(int a){
	DOB = a;
}

void Person::setGender(int a){
	gender = a;
}

void Person::setAddress(char* a){
	address = a;
}

void Person::read(){
	int tempID;
	char tempName[256];
	int tempDOB;
	int tempGender;
	char tempAddress[256];

	cout << "ID: ";
	cin >> tempID;
	cout << "Name: ";
	cin.ignore();
	cin.getline(tempName, 256);
	cout << "Date of Birth: ";
	cin >> tempDOB;
	cout << "Gender(1:M or 2:F): ";
	cin >> tempGender;
	cin.ignore();
	cout << "Address: ";
	cin.getline(tempAddress, 256);

	this->setID(tempID);
	this->setName(tempName);
	this->setDOB(tempDOB);
	this->setGender(tempGender);
	this->setAddress(tempAddress);

}

void Person::write(){
	cout << "ID Number: " << this->getID() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "Date Of Birth:  " << this->getDOB() << endl;
	cout << "Gender(0: Boy, 1: Girl) " << this->getGender() << endl;
	cout << "Address " << this->getAddress() << endl;
	
}