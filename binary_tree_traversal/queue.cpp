#include"queue.h"

template<typename T>
queue<T>::queue()
{
}

template<typename T>
void queue<T>::enqueue(T d)
{
	base_list.add_at_end(d);
}

template<typename T>
T queue<T>::dequeue()
{
	return base_list.remove_at_beginning();
}

template<typename T>
T queue<T>::peek()
{
	return base_list.first_element();
}

template<typename T>
bool queue<T>::is_empty()
{
	return base_list.is_empty();
}

template<typename T>
queue<T>::~queue()
{
}
