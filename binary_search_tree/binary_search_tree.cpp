#include "binary_search_tree.h"

using namespace std;

template <typename T>
binary_search_tree<T>::binary_search_tree()
{
	root = NULL;
}

template <typename T>
void binary_search_tree<T>::nr_insert(T d)
{
	if (root == NULL)
		root = create_node(d, NULL, NULL);
	else
	{
		BST_node<T>* temp = root;
		while (true)
		{
			if (d == temp->data)
			{
				cout << endl << "Duplicate node identified, not inserted";
				break;
			}
			else if (d<temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = create_node(d, NULL, NULL);
					break;
				}
				else
					temp = temp->left;
			}
			else
			{
				if (temp->right == NULL)
				{
					temp->right = create_node(d, NULL, NULL);
					break;
				}
				else
					temp = temp->right;
			}
		}
	}
}

template <typename T>
void binary_search_tree<T>::insert(T d)
{
	r_insert(root, d);
}

template <typename T>
void binary_search_tree<T>::r_insert(BST_node<T> *r, T d)
{
	if (r == NULL)
		root = create_node(d, NULL, NULL);
	else
	{
		if (d<r->data)
		{
			if (r->left == NULL)
				r->left = create_node(d, NULL, NULL);
			else
				r_insert(r->left, d);
		}
		else if (d>r->data)
		{
			if (r->right == NULL)
				r->right = create_node(d, NULL, NULL);
			else
				r_insert(r->right, d);
		}
	}
}

template <typename T>
BST_node<T> *binary_search_tree<T>::create_node(T d, BST_node<T> *l, BST_node<T> *r)
{
	BST_node<T> *temp = new BST_node<T>(d, NULL, NULL);
	return temp;
}

template <typename T>
void binary_search_tree<T>::levelorder()
{
	queue<BST_node<T> *> base_queue;
	BST_node<T> *r = root;
	base_queue.enqueue(r);
	while (!base_queue.is_empty())
	{
		r = base_queue.dequeue();
		cout << "\t" << r->data;
		if (r->left != NULL)
			base_queue.enqueue(r->left);
		if (r->right != NULL)
			base_queue.enqueue(r->right);
	}
}

template <typename T>
void binary_search_tree<T>::inorder()
{
	r_inorder(root);
}

template <typename T>
void binary_search_tree<T>::r_inorder(BST_node<T> *r)
{
	if (r != NULL)
	{
		r_inorder(r->left);
		cout << "\t" << r->data;
		r_inorder(r->right);
	}
}

template <typename T>
void binary_search_tree<T>::postorder()
{
	r_postorder(root);
}

template <typename T>
void binary_search_tree<T>::r_postorder(BST_node<T> *r)
{
	if (r != NULL)
	{
		r_postorder(r->left);
		r_postorder(r->right);
		cout << "\t" << r->data;
	}
}

template <typename T>
void binary_search_tree<T>::preorder()
{
	r_preorder(root);
}

template <typename T>
void binary_search_tree<T>::r_preorder(BST_node<T> *r)
{
	if (r != NULL)
	{
		cout << "\t" << r->data;
		r_preorder(r->left);
		r_preorder(r->right);
	}
}

template <typename T>
bool binary_search_tree<T>::search(T d)
{
	return r_search(root, d);
}

template <typename T>
bool binary_search_tree<T>::r_search(BST_node<T> *r, T d)
{
	if (r == NULL)
		return false;
	else
	{
		if (d == r->data)
			return true;
		else if (d<r->data)
			return r_search(r->left, d);
		else
			return r_search(r->right, d);
	}
	return false;
}

template <typename T>
bool binary_search_tree<T>::nr_search(T d)
{
	if (root == NULL)
		return false;
	else
	{
		BST_node<T> *temp = root;
		while (temp != NULL)
		{
			if (d == temp->data)
				return true;
			else if (d<temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return false;
}

template <typename T>
bool binary_search_tree<T>::is_empty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

template <typename T>
int binary_search_tree<T>::larger(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

template <typename T>
int binary_search_tree<T>::depth()
{
	return r_depth(root);
}

template <typename T>
int binary_search_tree<T>::r_depth(BST_node<T> *r)
{
	if (r == NULL)
		return 0;
	else
		return(1 + larger(r_depth(r->left), r_depth(r->right)));
}

template <typename T>
void binary_search_tree<T>::nr_delete(T d)
{
	BST_node<T> *ptr=root, *parent=NULL, *child_ptr=NULL;
	bool is_left = false;
	while (1)
	{
		while (ptr != NULL) // find node to delete
		{
			if (d == ptr->data)
				break; // Found it
			else if (d < ptr->data)
			{
				parent = ptr;
				is_left = 1; /* Left */
				ptr = ptr->left;
			}
			else
			{
				parent = ptr;
				is_left = 0; /* Right */
				ptr = ptr->right;
			}
		}
		if (ptr == NULL) // node not found
			return;
		// ptr is now pointing to the node to be deleted
		if ((ptr->left == NULL) && (ptr->right == NULL)) // leaf node
		{
			if (parent == NULL) // node is root
			{
				delete root;
				root = NULL;
			}
			else
			{
				delete ptr;
				if (is_left)
					parent->left = NULL;
				else
					parent->right = NULL;
			}
			return;
		}
		else
		{
			if ((ptr->left == NULL) || (ptr->right == NULL)) // node has one child
			{
				if (ptr->left != NULL) // left child
					child_ptr = ptr->left;
				else // right child
					child_ptr = ptr->right;
				if (parent == NULL) // root is being deleted
				{
					root = child_ptr;
					delete ptr;
				}
				else // non root node being deleted
				{
					if (is_left)
						parent->left = child_ptr;
					else
						parent->right = child_ptr;
					delete ptr;
				}
				return;
			}
			else // node has both children
			{
				BST_node<T> *temp = ptr->right;
				while (temp->left != NULL)
					temp=temp->right;
				ptr->data = temp->data;
				parent = ptr;
				ptr = ptr->left;
				d = temp->data;
			}
		}
	}
}

template <typename T>
void binary_search_tree<T>::del(T d)
{
	root = r_delete(root, d);
}

template <typename T>
BST_node<T> *binary_search_tree<T>::r_delete(BST_node<T> *r, T d)
{
	BST_node<T> *temp = NULL;
	if (r == NULL)
		return NULL;
	else
	{
		if (d < r->data) // key less than root
		{
			r->left = r_delete(r->left, d);
			return r;
		}
		else if (d > r->data) // key greater than root
		{
			r->right = r_delete(r->right, d);
			return r;
		}
		else // key found
		{
			if (r->left == NULL && r->right == NULL) // leaf node
			{
				delete r;
				return NULL;
			}
			else if (r->left == NULL) // no left child
			{
				temp = r->right;
				delete r;
				return temp;
			}
			else if(r->right == NULL) // no right child
			{
				temp = r->left;
				delete r;
				return temp;
			}
			else // both children
			{
				temp = find_min(r->right);
				r->data = temp->data;
				r->right = r_delete(r->right, temp->data);
			}
			return r;
		}
	}
}

template <typename T>
BST_node<T> *binary_search_tree<T>::find_min(BST_node<T> *r)
{
	while (r->left != NULL)
		r = r->left;
	return r;
}

template <typename T>
void binary_search_tree<T>::nr_mirror()
{
	BST_node<T> *temp = NULL,*r=NULL;
	stack<BST_node<T> *> base_stack;
	if (root != NULL)
		base_stack.push(root);
	while (!base_stack.is_empty())
	{
		r = base_stack.pop();
		temp = r->left;
		r->left = r->right;
		r->right = temp;
		if (r->left != NULL)
			base_stack.push(r->left);
		if (r->right != NULL)
			base_stack.push(r->right);
	}
}

template <typename T>
void binary_search_tree<T>::mirror()
{
	r_mirror(root);
}

template <typename T>
void binary_search_tree<T>::r_mirror(BST_node<T> *r)
{
	BST_node<T> *temp;
	if (r != NULL)
	{
		temp = r->left;
		r->left = r->right;
		r->right = temp;
		r_mirror(r->left);
		r_mirror(r->right);
	}
}

template <typename T>
void binary_search_tree<T>::delete_tree(BST_node<T> *r)
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
binary_search_tree<T>::~binary_search_tree()
{
	delete_tree(root);
}
