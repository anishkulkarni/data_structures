#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "tnode.h"
#include "tnode.cpp"
#include "stack.h"
#include "stack.cpp"
#include "queue.h"
#include "queue.cpp"
#include <iostream>

using namespace std;

template <typename T>
class binary_tree
{
	tnode<T> *root;
public:
	binary_tree();
	void nr_inorder();
	void nr_preorder();
	void nr_postorder();
	void inorder();
	void postorder();
	void preorder();
	void r_inorder(tnode<T> *);
	void r_postorder(tnode<T> *);
	void r_preorder(tnode<T> *);
	void create_from_postfix();
	void delete_tree(tnode<T> *);
	tnode<T> *create_node(T d = 0, tnode<T> *l = NULL, tnode<T> *r = NULL);
	bool is_empty();
	int larger(int, int);
	bool is_alpha(char);
	virtual ~binary_tree();
};

#endif
