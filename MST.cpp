#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <sstream>
#include <climits>
#include <cmath>
#include <math.h>
#include <float.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
	string vertex1;
	string vertex2;
	int weight;
};

struct Graph 
{
	int* vertices;
	Edge* edges;
	int n;
	int m;
};

int* parent;
int* rank;

int find(int vertex) 
{
	if (parent[vertex] == vertex) 
		return parent[vertex];
	else
		return find(parent[vertex]);	
}

void Union(int root1, int root2)
{
	if(rank[root1] > rank[root2])
		parent[root2] = root1;
	else if(rank[root2] > rank[root1])
		parent[root1] = root2;
	else
	{
		parent[root1] = root2;
		rank[root2]++;
	}
}

void Reset(int vertex)
{
	parent[vertex] = vertex;
	rank[vertex] = 0;
}	

void Kruskal(Graph g)
{	
	vector<Edge> MST;
	int MSTweight = 0;

	parent = new int[g.n];
	rank = new int[g.n];

	for(int i = 0; i <= g.n; i++)
	{
		parent[i] = i;
		rank[i] = 0;
	}

	/*................tester
	for ( int i = 0; i <= g.n; i++) {
            cout << "Set: " << parent[i] << " Height: " << rank[i] << "\n";
        }*/

	for (int i = 0; i < g.m; i++)
	{
		Edge tmpe = g.edges[i];
		int tmpv1 = atoi(tmpe.vertex1.c_str());
		int tmpv2 = atoi(tmpe.vertex2.c_str());	
		int root1 = find(tmpv1);
		int root2 = find(tmpv2);
		if (root1 != root2) 
		{
			MSTweight = MSTweight + tmpe.weight;
			MST.push_back(tmpe);
			if (rank[root1] > rank[root2]) 
			{
				parent[root2] = root1;
				rank[root1]++;
				cout << "Edge (" << tmpe.vertex1 << "," << tmpe.vertex2 << ") successfully inserted" << "\n";
			} 
			else 
			{
				parent[root1] = root2;
				rank[root2]++;
				cout << "Edge (" << tmpe.vertex1 << "," << tmpe.vertex2 << ") successfully inserted" << "\n";
			}
		}
		else
			cout << "Edge (" << tmpe.vertex1 << "," << tmpe.vertex2 << ") creates cycle" << "\n";
	}

	if(MST.size() == g.n - 1)
	{		
		for (int i = 0; i < MST.size(); i++) 
		{
			cout << MST[i].vertex1 << " " << MST[i].vertex2 << endl;
		}
		cout << MSTweight << "\n";
	}
	else
		cout << "ERROR: MST not found" << "\n";
}

//prints current array of edges
void printGraph(Edge* e, int m, int n, int* v)
{
	cout << "# of Nodes: " << n << "\n";
	cout << "# of Edges: " << m << "\n";

	cout << "vertices: ";
	for(int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";	

	for(int i = 0; i < m; i++)
	{
		cout << e[i].vertex1 << " " << e[i].vertex2 << " " << e[i].weight << "\n";
	}
}

bool edgecompare(Edge lhs, Edge rhs)
{ 
	return lhs.weight < rhs.weight;
}

void sort(Edge* e, int m)
{
	sort(e, e + m, edgecompare);
}

int main()
{  
	Graph g;

	//read to n
	string tmpn;
	getline(cin,tmpn,' ');
	g.n = atoi(tmpn.c_str());

	//read to m
	string tmpm;
	getline(cin,tmpm);
	g.m = atoi(tmpm.c_str());	

	g.vertices = new int[g.n];

	for(int i = 0; i < g.n; i++)
	{
		int j = i + 1;
		g.vertices[i] = j;
	}

	g.edges = new Edge[g.m];	

	//store m edges in array e
	for(int i = 0; i < g.m; i++)
	{
		int w = 0;
		string tmpw;
	
		getline(cin, g.edges[i].vertex1,' ');
	
		getline(cin, g.edges[i].vertex2,' ');
	
		getline(cin,tmpw);
		w = atoi(tmpw.c_str());
		g.edges[i].weight = w;
	}

	sort(g.edges, g.m);

	//printGraph(g.edges, g.m, g.n, g.vertices);

	Kruskal(g);

	return 1;
}
