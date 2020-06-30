#include "circular_queue.h"
#include<iostream>

using namespace std;

circular_queue::circular_queue()
{
	front = rear = -1;
}

bool circular_queue::is_full()
{
	if ((rear == front - 1) || (rear == MAX - 1 && front == 0))//
		return true;
	else
		return false;
}

bool circular_queue::is_empty()
{
	if (front == -1)
		return true;
	else
		return false;
}

void circular_queue::enqueue(int d)
{
	if (front == -1)//
		front++;
	rear = (rear + 1) % MAX;//
	a[rear] = d;
}

int circular_queue::dequeue()
{
	int temp = a[front];
	if (front == rear)//
		front = rear = -1;
	else
		front = (front + 1) % MAX;
	return temp;
}

void circular_queue::display()
{
	cout << endl;
	for (int i = 0; i < MAX; i++)
		cout << "\t" << a[i];
	cout << endl << "rear = " << rear;
	cout << endl << "front = " << front;
	cout << endl << "a[rear] = " << a[rear];
	cout << endl << "a[front] = " << a[front];
}

circular_queue::~circular_queue()
{
}
