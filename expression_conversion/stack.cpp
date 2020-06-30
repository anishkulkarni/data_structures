#include "stack.h"

template <typename T>
stack<T>::stack()
{

}

template <typename T>
bool stack<T>::is_empty()
{
	return base_list.is_empty();
}

template <typename T>
void stack<T>::push(T push_data)
{
	base_list.add_at_beginning(push_data);
}

template<typename T>
T stack<T>::peek()
{
	return base_list.first_element();
}

template<typename T>
T stack<T>::pop()
{
	return base_list.remove_at_beginning();
}

template<typename T>
void stack<T>::display()
{
	base_list.display();
}

template <typename T>
stack<T>::~stack()
{

}
