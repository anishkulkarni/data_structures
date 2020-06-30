#ifndef Graph_cpp_
#define Graph_cpp_

#include "Graph.h"
#include<stack>

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
	adjMat = new int*[no];
	for (i = 0; i < vertices; i++)
		adjMat[i] = new int[vertices];
	nodeNames = new string[vertices];
	for (i = 0; i < vertices; i++)
		for (j = 0; j < vertices; j++)
			adjMat[i][j] = -1;
	for (i = 0; i < vertices; i++)
	{
		cout << "Name of node: " << i << " is: ";
		cin >> nodeNames[i];
	}
}

void Graph::addEdge(int v1, int v2, int weight)
{
	adjMat[v1][v2]= weight;
	adjMat[v2][v1] = weight;
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
			cout << " | " << setw(10) << adjMat[i][j];
		cout << " |" << endl;
	}
	for (int i = 0; i <= vertices; i++)
		cout << "-------------";
	cout << "-";
	cout << endl << endl;
}

void Graph::dijkstraShortestPath(int source, int destination)
{
	int i = 0, j = 0, current = source, vertexCount = 1, next = -1, minCost = 0, sourceCount = 0;
	stack<int> s;
	bool *visited = new bool[vertices];
	int *distance = new int[vertices];
	int *parent = new int[vertices];
	int **cost = new int *[vertices];
	for (i = 0; i < vertices; i++)
		cost[i] = new int[vertices];
	for (i = 0; i < vertices; i++)
		for (j = 0; j < vertices; j++)
			if (adjMat[i][j] == -1)
				cost[i][j] = infinity;
			else
				cost[i][j] = adjMat[i][j];
	if (source == -1)
	{
		source = 0;
		sourceCount = 0;
	}
	else
		sourceCount = vertices - 1;
	while (sourceCount < vertices)
	{
		current = source;
		vertexCount = 1;
		next = -1;
		cout << endl << "Computing shortest paths from source: " << source;
		for (i = 0; i < vertices; i++)
		{
			visited[i] = false;
			distance[i] = cost[current][i];
			parent[i] = current;
		}
		visited[current] = true;
		while (vertexCount < vertices)
		{
			minCost = infinity;
			for (i = 0; i < vertices; i++)
			{
				if (!visited[i] && distance[i] < minCost)
				{
					minCost = distance[i];
					next = i;
				}
			}
			j = next;
			while (parent[j] != source)
			{
				s.push(j);
				j = parent[j];
			}
			s.push(j);
			s.push(parent[j]);
			cout << endl << "The shortest path from " << nodeNames[source] << " to " << nodeNames[next] << " is: ";
			while (!s.empty())
			{
				cout << " - " << nodeNames[s.top()];
				s.pop();
			}
			cout << " with weight: " << distance[next];
			current = next;
			visited[current] = true;
			for (i = 0; i < vertices; i++)
			{
				if (distance[i] > distance[current] + cost[current][i])
				{
					distance[i] = distance[current] + cost[current][i];
					parent[i] = current;
				}
			}
			if (current == destination)
				break;
			vertexCount++;
		}
		sourceCount++;
		source++;
	}
}

Graph::~Graph()
{
	if (adjMat != NULL)
		delete adjMat;
}

#endif
