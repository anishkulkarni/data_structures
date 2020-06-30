#include <iostream>
#include<iomanip>

#include"HashTable.h"
#include"HashTable.cpp"

using namespace std;

struct Student
{
	int rollNumber;
	char name[20];
	long int mobileNumber;
	void display()
	{
		cout<<" | "<<setw(11)<<rollNumber<<" | "<<setw(12)<<name<<" | "<<setw(13)<<mobileNumber<<" |";
	}
	void init()
	{
		rollNumber=-1;
		name[0]='\0';
		mobileNumber=-1;
	}
	void input()
	{
		cout<<endl<<"Enter detail of student";
		cout<<endl<<"Roll number: ";
		cin>>rollNumber;
		cout<<"Name: ";
		cin>>name;
		cout<<"Mobile Number: ";
		cin>>mobileNumber;
	}
};

int main()
{
	HashTable<Student> hashTable(10);
	int choice;
	bool insertReplacementFlag=false;
	cout<<"Chose collision handling mechanism:\n1. Linear probing without replacement\n2. Linear Probing without replacement\nChoice: ";
	cin>>choice;
	switch(choice)
	{
	case 1:
		insertReplacementFlag=false;
		break;
	case 2:
		insertReplacementFlag=true;
		break;
	}
	while (1)
	{
		cout << "Menu\n1. Display\n2. Insert\n3. Search\n4. Delete\n5. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			hashTable.display();
			cout << endl << endl;
			break;
		case 2:
		{
			Student student;
			student.input();
			switch(insertReplacementFlag)
			{
			case false:
				hashTable.insertWithoutReplacement(student);
				break;
			case true:
				hashTable.insertWithReplacement(student);
				break;
			}
			cout << endl << endl;
			break;
		}
		case 3:
		{
			Student student;
			student.input();
			hashTable.search(student);
			cout << endl << endl;
			break;
		}
		case 4:
			Student student;
			student.input();
			hashTable._delete(student);
			cout << endl << endl;
			break;
		case 5:
			return 0;
			break;
		}
	}
}
