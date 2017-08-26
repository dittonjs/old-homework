#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Course.h"
#include <vector>

using namespace std;
class Student : public Person
{
public:
	Student();
	~Student();

	void setMajor(char* a);
	char* getMajor();
	void read();
	void write();
	double calcGPA();
	void printTranscript();
	void addCourse(Course * a);
	double getGPA(int a);
private:
	char* major;
	vector < Course* > courses;

};

#endif // !1
