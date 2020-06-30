#ifndef TNODE_H_
#define TNODE_H_

template <typename T>
class tnode
{
public:
	T data;
	tnode *left, *right;
	tnode();
	tnode(T d, tnode *r, tnode *l);
	virtual ~tnode();
};

#endif
