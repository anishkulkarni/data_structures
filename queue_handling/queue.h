#ifndef QUEUE_H_
#define QUEUE_H_
#include"list.h"
#include"list.cpp"

template <typename T>
class queue
{
	protected:
		list<T> base_list;
	public:
		queue();
		void enqueue(T);
		T dequeue();
		T peek();
		bool is_empty();
		virtual ~queue();
};

#endif /* QUEUE_H_ */
