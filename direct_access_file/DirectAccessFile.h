#ifndef DIRECTACCESSFILE_H_
#define DIRECTACCESSFILE_H_

#include<fstream>
#include<iostream>
#include<iomanip>

using namespace std;

struct Employee
{
	int id;
	char name[20];
	int mobile;
	int chain;
	void init()
	{
		id = -1;
		name[0] = '\0';
		mobile = -1;
		chain = -1;
	}
	void get()
	{
		cout << endl << "ID: ";
		cin >> id;
		cout << "Name: ";
		cin >> name;
		cout << "Mobile: ";
		cin >> mobile;
	}
};

class DirectAccessFile
{
	Employee emp;
	int size;
	fstream file;
public:
	DirectAccessFile(int);
	void display();
	void insert();
	int hash(int);
	bool search(int);
	void modify(int);
	void deleter(int);
	virtual ~DirectAccessFile();
};

#endif
