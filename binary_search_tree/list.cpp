#include "list.h"
#include<iostream>

template <class T>
list<T>::list()
{
	head = NULL;
}

template <typename T>
bool list<T>::is_empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

template <typename T>
node<T> *list<T>::add_node(T d, node<T> *next_node)
{
	node<T> *temp = new node<T>;
	temp->data = d;
	temp->next = next_node;
	return temp;
}

template <class T>
T list<T>::first_element()
{
	return head->data;
}

template <class T>
void list<T>::add_at_beginning(T d)
{
	node<T> *temp = (node<T> *)add_node(d, head);
	head = temp;
}

template <class T>
void list<T>::add_at_end(T d)
{
	node<T> *temp = (node<T> *)add_node(d, NULL);
	if (head == NULL)
	{
		head = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = rear->next;
	}
}

template <class T>
T list<T>::remove_at_beginning()
{
	node<T> *temp = head;
	head = head->next;
	T d = temp->data;
	delete temp;
	return d;
}

template <class T>
void list<T>::display()
{
	node<T> *temp = head;
	while (temp != NULL)
	{
		std::cout << " " << temp->data;
		temp = temp->next;
	}
}

template <class T>
list<T>::~list()
{
	node<T> *temp = head;
	while (temp != NULL)
	{
		head = temp->next;
		delete temp;
		temp = head;
	}
}
