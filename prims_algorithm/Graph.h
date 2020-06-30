#ifndef Graph_h_
#define Graph_h_

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct edge
{
	int source, destination,weight;
};

class Graph
{
	int *adjMat;
	string *nodeNames;
	int vertices;
public:
	Graph();
	void createGraph(int);
	void addEdge(int, int, int);
	void displayGraph();
	void PrimMST();
	virtual ~Graph();
};

#endif
