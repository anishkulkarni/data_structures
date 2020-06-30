#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include "priority_list.h"
#include "priority_list.cpp"

template <typename T>
class priority_queue
{
	priority_list<T> base_list;
public:
	priority_queue();
	void enqueue(T, priority);
	T dequeue();
	T peek();
	bool is_empty();
	bool display();
	virtual ~priority_queue();
};

#endif
