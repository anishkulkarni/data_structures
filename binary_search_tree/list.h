#ifndef LIST_H_
#define LIST_H_

#include<iostream>

template<typename T>
struct node
{
	T data;
	node<T> *next;
};

template<typename T>
class list
{
protected:
	node<T> *head,*rear;
public:
	list();
	bool is_empty();
	void add_at_beginning(T);
	node<T> *add_node(T d = 0, node<T> *next_node = NULL);
	T first_element();
	void add_at_end(T);
	T remove_at_beginning();
	void display();
	virtual ~list();
};

#endif
