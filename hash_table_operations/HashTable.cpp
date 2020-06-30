#ifndef HASHTABLE_CPP_
#define HASHTABLE_CPP_

#include "HashTable.h"

template <typename T>
HashTable<T>::HashTable(int _size)
{
	int i=0;
	size=_size;
	keyTable=new T[size];
	chain=new int[size];
	key=new long int[size];
	for(i=0;i<size;i++)
	{
		keyTable[i].init();
		chain[i]=-1;
		key[i]=-1;
	}
}

template <typename T>
void HashTable<T>::display()
{
	int i=0;
	cout<<endl<<"--------------------------------------------------------------";
	cout<<endl<<"| Index | Roll Number | Student Name | Mobile Number | Chain |";
	cout<<endl<<"--------------------------------------------------------------";
	for(i=0;i<size;i++)
	{
		cout<<endl;
		cout<<"| "<<setw(5)<<i;
		keyTable[i].display();
		cout<<setw(6)<<chain[i]<<" |";
		cout<<endl<<"--------------------------------------------------------------";
	}
}

template <typename T>
bool HashTable<T>::isFull()
{
	int i=0;
	for(i=0;i<size;i++)
		if(key[i]==-1)
			break;
	if(i==size)
		return true;
	else
		return false;
}

template <typename T>
void HashTable<T>::insertWithoutReplacement(T insertKey)
{
	int i=0,temp=-1;
	cout<<endl<<"Hash table before insertion is: "<<endl;
	display();
	cout<<endl;
	if(isFull())
	{
		cout<<endl<<"Hash Table is full";
	}
	else
	{
		int index=(insertKey.mobileNumber)%size;
		cout<<"Bucket: "<<index;
		if(key[index]==-1)
		{
			cout<<endl<<"Bucket unoccupied. Inserting in bucket";
			key[index]=insertKey.mobileNumber;
			keyTable[index]=insertKey;
		}
		else
		{
			if(((key[index])%size)==index)
				temp=index;
			i=(index+1)%size;
			while((key[i]!=-1)&&(((key[i])%size)!=index))
			{
				i=(i+1)%size;
			}
			if(key[i]==-1)
			{
				key[i]=insertKey.mobileNumber;
				keyTable[i]=insertKey;
				if(temp!=-1)
					chain[temp]=i;
			}
			else
			{
				temp=i;
				while(chain[i]!=-1)
				{
					i=chain[i];
					temp=i;
				}
				while(((key[i])%size)!=-1)
				{
					i=(i+1)%size;
				}
				key[i]=insertKey.mobileNumber;
				keyTable[i]=insertKey;
				if(temp!=-1)
					chain[temp]=i;
			}
		}
	}
	cout<<endl<<"Hash table after insertion is: "<<endl;
	display();
}

template <typename T>
void HashTable<T>::insertWithReplacement(T insertKey)
{
	cout<<endl<<"Hash table before insertion is: "<<endl;
	display();
	cout<<endl;
	int index=(insertKey.mobileNumber)%size;
	int tempChain=0;
	cout<<"Bucket: "<<index;
	int temp=0;
	T tempKey;
	if(key[index]==-1)
	{
		cout<<endl<<"Bucket unoccupied. Inserting in bucket";
		key[index]=insertKey.mobileNumber;
		keyTable[index]=insertKey;
	}
	else
	{
		if((key[index])%size==index)
		{
			cout<<endl<<"Bucket occupied with record hashed at correct place. Checking chains.";
			while(chain[index]!=-1)
			{
				index=chain[index];
				if(index!=-1)
					cout<<endl<<"Next chained bucket is: "<<index;
				else
					cout<<endl<<"All chains visited. Finding next unallocated bucket";
			}
			temp=index;
			while(key[index]!=-1)
			{
				index=(index+1)%size;
				cout<<endl<<"Next bucket checked: "<<index;
				if(index==((insertKey.mobileNumber)%size))
				{
					break;
				}
			}
			if(index!=((insertKey.mobileNumber)%size))
			{
				cout<<endl<<"Empty bucket found. Inserting";
				chain[temp]=index;
				cout<<endl<<"Chain for "<<temp<<" set as "<<index;
				key[index]=insertKey.mobileNumber;
				keyTable[index]=insertKey;
			}
			else
				cout<<endl<<"Table is full";
		}
		else
		{
			cout<<endl<<"Bucket occupied with record hashed at wrong place. It should be replaced";
			temp=(key[index])%size;
			cout<<endl<<"Index for record to be replaced is: "<<temp;
			cout<<endl<<"Checking chains";
			while(chain[temp]!=index)
			{
				temp=chain[temp];
				if(temp!=index)
					cout<<endl<<"Next chained bucket is: "<<temp;
			}
			cout<<endl<<"Predecessor of record to be replaced found";
			tempKey=keyTable[index];
			tempChain=chain[index];
			keyTable[index]=insertKey;
			key[index]=insertKey.mobileNumber;
			chain[index]=-1;
			index=temp;
			cout<<endl<<"Finding next empty slot for record to be replaced";
			while(key[temp]!=-1)
			{
				temp=(temp+1)%size;
				cout<<endl<<"Next bucket checked: "<<temp;
				if(temp==((index)%size))
				{
					break;
				}
			}
			if(temp!=(index)%size)
			{
				cout<<endl<<"Empty bucket found. Inserting";
				cout<<endl<<"Chain for "<<index<<" set as "<<temp;
				key[temp]=tempKey.mobileNumber;
				keyTable[temp]=tempKey;
				chain[temp]=tempChain;
				chain[index]=temp;
			}
			else
				cout<<endl<<"Table is full";
		}
	}
	cout<<endl<<"Hash table after insertion is: "<<endl;
	display();
}

template <typename T>
void HashTable<T>::search(T searchKey)
{
	int i=0;
	cout<<endl<<"Hash table before insertion is: "<<endl;
	display();
	cout<<endl;
	int index=(searchKey.mobileNumber)%size;
	cout<<"Bucket: "<<index;
	if(key[index]==(searchKey.mobileNumber))
		cout<<endl<<"Found in bucket: "<<index;
	else
	{
		i=index;
		if(((key[index])%size)!=index)
		{
			while(((key[i])%size)!=index)
			{
				i=(i+1)%size;
				if(i==index)
				{
					cout<<endl<<"Data isn't hashed yet hence not found";
					return;
				}
			}
		}
		index=i;
		cout<<endl<<"Not found in bucket: "<<index<<" checking chains";
		if(key[index]==searchKey.mobileNumber)
		{
			cout<<endl<<"Found in bucket: "<<i;
		}
		else
		{
			while(chain[index]!=-1)
			{
				index=chain[index];
				cout<<endl<<"Checking chained bucket: "<<index;
				if(key[index]==(searchKey.mobileNumber))
				{
					cout<<endl<<"Found in bucket: "<<index;
					break;
				}
			}
			if(chain[index]==-1 && key[index]!=(searchKey.mobileNumber))
				cout<<endl<<"Data isn't hashed yet hence not found";
		}
	}
}

template <typename T>
void HashTable<T>::_delete(T deleteKey)
{

}

template <typename T>
HashTable<T>::~HashTable()
{
	if(keyTable!=NULL)
		delete []keyTable;
	if(chain!=NULL)
		delete []chain;
}

#endif
