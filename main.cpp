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
};

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
	//read to n
	string tmpn;
	getline(cin,tmpn,' ');
	int n = atoi(tmpn.c_str());
	
	//read to m
	string tmpm;
	getline(cin,tmpm);
	int m = atoi(tmpm.c_str());	

	Graph g;

	g.vertices = new int[n];

	for(int i = 0; i < n; i++)
	{
		int j = i + 1;
		g.vertices[i] = j;
	}

	g.edges = new Edge[m];	
	
	//store m edges in array e
	for(int i = 0; i < m; i++)
	{
		int w = 0;
		string tmpw;
		
		getline(cin, g.edges[i].vertex1,' ');
		
		getline(cin, g.edges[i].vertex2,' ');
		
		getline(cin,tmpw);
		w = atoi(tmpw.c_str());
		g.edges[i].weight = w;
	}
	
	sort(g.edges, m);
	
	printGraph(g.edges, m, n, g.vertices);

	return 1;
}
