#include<iostream>
#include"circular_queue.h"
using namespace std;

int main()
{
	int choice = 0;
	circular_queue cq;
	do
	{
		cout << "Menu\n1. Enqueue\n2. Dequeue\n3. Dispaly queue contents\n4. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if (cq.is_full())
				cout << endl << "Queue full";
			else
			{
				cout << endl << "Enter the element to enqueue: ";
				cin >> choice;
				cq.enqueue(choice);
			}
			cout << endl << endl;
			break;
		case 2:
			if (cq.is_empty())
				cout << endl << "Queue empty";
			else
			{
				cout << endl << "The element dequeued is: " << cq.dequeue();
			}
			cout << endl << endl;
			break;
		case 3:
			cq.display();
			cout << endl << endl;
			break;
		case 4:
			return 0;
			break;
		default:
			cout << endl << "Invalid input" << endl << endl;
			break;
		}
	} while (1);
}
