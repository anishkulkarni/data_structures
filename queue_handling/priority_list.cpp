#include "priority_list.h"

template<typename T>
priority_list<T>::priority_list()
{
	head = NULL;
	rear = NULL;
}

template<typename T>
bool priority_list<T>::is_empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

template<typename T>
priority_node<T> *priority_list<T>::add_node(T d, priority p, priority_node<T> *next_node)
{
	priority_node<T> *temp = new priority_node<T>;
	temp->data = d;
	temp->node_priority = p;
	temp->next = next_node;
	return temp;
}

template<typename T>
void priority_list<T>::add_at_end_prioritized(T d, priority p)
{
	priority_node<T> *temp = NULL, *temp_next = head;
	while (temp_next != NULL) // Traverse till the last node
	{
		if (temp_next->node_priority < p) // Required position found
			break;
		temp = temp_next;
		temp_next = temp_next->next;
	}
	if (temp == NULL) // Required position is at the beginning
	{
		head = add_node(d, p, head);
	}
	else // Insert at required positionS
	{
		temp->next = add_node(d, p, temp_next);
	}
}

template<typename T>
T priority_list<T>::first_element()
{
	return head->data;
}

template<typename T>
T priority_list<T>::remove_at_beginning()
{
	T temp = head->data;
	priority_node<T> *saver = head;
	head = head->next;
	delete saver;
	return temp;
}

template <typename T>
bool priority_list<T>::display()
{
	priority_node<T> *temp = head;
	while (temp != NULL)
	{
		temp->data.display();
		temp = temp->next;
	}
	return (!(head == NULL));
}

template<typename T>
priority_list<T>::~priority_list()
{
	priority_node<T> *temp = head;
	priority_node<T> *saver = NULL;
	while (temp != NULL)
	{
		saver = temp;
		temp = temp->next;
		delete saver;
	}
}
