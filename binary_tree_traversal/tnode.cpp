#include "tnode.h"
#include <iostream>

template <typename T>
tnode<T>::tnode()
{
	data = 0;
	left = NULL;
	right = NULL;
}

template <typename T>
tnode<T>::tnode(T d, tnode *r, tnode *l)
{
	data = d;
	left = l;
	right = r;
}

template <typename T>
tnode<T>::~tnode()
{
}
