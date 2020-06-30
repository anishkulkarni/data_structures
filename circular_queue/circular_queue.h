#pragma once
#define MAX 5
class circular_queue
{
	int a[MAX],front,rear;
public:
	circular_queue();
	bool is_empty();
	bool is_full();
	void enqueue(int);
	int dequeue();
	void display();
	virtual ~circular_queue();
};
