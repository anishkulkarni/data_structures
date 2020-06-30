#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include"BST_node.h"
#include"BST_node.cpp"
#include"stack.h"
#include"stack.cpp"
#include"queue.h"
#include"queue.cpp"
#include<iostream>

template <typename T>
class binary_search_tree
{
	BST_node<T> *root;
public:
	binary_search_tree();
	void nr_insert(T);
	void insert(T);
	void r_insert(BST_node<T> *, T);
	BST_node<T> *create_node(T d = 0, BST_node<T> *l = NULL, BST_node<T> *r = NULL);
	bool is_empty();
	void levelorder();
	void inorder();
	void preorder();
	void postorder();
	void r_inorder(BST_node<T> *);
	void r_preorder(BST_node<T> *);
	void r_postorder(BST_node<T> *);
	bool nr_search(T);
	bool search(T);
	bool r_search(BST_node<T> *, T);
	int depth();
	int r_depth(BST_node<T> *);
	int larger(int, int);
	void nr_delete(T);
	void del(T);
	BST_node<T> *r_delete(BST_node<T> *, T);
	BST_node<T> *find_min(BST_node<T> *);
	void nr_mirror();
	void mirror();
	void r_mirror(BST_node<T> *);
	void delete_tree(BST_node<T> *);
	virtual ~binary_search_tree();
};

#endif
