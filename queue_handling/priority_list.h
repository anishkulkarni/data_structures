#ifndef PRIORITY_LIST_H_
#define PRIORITY_LIST_H_

#include <iostream>

enum priority
{
	low,medium,high
};

template<typename T>
struct priority_node
{
	T data;
	priority node_priority;
	priority_node<T> *next;
};

template<typename T>
class priority_list
{
protected:
	priority_node<T> *head, *rear;
public:
	priority_list();
	bool is_empty();
	priority_node<T> *add_node(T d = 0, priority p = medium, priority_node<T> *next_node = NULL);
	void add_at_end_prioritized(T, priority);
	T first_element();
	T remove_at_beginning();
	bool display();
	virtual ~priority_list();
};

#endif
