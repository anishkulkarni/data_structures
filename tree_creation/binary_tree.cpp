#include "binary_tree.h"

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
void binary_tree<T>::create_from_postfix()
{
	char postfix[200];
	tnode<T> *temp = NULL;
	stack<tnode<T> *> base_stack;
	cout << endl << endl << "Enter the postfix expression: ";
	cin >> postfix;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		cout<<endl<<endl<<"Considered character: "<<postfix[i];
		if (is_alpha(postfix[i]))
		{
			cout<<endl<<endl<<"Operand found: "<<postfix[i];
			base_stack.push(create_node(postfix[i], NULL, NULL));
			cout<<endl<<endl<<"Pushing: "<<postfix[i];
		}
		else
		{
			cout<<endl<<endl<<"Operator found: "<<postfix[i];
			temp = create_node(postfix[i], NULL, NULL);
			temp->right = base_stack.pop();
			cout<<endl<<endl<<"Right node is: "<<temp->right->data;
			temp->left = base_stack.pop();
			cout<<endl<<endl<<"Left node is: "<<temp->left->data;
			base_stack.push(temp);
			cout<<endl<<endl<<"Tree generated is (Inorder Traversal): ";
			r_inorder(temp);
		}
		cout<<endl<<endl<<"Stack contents are (Top at left): ";
		base_stack.display();
	}
	root = base_stack.pop();
	cout<<endl<<endl<<"Final tree generated is (Inorder Traversal): ";
	r_inorder(root);
}

template<typename T>
tnode<T>* binary_tree<T>::create_node(T d, tnode<T>* l, tnode<T>* r)
{
	return new tnode<T>(d, l, r);
}

template <typename T>
void binary_tree<T>::nr_inorder()
{
	stack<tnode<T> *>base_stack;
	tnode<T> *temp = NULL;
	if(root!=NULL)
		temp=root;
	do
	{
		while(temp!=NULL)
		{
			base_stack.push(temp);
			temp=temp->left;
		}
		if(!base_stack.is_empty())
		{
			temp=base_stack.pop();
			cout<<temp->data;
			temp=temp->right;
		}
	}while(temp!=NULL || !base_stack.is_empty());
}

template <typename T>
void binary_tree<T>::nr_postorder()
{
	stack<tnode<T> *>base_stack;
	tnode<T> *temp = NULL, *previous = NULL;
	if (root != NULL)
		base_stack.push(root);
	while (!base_stack.is_empty())
	{
		temp = base_stack.pop();
		if (temp->left == NULL && temp->right == NULL)
		{
			previous = temp;
			cout << temp->data;
		}
		else if (temp->right == previous || temp->left == previous)
		{
			previous = temp;
			cout << temp->data;
		}
		else
		{
			base_stack.push(temp);
			if (temp->right != NULL)
				base_stack.push(temp->right);
			if (temp->left != NULL)
				base_stack.push(temp->left);
		}
	}
}

template <typename T>
void binary_tree<T>::nr_preorder()
{
	stack<tnode<T> *>base_stack;
	tnode<T> *temp = NULL;
	if(root!=NULL)
		base_stack.push(root);
	do
	{
		temp=base_stack.pop();
		while(temp!=NULL)
		{
			cout<<temp->data;
			if(temp->right!=NULL)
				base_stack.push(temp->right);
			temp=temp->left;
		}
	}while(!base_stack.is_empty());
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
		cout << r->data;
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
		cout << r->data;
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
		cout << r->data;
		r_preorder(r->left);
		r_preorder(r->right);
	}
}

template <typename T>
bool binary_tree<T>::is_alpha(char x)
{
	if ((x >= 'a'&&x <= 'z') || (x >= 'A'&&x <= 'Z'))
		return true;
	else
		return false;
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
binary_tree<T>::~binary_tree()
{
	delete_tree(root);
}
