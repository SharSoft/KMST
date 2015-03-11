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

	//................tester
	for ( int i = 0; i <= g.n; i++) {
            cout << "Set: " << parent[i] << " Height: " << rank[i] << "\n";
        }

	for (int i = 0; i < g.m; i++)
	{
		Edge tmp = g.edges[i];	
		/*int root1 = find(tmp.vertex1);
		int root2 = find(tmp.vertex2);
		if (root1 != root2) 
		{
			MSTweight = MSTweight + e.weight;
			MST.push_back(e);
			if (rank[root1] > rank[root2]) 
			{
				Kset.parent[root2] = root1;
				Kset.rank[root1]++;
				cout << "Edge (" << e.vertex1 << "," << e.vertex2 << ") successfully inserted" << "\n";
			} 
			else 
			{
				Kset.parent[root1] = root2;
				Kset.rank[root2]++;
				cout << "Edge (" << e.vertex1 << "," << e.vertex2 << ") successfully inserted" << "\n";
			}
		}
		else
			cout << "Edge (" << g.e.vertex1 << "," << g.e.vertex2 << ") creates cycle" << "\n";
	*/}

	/*for (Edge e : MST) 
	{
		cout << e.vertex1 << " " << e.vertex2 << endl;
	}*/
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

	printGraph(g.edges, g.m, g.n, g.vertices);

	Kruskal(g);

	return 1;
}
