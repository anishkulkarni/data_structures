#ifndef Graph_h_
#define Graph_h_

const int infinity = 32767;

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct edge
{
	int source, destination, weight;
};

class Graph
{
	int **adjMat;
	string *nodeNames;
	int vertices;
public:
	Graph();
	void createGraph(int);
	void addEdge(int, int, int);
	void displayGraph();
	void dijkstraShortestPath(int source = 0, int destination = -1);
	virtual ~Graph();
};

#endif
