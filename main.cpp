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
using namespace std;

struct Edge 
{
	char vertex1;
	char vertex2;
	int weight;
};

int main()
{  
	//read to n
	string tmpn;
	getline(cin,tmpn,' ');
	int n = atoi(tmpn.c_str());
	cout << "# of Nodes: " << n << "\n";
	
	//read to m
	string tmpm;
	getline(cin,tmpm);
	int m = atoi(tmpm.c_str());
	cout << "# of Edges: " << m << "\n";
	
	Edge e[m];
	
	//store m edges in array e
	for(int i = 0; i < m; i++)
	{
		int v1 = -1;
		int v2 = -1;
		int w = 0;
		string tmpv1;
		string tmpv2;
		string tmpw;
		
		getline(cin,tmpv1,' ');
		v1 = atoi(tmpv1.c_str());
		
		getline(cin,tmpv2,' ');
		v2 = atoi(tmpv2.c_str());
		
		getline(cin,tmpw);
		w = atoi(tmpw.c_str());
		
		e[i].vertex1 = v1;
		e[i].vertex2 = v2;
		e[i].weight = w;
	}
	
	for(int i = 0; i < m; i++)
	{
		cout << e[i].vertex1 << " " << e[i].vertex2 << " " << e[i].weight << "\n";
	}

	return 1;
}