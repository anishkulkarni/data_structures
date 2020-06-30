#include <iostream>

#include"Graph.h"

using namespace std;

int main()
{
	Graph graph;
	int choice;
	while (1)
	{
		cout << "Menu\n1. Create Graph\n2. Display Graph\n3. Add edge\n4. Display MST using Kruskal's algorithm\n5. Exit\nChoice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int v;
			do
			{
				cout<<endl<<"Enter number of vertices in graph: ";
				cin>>v;
				if(v<0)
					cout<<"";
			}while(v<0);
			graph.createGraph(v);
			cout<<endl<<endl;
			break;
		case 2:
			graph.displayGraph();
			cout<<endl<<endl;
			break;
		case 3:
		{
			int v1,v2;
			float weight;
			cout<<endl<<"Enter first vertex: ";
			cin>>v1;
			cout<<endl<<"Enter second vertex: ";
			cin>>v2;
			cout<<endl<<"Enter weight: ";
			cin>>weight;
			graph.addEdge(v1,v2,weight);
			cout<<endl<<endl;
			break;
		}
		case 4:
			graph.KruskalMST();
			cout<<endl<<endl;
			break;
		case 5:
			return 0;
			break;
		}
	}
}
