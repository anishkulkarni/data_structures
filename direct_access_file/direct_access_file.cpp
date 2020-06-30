#include <iostream>
#include"DirectAccessFile.h" //header file inclusion

using namespace std; //namespace declaration

int main() //Main function
{
	int choice;
	cout << "Enter the number of records: ";
	cin >> choice;
	DirectAccessFile dafile(choice);
	do
	{
		cout << "Menu\n1. Add record\n2. Display database\n3. Delete record\n4. Modify record\n5. Search record\n6. Exit\nChoice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: //add record
			dafile.insert();
			break;
		case 2: //display database
			dafile.display();
			break;
		case 3: //delete record
		{
			int choice;
			cout << "Enter id to search: ";
			cin >> choice;
			dafile.deleter(choice);
			break;
		}
			break;
		case 4: // Modify record
		{
			int choice;
			cout << "Enter id to search: ";
			cin >> choice;
			dafile.modify(choice);
			break;
		}
		case 5: //Search record
		{
			int choice;
			cout << "Enter id to search: ";
			cin >> choice;
			dafile.search(choice);
			break;
		}
		case 6: //exit
			return 0;
			break;
		default:
			cout << "Invalid input";
			cout << endl << endl;
			cin.ignore(1000, '\n');
			break;
		}
	} while (1);
	return 0;
}