#include <iostream>
#include"priority_queue.h"
#include"priority_queue.cpp"
#include"patient.h"

using namespace std;

int main()
{
	int choice;
	patient p;
	priority_queue<patient> base_queue;
	do
	{
		cout << "Menu\n1. Enroll patient\n2. Call patient\n3. Check next patient\n4. Display all patients\n5. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // Case to enroll patient
			cout << endl;
			p.enroll();
			base_queue.enqueue(p, p.get_priority());
			cout << endl << endl;
			break;
		case 2: // Case to call next patient
			if (base_queue.is_empty())
				cout << endl << "Patient Queue empty";
			else
			{
				p = base_queue.dequeue();
				cout << endl << "Following patient called:" << endl;
				p.display();
			}
			cout << endl << endl;
			break;
		case 3: // Case to check next patient
			if (base_queue.is_empty())
				cout << endl << "Patient Queue empty";
			else
			{
				cout << endl << "Following is the next patient:" << endl;
				p = base_queue.peek();
				p.display();
			}
			cout << endl << endl;
			break;
		case 4: // Case to display all patients
			if (!base_queue.display())
				cout << endl << "Patient queue empty";
			cout << endl << endl;
			break;
		case 5: // Case to exit
			return 0;
			break;
		default: // Case to handle invalid inputs
			cout << "\nInvalid choice" << endl << endl;
			break;
		}
	} while (1);
	return 0;
}
