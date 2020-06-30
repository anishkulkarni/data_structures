#include "priority_queue.h"

template <typename T>
priority_queue<T>::priority_queue()
{
}

template <typename T>
void priority_queue<T>::enqueue(T d, priority p)
{
	base_list.add_at_end_prioritized(d, p);
}

template <typename T>
T priority_queue<T>::dequeue()
{
	return base_list.remove_at_beginning();
}

template <typename T>
T priority_queue<T>::peek()
{
	return base_list.first_element();
}

template <typename T>
bool priority_queue<T>::is_empty()
{
	return base_list.is_empty();
}

template <typename T>
bool priority_queue<T>::display()
{
	return base_list.display();
}

template <typename T>
priority_queue<T>::~priority_queue()
{
}
