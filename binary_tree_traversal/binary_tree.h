#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include"tnode.h"
#include"tnode.cpp"
#include<iostream>

using namespace std;

template <typename T>
class binary_tree
{
	tnode<T> *root;
public:
	binary_tree();
	void insert(T);
	void nr_insert(T);
	void inorder();
	void postorder();
	void preorder();
	void levelorder();
	void r_inorder(tnode<T> *);
	void r_postorder(tnode<T> *);
	void r_preorder(tnode<T> *);
	void delete_tree(tnode<T> *);
	void insert_node(tnode<T> *r, T d);
	tnode<T> *create_node(T d = 0, tnode<T> *l = NULL, tnode<T> *r = NULL);
	bool is_empty();
	int depth();
	int r_depth(tnode<T> *);
	void leaves();
	tnode<T> *copy();
	tnode<T> *r_copy(tnode<T> *);
	void set_tree(tnode<T> *);
	int larger(int,int);
	virtual ~binary_tree();
};

#endif
