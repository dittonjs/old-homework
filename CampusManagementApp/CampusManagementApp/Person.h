#ifndef PERSON_H
#define PERSON_H

class Person 
{
public:
	Person();
	~Person();
	
	void setID(int a);
	void setName(char* a);
	void setDOB(int a);
	void setGender(int a);
	void setAddress(char* a);

	int getID();
	char* getName();
	int getDOB();
	int getGender();
	char* getAddress();
	virtual void read();
	virtual void write();

protected:
	int ID;
	char* name;
	int DOB; //mmddyy
	int gender; //0: boy 1: girl
	char* address;

};



#endif