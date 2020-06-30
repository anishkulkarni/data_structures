#include "binary_tree.h"
#include"queue.h"
#include"queue.cpp"
using namespace std;

template <typename T>
int binary_tree<T>::larger(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

template <typename T>
binary_tree<T>::binary_tree()
{
	root = NULL;
}

template <typename T>
void binary_tree<T>::insert(T d)
{
	insert_node(root, d);
}

template<typename T>
tnode<T>* binary_tree<T>::create_node(T d, tnode<T>* l, tnode<T>* r)
{
	return new tnode<T>(d, l, r);
}

template <typename T>
void binary_tree<T>::insert_node(tnode<T> *r,T d)
{
	if (r == NULL) // Tree Empty
		root = create_node(d, NULL, NULL);
	else
	{
		int choice;
		do
		{
			cout << endl << "Choose path\n1. Left\n2. Right\nChoice: ";
			cin >> choice;
			switch (choice)
			{
			case 1: // Insertion at left
				if (r->left == NULL)
					r->left = create_node(d, NULL, NULL);
				else
					insert_node(r->left,d);
				break;
			case 2: // Insertion at right
				if (r->right == NULL)
					r->right = create_node(d, NULL, NULL);
				else
					insert_node(r->right,d);
				break;
			default:
				cout << endl << "Invalid choice. Please try again";
				break;
			}
		} while (choice < 1 || choice>2);
	}
}

template <typename T>
void binary_tree<T>::nr_insert(T d)
{
	if(root==NULL) // Empty Tree
	{
		root=create_node(d,NULL,NULL);
	}
	else
	{
		tnode<T>* p=root;
		while(true)
		{
			int choice;
			cout << endl << "Choose path\n1. Left\n2. Right\nChoice: ";
			cin >> choice;
			switch (choice)
			{
			case 1: // Insertion at left
				if(p->left==NULL)
					p->left=create_node(d,NULL,NULL);
				else
					p=p->left;
				break;
			case 2: // Insertion at right
				if(p->right==NULL)
					p->right=create_node(d,NULL,NULL);
				else
					p=p->right;
				break;
			default:
				cout << endl << "Invalid choice. Please try again";
				break;
			}
		}
	}
	return;
}

template <typename T>
void binary_tree<T>::inorder()
{
	r_inorder(root);
}

template <typename T>
void binary_tree<T>::r_inorder(tnode<T> *r)
{
	if (r != NULL)
	{
		r_inorder(r->left);
		cout << "\t" << r->data;
		r_inorder(r->right);
	}
}

template <typename T>
void binary_tree<T>::postorder()
{
	r_postorder(root);
}

template <typename T>
void binary_tree<T>::r_postorder(tnode<T> *r)
{
	if (r != NULL)
	{
		r_postorder(r->left);
		r_postorder(r->right);
		cout << "\t" << r->data;
	}
}

template <typename T>
void binary_tree<T>::preorder()
{
	r_preorder(root);
}

template <typename T>
void binary_tree<T>::r_preorder(tnode<T> *r)
{
	if (r != NULL)
	{
		cout << "\t" << r->data;
		r_preorder(r->left);
		r_preorder(r->right);
	}
}

template <typename T>
void binary_tree<T>::levelorder()
{
	queue<tnode<T> *> base_queue;
	tnode<T> *r = root;
	base_queue.enqueue(r); // Enqueue root
	while (!base_queue.is_empty())
	{
		r = base_queue.dequeue(); // Dequeue node
		cout << "\t" << r->data;
		if (r->left != NULL)
			base_queue.enqueue(r->left);
		if (r->right != NULL)
			base_queue.enqueue(r->right);
	}
}

template <typename T>
void binary_tree<T>::leaves()
{
	queue<tnode<T> *> base_queue;
	tnode<T> *r = root;
	base_queue.enqueue(r); // Enqueue root
	while (!base_queue.is_empty())
	{
		r = base_queue.dequeue(); // Dequeue node
		if (r->right == NULL && r->left == NULL) // Check if leaf node
			cout << "\t" << r->data;
		if (r->left != NULL)
			base_queue.enqueue(r->left);
		if (r->right != NULL)
			base_queue.enqueue(r->right);
	}
}

template <typename T>
void binary_tree<T>::delete_tree(tnode<T> *r)
{
	if (r != NULL)
	{
		if (r->left != NULL)
			delete_tree(r->left);
		if (r->right != NULL)
			delete_tree(r->right);
		delete r;
	}
}

template <typename T>
bool binary_tree<T>::is_empty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

template <typename T>
int binary_tree<T>::depth()
{
	return r_depth(root);
}

template <typename T>
int binary_tree<T>::r_depth(tnode<T> *r)
{
	if (r == NULL)
		return 0;
	else
		return(1 + larger(r_depth(r->left), r_depth(r->right)));
}

template <typename T>
tnode<T> *binary_tree<T>::copy()
{
	return r_copy(root);
}

template <typename T>
tnode<T> *binary_tree<T>::r_copy(tnode<T> *r)
{
	tnode<T> *temp = create_node(0, NULL, NULL);
	if (r == NULL)
		return NULL;
	else
	{
		temp->data = r->data;
		temp->left = r_copy(r->left);
		temp->right = r_copy(r->right);
	}
	return temp;
}

template <typename T>
void binary_tree<T>::set_tree(tnode<T> *r)
{
	root = r;
}

template <typename T>
binary_tree<T>::~binary_tree()
{
	delete_tree(root);
}
