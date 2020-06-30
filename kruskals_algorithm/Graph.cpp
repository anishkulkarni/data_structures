#ifndef Graph_cpp_
#define Graph_cpp_

#include "Graph.h"



Graph::Graph()
{
	adjMat = NULL;
	vertices=0;
}

void Graph::createGraph(int no)
{
	vertices = no;
	adjMat = new float[no*no];
	for (int i = 0; i < vertices; i++)
		for (int j = 0; j < vertices; j++)
			*(adjMat + i * (vertices) + j) = -1;
}

void Graph::addEdge(int v1, int v2,float weight)
{
	*(adjMat + (v1)*(vertices) + v2) = weight;
	*(adjMat + (v2)*(vertices) + v1) = weight;
}

void Graph::displayGraph()
{

	for (int i = 0; i <= vertices; i++)
		cout << "----------";
	cout << endl;
	cout << "          ";
	for (int i = 0; i < vertices; i++)
		cout << setw(10) << i ;
	cout << endl;
	for (int i = 0; i < vertices; i++)
	{
		for (int i = 0; i <= vertices; i++)
			cout << "----------";
		cout << endl;
		cout << setw(10) << i ;
		for (int j = 0; j < vertices; j++)
			cout << setw(10) << *(adjMat + i * (vertices) + j);
		cout << endl;
	}
	for (int i = 0; i <= vertices; i++)
		cout << "----------";
	cout << endl << endl;
}

void Graph::generateEdges(edge *edgeMat,int &k)
{
	int i=0,j=0;
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<i;j++)
		{
			if(*(adjMat+i*vertices+j)!=0-1)
			{
				edgeMat[k].source=i;
				edgeMat[k].destination=j;
				edgeMat[k].weight=*(adjMat+i*vertices+j);
				k++;
			}
		}
	}
}

void Graph::sortEdges(edge *edgeMat,int edgeTotal)
{
	int i=0,j=0;
	for(i=0;i<edgeTotal;i++)
	{
		for(j=i+1;j<edgeTotal;j++)
		{
			if(edgeMat[i].weight>edgeMat[j].weight)
			{
				edge temp;
				temp.destination=edgeMat[i].destination;
				temp.source=edgeMat[i].source;
				temp.weight=edgeMat[i].weight;
				edgeMat[i].destination=edgeMat[j].destination;
				edgeMat[i].source=edgeMat[j].source;
				edgeMat[i].weight=edgeMat[j].weight;
				edgeMat[j].destination=temp.destination;
				edgeMat[j].source=temp.source;
				edgeMat[j].weight=temp.weight;
			}
		}
	}
}

void Graph::KruskalMST()
{
	int i=0,j=0,k=0,edgeCount=0,edgeTotal=0,edgeMax=(vertices*(vertices-1))/2,v1=0,v2=0,c[vertices];
	float cost=0;
	edge *edgeMat, *treeMat;
	edgeMat=new edge[edgeMax];
	treeMat=new edge[vertices-1];
	generateEdges(edgeMat,edgeTotal);
	cout<<endl<<"total edges = "<<edgeTotal;
	cout<<endl<<"Before sorting: ";
	for(i=0;i<edgeTotal;i++)
		cout<<endl<<"\t"<<edgeMat[i].source<<"\t"<<edgeMat[i].destination<<"\t"<<edgeMat[i].weight;
	sortEdges(edgeMat,edgeTotal);
	cout<<endl<<"After sorting: ";
	for(i=0;i<edgeTotal;i++)
		cout<<endl<<"\t"<<edgeMat[i].source<<"\t"<<edgeMat[i].destination<<"\t"<<edgeMat[i].weight;
	for(i=0;i<vertices;i++)
		c[i]=i;
	i=0,j=0;
	while(edgeCount<vertices-1)
	{
		v1=c[edgeMat[i].source];
		v2=c[edgeMat[i].destination];
		if(v1!=v2)
		{
			cost+=edgeMat[i].weight;
			treeMat[j].source=edgeMat[i].source;
			treeMat[j].destination=edgeMat[i].destination;
			treeMat[j].weight=edgeMat[i].weight;
			j++;
			edgeCount++;
		}
		for(k=0;k<vertices;k++)
			if(c[k]==v2)
				c[k]=v1;
		i++;
	}
	cout<<endl<<"The minimum spanning tree consists of following edges: ";
	cout<<endl<<"-------------------------------------";
	cout<<endl<<"| Source | Destination |   Weight   |";
	cout<<endl<<"-------------------------------------";
	for(i=0;i<vertices-1;i++)
	{
		cout<<endl<<"| "<<setw(6)<<treeMat[i].source<<" | "<<setw(11)<<treeMat[i].destination<<" | "<<setw(10)<<treeMat[i].weight<<" |";
		cout<<endl<<"-------------------------------------";
	}
	cout<<endl<<"Weight of the spanning tree is: "<<cost;
}

Graph::~Graph()
{
	if(adjMat!=NULL)
		delete adjMat;
}

#endif
