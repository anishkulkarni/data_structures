#include "BST_node.h"

template <typename T>
BST_node<T>::BST_node()
{
	data = 0;
	left = NULL;
	right = NULL;
}

template <typename T>
BST_node<T>::BST_node(T d, BST_node<T> *r, BST_node<T> *l)
{
	data = d;
	left = l;
	right = r;
}

template <typename T>
BST_node<T>::~BST_node()
{
}
