#ifndef Graph_h_
#define Graph_h_

#include<iostream>
#include<iomanip>

using namespace std;

struct edge
{
	int source,destination;
	float weight;
};

class Graph
{
	float *adjMat;
	int vertices;
public:
	Graph();
	void createGraph(int);
	void addEdge(int,int,float);
	void displayGraph();
	void KruskalMST();
	void generateEdges(edge *,int &);
	void sortEdges(edge *,int);
	virtual ~Graph();
};

#endif
