#ifndef BST_NODE_H_
#define BST_NODE_H_

#include<iostream>

template<typename T>
class BST_node
{
public:
	T data;
	BST_node<T> *left, *right;
	BST_node();
	BST_node(T d = 0, BST_node<T> *r = NULL, BST_node<T> *l = NULL);
	virtual ~BST_node();
};

#endif
