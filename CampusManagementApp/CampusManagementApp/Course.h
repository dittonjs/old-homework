#ifndef COURSE_H
#define COURSE_H

class Course
{
public:
	Course();
	~Course();
	void setCourseID(char* a);
	void setName(char* a);
	void setNumOfCredits(int a);
	void setGrade(int a);
	void setSemester(int a);
	void setYear(int a);
	char* getCourseID();
	char* getName();
	int getNumOfCredits();
	int getGrade();
	int getSemester();
	int getYear();
	void read();
	void write();
private:
	char* courseID;
	char* name;
	int numOfCredits;
	int grade;
	int semester; // 0: fall 1: spring 2: summer
	int year;

	
};

#endif