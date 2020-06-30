#ifndef STUDENT_H_
#define STUDENT_H_

#include<fstream>
#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

class Student
{
		char name[30];
		int rollNo;
		char address[50];
		int division;
	public:
		void add_record();
		void create_database();
		void display();
		bool isThisName(char []);
}; //Base class

#endif
