#include <iostream>
#include "binary_search_tree.h"
#include "binary_search_tree.cpp"

using namespace std;

int main()
{
	int choice;
	string data;
	binary_search_tree<string> base_tree;
	do
	{
		cout << "Menu\n1. Insert\n2. Delete\n3. Search\n4. Mirror\n5. Display\n6. Display Height\n7. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // Case for insertion
			cout << "\nSelect insertion method:\n1. Recursive\n2. Non Recursive\nChoice: ";
			cin >> choice;
			switch (choice)
			{
			case 1: // Case for recursive insertion
				cout << endl << "Enter the data to be inserted: ";
				cin >> data;
				base_tree.insert(data);
				break;
			case 2: // Case for non recursive insertion
				cout << endl << "Enter the data to be inserted: ";
				cin >> data;
				base_tree.nr_insert(data);
				break;
			default: // Case to handle invalid input
				cout << endl << "Invalid choice";
				break;
			}
			cout << endl << endl;
			break;
		case 2: // Case to delete
			cout << "\nSelect search method:\n1. Recursive\n2. Non Recursive\nChoice: ";
			cin >> choice;
			switch (choice)
			{
			case 1: // Case to delete recursively
				cout << endl << "Enter the data to be deleted: ";
				cin >> data;
				base_tree.del(data);
				break;
			case 2: // Case to delete non recursively
				cout << endl << "Enter the data to be deleted: ";
				cin >> choice;
				base_tree.nr_delete(data);
				break;
			default: // Case to handle invalid input
				cout << endl << "Invalid choice";
				break;
			}
			cout << endl << endl;
			break;
		case 3:
			cout << "\nSelect search method:\n1. Recursive\n2. Non Recursive\nChoice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << endl << "Enter the data to be searched: ";
				cin >> data;
				if (base_tree.search(data))
					cout << endl << "Given element found";
				else
					cout << endl << "Given element not found";
				break;
			case 2:
				cout << endl << "Enter the data to be searched: ";
				cin >> data;
				if (base_tree.nr_search(data))
					cout << endl << "Given element found";
				else
					cout << endl << "Given element not found";
				break;
			default:
				cout << endl << "Invalid choice";
				break;
			}
			cout << endl << endl;
			break;
		case 4:
			cout << "\nSelect mirror method:\n1. Recursive\n2. Non Recursive\nChoice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				base_tree.mirror();
				break;
			case 2:
				base_tree.nr_mirror();
				break;
			default:
				cout << endl << "Invalid choice";
				break;
			}
			cout << endl << endl;
			break;
		case 5:
			if (base_tree.is_empty())
				cout << endl << "Tree is empty";
			else
			{
				cout << endl << "Inorder traversal: ";
				base_tree.inorder();
				cout << endl << "Preorder traversal: ";
				base_tree.preorder();
				cout << endl << "Postorder traversal: ";
				base_tree.postorder();
				cout << endl << "Levelorder traversal: ";
				base_tree.levelorder();
			}
			cout << endl << endl;
			break;
		case 6: // Case for height display
			cout << endl << "The height of the tree is: " << base_tree.depth();
			cout << endl << endl;
			cout << endl << endl;
			break;
		case 7:
			return 0;
			cout << endl << endl;
			break;
		default:
			cout << endl << "Invalid choice" << endl << endl;
			break;
		}
	} while (1);
	return 0;
}
