#ifndef STACK_H_
#define STACK_H_

#include"list.h"
#include"list.cpp"

template <typename T>
class stack
{
protected:
	list<T> base_list;
public:
	stack();
	bool is_empty();
	void push(T);
	void display();
	T pop();
	T peek();
	virtual ~stack();
};

#endif
