#include "Student.h"

using namespace std;

void Student::add_record()
{
	cout<<"Name : ";
	cin>>name;
	cout<<"Roll Number : ";
	cin>>rollNo;
	cout<<"Address : ";
	cin>>address;
	cout<<"Division : ";
	cin>>division;
}

void Student::display()
{
	cout<<"| "<<setw(30)<<name;
	cout<<" | "<<setw(13)<<rollNo;
	cout<<" | "<<setw(8)<<division;
	cout<<" | "<<setw(38)<<address<<" |";
}

bool Student::isThisName(char check[])
{
	if(!strcmp(name,check))
		return true;
	return false;
}

