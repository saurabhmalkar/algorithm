// stronglyconnected.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<queue>
using namespace std;

int nextind(int[10]);


bool visited[10] = { false,false,false,false,false,false,false,false,false,false };

int main()
{
	int node;
	int graph1[10][10] = { { 0,10,0,0,3,2,0,0,0,0 },
						   { 10,0,0,0,6,0,0,0,0,5},
						   { 0,0,0,7,9,0,0,0,0,8 },
						   { 0,0,7,0,4,0,8,10,5,6},
						   { 3,6,9,4,0,5,9,0,0,0 },
						   { 2,0,0,0,5,0,4,0,0,0 },
						   { 0,0,0,8,9,4,0,15,0,0 },
						   { 0,0,0,10,0,0,15,0,11,0 },
						   { 0,0,0,5,0,0,0,11,0,5 },
						   { 0,5,8,6,0,0,0,0,5,0 } };
	
	int parent[10] = {};
	int distance[10] = { 999,999,999,999,999,999,999,999,999,999 };
	parent[0] = -1;
	distance[0] = 0;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "   " << graph1[i][j];
		}
		cout << endl;
	}
	cout << endl;
	int m = 0;
	int i = 0;
	while(i!=-1)
	{
		node = nextind(distance);
		visited[node] = 1;
		i = node;

		for (int j = 0; j < 10; j++)
		{
			if (graph1[i][j] > 0 && visited[j] == false)
			{
				if (graph1[i][j] < distance[j])
				{
					parent[j] = i;
					distance[j] = graph1[i][j];
					m++;
				}
			}
		}
		
		if (visited[0] == 1 && visited[1] == 1 && visited[2] == 1 && visited[3] == 1 && visited[4] == 1 &&
			visited[5] == 1 && visited[6] == 1 && visited[7] == 1 && visited[8] == 1 && visited[9] == 1)
		{
			i = -1;
		}
 }
	cout << endl;
	cout << "node       visited          distance            parent           " << endl;
	for (int k = 0; k < 10; k++)
	{
		cout << k << "              " << visited[k] << "             " << distance[k] << "                  " << parent[k]+1 << endl;
	}

	return 0;
}


int nextind(int distance[10])
{
	int distanceMin = 1000;
	int ind;
	for (int n = 0; n < 10; n++)
	{
		if (visited[n] == false&&distance[n] <distanceMin)
		{
			distanceMin = distance[n];
			ind = n;
		}
	}
	return ind;
}
