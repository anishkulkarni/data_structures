#include<iostream>
#include"binary_tree.h"
#include"binary_tree.cpp"

using namespace std;

int main()
{
	int choice;
	binary_tree<char> base_tree;
	do
	{
		cout << "Menu\n1. Create tree from postfix expression\n2. Display Recursive\n3. Display Non-recursive\n4. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			base_tree.create_from_postfix();
			cout << endl << endl;
			break;
		case 2:
			if (base_tree.is_empty())
				cout << endl << "Tree is empty";
			else
			{
				cout << endl << "Recursive traversals:";
				cout << endl << "Inorder traversal: ";
				base_tree.inorder();
				cout<<endl<<"Postorder traversal: ";
				base_tree.postorder();
				cout<<endl<<"Preorder traversal: ";
				base_tree.preorder();
			}
			cout<<endl<<endl;
			break;
		case 3:
			if (base_tree.is_empty())
				cout << endl << "Tree is empty";
			else
			{
				cout << endl << "Non-recursive traversals:";
				cout << endl << "Inorder traversal: ";
				base_tree.nr_inorder();
				cout<<endl<<"Postorder traversal: ";
				base_tree.nr_postorder();
				cout<<endl<<"Preorder traversal: ";
				base_tree.nr_preorder();
			}
			cout << endl << endl;
			break;
		case 4:
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
