#ifndef LIST_H_
#define LIST_H_

#include<iostream>

#include "node.h"

template<typename T>
class list
{
	protected:
		node<T> *head;
		node<T> *rear;
	public:
		list();
		bool is_empty();
		void add_at_beginning(T);
		void add_at_end(T);
		node<T> *add_node(T d=0,node<T> *next_node=NULL);
		T first_element();
		T remove_at_beginning();
		void display();
		virtual ~list();
};

#endif /* LIST_H_ */
