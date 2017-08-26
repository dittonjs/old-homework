#include "Course.h"
#include "Person.h"
#include "Professor.h"
#include "Student.h"
#include <iostream>
#include <vector>

using namespace std;

Professor* addProfessor(){
	return new Professor();
}



int main(){

	vector<Person *> people;
	int input = 0;
	Professor* tempP;
	Student* tempS;
	Course* tempC;
	int tempID;
	while (input != 6)
	{
		cout << "SELECT YOUR CHOICE" << endl;
		cout << "1: Add Professor" << endl;
		cout << "2: Add Student" << endl;
		cout << "3: Add a Course for a student" << endl;
		cout << "4: Print Transcript for student" << endl;
		cout << "5: Print Professor Information" << endl;
		cout << "6: Quit" << endl;
		cin >> input;
		
		switch (input)
		{
		case 1:
			tempP = new Professor();
			tempP->read();
			people.push_back(tempP);
			break;
		case 2:
			tempS = new Student();
			tempS->read();
			people.push_back(tempS);
			break;
		case 3:
			cout << "For What ID?" << endl;
			cin >> tempID;
			for (int i = 0; i < people.size(); i++){
				if (people[i]->getID() == tempID){
					Course* c = new Course();
					c->read();
					Student* a = (Student*)people[i];
					a->addCourse(c);

				}
			}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
		
	}


	return 0;
}