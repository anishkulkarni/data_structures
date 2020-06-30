#ifndef Graph_cpp_
#define Graph_cpp_

#include "Graph.h"

using namespace std;

Graph::Graph()
{
	adjMat = NULL;
	vertices = 0;
	nodeNames = NULL;
}

void Graph::createGraph(int no)
{
	int i = 0, j = 0;
	vertices = no;
	adjMat = new int[no*no];
	for (i = 0; i < vertices; i++)
		for (j = 0; j < vertices; j++)
			*(adjMat + i * (vertices)+j) = -1;
	nodeNames = new string[vertices];
	for (i = 0; i < vertices; i++)
	{
		cout << "Name of node: " << i << " is: ";
		cin >> nodeNames[i];
	}
}

void Graph::addEdge(int v1, int v2, int weight)
{
	*(adjMat + (v1)*(vertices)+v2) = weight;
	*(adjMat + (v2)*(vertices)+v1) = weight;
}

void Graph::displayGraph()
{

	for (int i = 0; i <= vertices; i++)
		cout << "-------------";
	cout << "-";
	cout << endl;
	cout << "| " << setw(10) << "Cities";
	for (int i = 0; i < vertices; i++)
		cout << " | " << setw(10) << nodeNames[i];
	cout << " |" << endl;
	for (int i = 0; i < vertices; i++)
	{
		for (int i = 0; i <= vertices; i++)
			cout << "-------------";
		cout << "-";
		cout << endl;
		cout << "| " << setw(10) << nodeNames[i];
		for (int j = 0; j < vertices; j++)
			cout << " | " << setw(10) << *(adjMat + i * (vertices)+j);
		cout << " |" << endl;
	}
	for (int i = 0; i <= vertices; i++)
		cout << "-------------";
	cout << "-";
	cout << endl << endl;
}

void Graph::PrimMST()
{
	int i = 0, j = 0, k=0, minCost = 0, current = 0, edgeCount = 0, next = 0, treeCost = 0;
	int *cost = new int[vertices*vertices];
	bool *visited = new bool[vertices];
	int *distance = new int[vertices];
	int *parent = new int[vertices];
	edge *treeMat = new edge[vertices-1];
	for (i = 0; i < vertices; i++)
	{
		for (j = 0; j < vertices; j++)
		{
			if (*(adjMat + i * vertices + j) == -1)
				*(cost + i * vertices + j) = 32767;
			else
				*(cost + i * vertices + j) = *(adjMat + i * vertices + j);
		}
	}
	for (i = 0; i < vertices; i++)
		cout << endl << i << ": " << nodeNames[i];
	cout << endl << "Enter the number of the city to start from: ";
	cin >> current;
	for (i = 0; i < vertices; i++)
	{
		visited[i] = 0;
		distance[i] = *(cost + current * vertices + i);
		parent[i] = current;
	}
	edgeCount = 0;
	visited[current] = 1;
	while (edgeCount < vertices - 1)
	{
		cout<<endl<<"--------------------------------------------------------------";
		cout<<endl<<"|       Node       |     Parent     | Visited |   Distance   |";
		cout<<endl<<"--------------------------------------------------------------";
		for(i=0;i<vertices;i++)
		{
			cout<<endl<<"| "<<setw(16)<<nodeNames[i]<<" | "<<setw(14)<<nodeNames[parent[i]]<<" | "<<setw(7)<<visited[i]<<" | "<<setw(12)<<distance[i]<<" |";
			cout<<endl<<"--------------------------------------------------------------";
		}
		minCost = 32767;
		for (i = 0; i < vertices; i++)
		{
			if (!visited[i] && minCost > distance[i])
			{
				minCost = distance[i];
				next = i;
			}
		}
		treeMat[k].source = parent[next];
		treeMat[k].destination = next;
		treeMat[k].weight = distance[next];
		cout<<endl<<"Edge added is: "<<nodeNames[parent[next]]<<" to "<<nodeNames[next]<<" with weight: "<<distance[next];
		k++;
		treeCost += distance[next];
		current = next;
		visited[current] = true;
		edgeCount++;
		for (i = 0; i < vertices; i++)
		{
			if (distance[i] > *(cost + current * vertices + i))
			{
				distance[i] = *(cost + current * vertices + i);
				parent[i] = current;
			}
		}
	}
	cout << endl << "The minimum spanning tree consists of following edges: ";
	cout << endl << "----------------------------------------------";
	cout << endl << "|     Source      |   Destination   | Weight |";
	cout << endl << "----------------------------------------------";
	for (i = 0; i < vertices - 1; i++)
	{
		cout << endl << "| " << setw(15) << nodeNames[treeMat[i].source] << " | " << setw(15) << nodeNames[treeMat[i].destination] << " | " << setw(6) << treeMat[i].weight << " |";
		cout << endl << "----------------------------------------------";
	}
	cout << endl << "Weight of the spanning tree is: " << treeCost;
	delete treeMat;
}

Graph::~Graph()
{
	if (adjMat != NULL)
		delete adjMat;
}

#endif
