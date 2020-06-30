#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include<iostream>
#include<iomanip>

using namespace std;

template <typename T>
class HashTable
{
	T *keyTable;
	int *chain;
	long int *key;
	int size;
public:
	HashTable(int);
	void insertWithoutReplacement(T);
	void insertWithReplacement(T);
	void display();
	void search(T);
	void _delete(T);
	bool isFull();
	virtual ~HashTable();
};

#endif
