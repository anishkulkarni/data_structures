#include<iostream>
#include"Student.h"
#include<fstream>
#include<cstring>
#include<iomanip> //header file inclusion

using namespace std; //namespace declaration

void printMenu() //Function to print menu
{
	cout<<"Menu\n1. Create database\n2. Add record\n3. Display database\n4. Delete record\n5. Modify record\n6. Search record\n7. Exit\nChoice : ";
}

void display_line();

void display_header();

int main() //Main function
{
	ofstream outfile;
	ifstream infile;
	Student data;
	int choice,size,flag=0;
	char name[50];
	do
	{
		printMenu();
		cin>>choice;
		switch(choice)
		{
			case 1: //create database
				outfile.open("database",ios::out|ios::app|ios::binary);
				cout<<endl<<"Database successfully created";
				outfile.close();
				cout<<endl<<endl;
				break;
			case 2: //add record
				outfile.open("database",ios::out|ios::app|ios::binary);
				cout<<"\nEnter the details of the record to be added : \n";
				data.add_record();
				outfile.write((char *)&data,sizeof(data));
				cout<<endl<<"Record successfully added"<<endl<<endl;
				outfile.flush();
				outfile.close();
				break;
			case 3: //display database
				infile.open("database",ios::in|ios::binary);
				flag=0;
				cout<<endl;
				while(infile.read((char *)&data,sizeof(data)))
				{
					if(flag==0)
					{
						display_line();
						cout<<endl;
						display_header();
						cout<<endl;
						display_line();
						cout<<endl;
					}
					flag++;
					data.display();
					cout<<endl;
					display_line();
					cout<<endl;
				}
				if(flag==0)
					cout<<"No records found";
				cout<<endl<<endl;
				infile.close();
				break;
			case 4: //delete record
			        cout<<"\nEnter the name to record to be deleted : ";
			        cin>>name;
			        infile.open("database");
			        outfile.open("temp");
			        flag=0;
			        while(infile.read((char *)&data,sizeof(data))!=NULL)
			        {
			                if(!data.isThisName(name))
			                {
			                        outfile.write((char *)&data,sizeof(data));
			                }
			                else
			                {
			                	flag=1;
			                	cout<<endl<<"Deleting following record : "<<endl<<endl;
						display_line();
						cout<<endl;
						display_header();
						cout<<endl;
						display_line();
						cout<<endl;
			         		data.display();
			         		cout<<endl;
			         		display_line();
			         		cout<<endl;
			                }
			        }
			        if(flag==0)
			       		cout<<endl<<"Record not found";
			       	else
			       		cout<<endl<<"Record successfully deleted";
                                infile.close();
                                outfile.close();
                                remove("database");
                                rename("temp","database");
                                cout<<endl<<endl;
                                break;
			case 5: // Modify record
			        cout<<"\nEnter the name to record to be modified : ";
			        cin>>name;
			        infile.open("database");
			        outfile.open("temp");
			        while(infile.read((char *)&data,sizeof(data))!=NULL)
			        {
			                if(!data.isThisName(name))
			                {
			                        outfile.write((char *)&data,sizeof(data));
			                }
			                else
			                {
			                	flag=1;
			                	cout<<endl<<"Following record found : "<<endl<<endl;
						display_line();
						cout<<endl;
						display_header();
						cout<<endl;
						display_line();
						cout<<endl;
			         		data.display();
			         		cout<<endl;
			         		display_line();
			         		cout<<endl;
			                	cout<<endl<<"Enter the new details of the record : "<<endl<<endl;
			                	data.add_record();
			                	outfile.write((char *)&data,sizeof(data));
			                	cout<<endl<<"Record successfuly modified";
			                	cout<<endl<<endl<<"Following is the modiied record : "<<endl<<endl;
						display_line();
						cout<<endl;
						display_header();
						cout<<endl;
						display_line();
						cout<<endl;
			         		data.display();
			         		cout<<endl;
			         		display_line();
			         		cout<<endl;
			                }
			        }
			        if(flag==0)
			        	cout<<endl<<"Record not found";
			        infile.close();
			        outfile.close();
			        remove("database");
			        rename("temp","database");
			        cout<<endl<<endl;
			        break;
			case 6: //Search record
				cout<<"\nEnter the name to record to search for: ";
				cin>>name;
				infile.open("database");
				flag=0;
				while(infile.read((char *)&data,sizeof(data))!=NULL)
			        {
			        	if(data.isThisName(name))
			         	{
			       			flag=2;
			         		cout<<endl<<"Following record found : "<<endl<<endl;
						display_line();
						cout<<endl;
						display_header();
						cout<<endl;
						display_line();
						cout<<endl;
			         		data.display();
			         		cout<<endl;
			         		display_line();
			         		cout<<endl;
			         		break;
					}
			        }
			        if(flag==0)
			        	cout<<endl<<"Record not found";
			        infile.close();
				cout<<endl<<endl;
				break;
			case 7:
				return 0;
				break;
			default:
				cout<<"Invalid input";
				cout<<endl<<endl;
				cin.ignore(1000,'\n');
				break;
		}
	}while(1);
	return 0;
}

void display_header()
{
cout<<"|              Name              |  Roll Number  | Division |                Address                 |";
}

void display_line()
{
cout<<"------------------------------------------------------------------------------------------------------";
}
