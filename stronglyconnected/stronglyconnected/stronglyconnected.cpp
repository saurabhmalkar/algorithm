// stronglyconnected.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<queue>
using namespace std;
int dfs(int[10][10], int);

int visited[10] = {};
int main()
{
	int graph1_con,trans_con;
	graph1_con = trans_con = 0;
	int trans[10][10];
	int graph1[10][10] = { { 0,1,0,0,1,1,0,0,0,0 },
							{ 1,0,0,0,0,0,0,0,0,1 },
							{ 0,0,0,1,0,0,0,0,0,0 },
							{ 0,0,1,0,1,0,1,1,1,0 },
							{ 0,1,1,0,0,1,0,0,0,0 },
							{ 0,0,0,0,0,0,1,0,0,0 },
							{ 0,0,0,0,1,0,0,0,0,0 },
							{ 0,0,0,0,0,0,1,0,0,0 },
							{ 0,0,0,0,0,0,0,1,0,0 },
							{ 0,0,1,1,0,0,0,0,1,0 } };

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << " " << graph1[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "visited nodes:" << endl;
	dfs(graph1, 1 - 1);

	if (visited[0] == 1 && visited[1] == 1 &&
		visited[2] == 1 && visited[3] == 1 &&
		visited[4] == 1 && visited[5] == 1 &&
		visited[6] == 1 && visited[7] == 1 &&
		visited[8] == 1 && visited[9] == 1)
	{
		graph1_con = 1;
	}

	cout << endl;

	visited[0] = 0;
	visited[1] = 0;
	visited[2] = 0;
	visited[3] = 0;
	visited[4] = 0;
	visited[5] = 0;
	visited[6] = 0;
	visited[7] = 0;
	visited[8] = 0;
	visited[9] = 0;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			trans[j][i] = graph1[i][j];
		}
	}
	cout << endl;
	cout << "display transpose:" << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << " " << trans[i][j];
		}
		cout << endl;
	}
	cout << endl;


	cout << "visited nodes of the transpose:" << endl;
	dfs(trans, 0);


	if (visited[0] == 1 && visited[1] == 1 &&
		visited[2] == 1 && visited[3] == 1 &&
		visited[4] == 1 && visited[5] == 1 &&
		visited[6] == 1 && visited[7] == 1 &&
		visited[8] == 1 && visited[9] == 1)
	{
		trans_con = 1;
	}

	cout << endl;

	cout << "connectivity of graph: " << graph1_con<<endl;
	cout << "connectivity of transpose: " << trans_con<<endl;
	cout << endl;
	cout << endl;
	if (graph1_con == 1 && trans_con == 1) cout << "the given graph is strongly connected" << endl;
	else cout << "the given graph is not strongly connected" << endl;
    return 0;
}

int dfs(int g[10][10], int n)
{
	cout <<" "<< n+1;
	visited[n] = 1;
	for (int i = 0; i < 10; i++)
	{
		if (g[n][i] == 1)
		{
			if(visited[i]==0)
			{
				dfs(g, i);
			}
		}
	}
	return 0;
	

}

