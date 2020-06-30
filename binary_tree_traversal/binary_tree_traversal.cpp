#include<iostream>
#include"binary_tree.h"
#include"binary_tree.cpp"

int main()
{
	int choice;
	binary_tree<int> base_tree,copy_tree;
	do
	{
		cout << "Menu\n1. Non Recursive Insert\n2. Recursive Insert\n3. Display\n4. Display Depth\n5. Display leaf nodes\n6. Create copy\n7. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // Case for Non Recursive Insertion
			cout << "Enter the node value to insert: ";
			cin >> choice;
			base_tree.nr_insert(choice);
			if (base_tree.is_empty())
				cout << endl << "Tree is empty";
			else
			{
				cout << endl << "Inorder traversal: ";
				base_tree.inorder();
			}
			cout << endl << endl;
			break;
		case 2: // Case for Recursive Insertion
			cout << "Enter the node value to insert: ";
			cin >> choice;
			base_tree.insert(choice);
			if (base_tree.is_empty())
				cout << endl << "Tree is empty";
			else
			{
				cout << endl << "Inorder traversal: ";
				base_tree.inorder();
			}
			cout << endl << endl;
			break;
		case 3: // Case for Display
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
		case 4: // Case for depth display
			cout << endl << "The depth of the tree is: " << base_tree.depth();
			cout << endl << endl;
			break;
		case 5: // Case to display leaf nodes
			if (base_tree.is_empty())
				cout << endl << "Tree is empty";
			else
			{
				cout << endl << "The leaf nodes are: ";
				base_tree.leaves();
			}
			cout << endl << endl;
			break;
		case 6: // Case to copy tree
			cout << endl << "The original tree is:";
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
			copy_tree.set_tree(base_tree.copy());
			cout << endl << endl << "The copied tree is:";
			if (copy_tree.is_empty())
				cout << endl << "Tree is empty";
			else
			{
				cout << endl << "Inorder traversal: ";
				copy_tree.inorder();
				cout << endl << "Preorder traversal: ";
				copy_tree.preorder();
				cout << endl << "Postorder traversal: ";
				copy_tree.postorder();
				cout << endl << "Levelorder traversal: ";
				copy_tree.levelorder();
			}
			cout << endl << endl;
			break;
		case 7: // Case to exit
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
