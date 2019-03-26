// bfsgraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <queue>
using namespace std;



int main()
{
	int temp = 0;
	int graph1[10][10] = { {0,1,0,0,1,1,0,0,0,0},
						{1,0,0,0,0,0,0,0,0,1},
						{0,0,0,1,0,0,0,0,0,0},
						{0,0,1,0,1,0,1,1,1,0},
						{0,1,1,0,0,1,0,0,0,0},
						{0,0,0,0,0,0,1,0,0,0},
						{0,0,0,0,1,0,0,0,0,0},
						{0,0,0,0,0,0,1,0,0,0},
						{0,0,0,0,0,0,0,1,0,0},
						{0,0,1,1,0,0,0,0,1,0} };
	int visited[10] = {};
	for (int i= 0; i<10; i++) 
	{
		for (int j= 0; j<10; j++)
		{
			cout <<" "<<graph1[i][j]; 
		}
		cout << endl;
	}

	queue<int> myqueue;
	myqueue.push(1);
	visited[0] = 1;
	int k = 0;
	do
	{
		for ( int j=0; j < 10; j++)
		{
			if (graph1[k][j] == 1)
			{
				if (visited[j] == 0)
				{
					myqueue.push(j + 1);
					visited[j] = 1;
				}
			}
		}
			cout << "visited node" << myqueue.front() << endl;
			
			myqueue.pop();

			if (!myqueue.empty()) k = myqueue.front() - 1;
		if(visited[0]==1&& visited[1] == 1 && 
			visited[2] == 1 && visited[3] == 1 &&
			visited[4] == 1 && visited[5] == 1 &&
			visited[6] == 1 && visited[7] == 1 &&
			visited[8] == 1 && visited[9] == 1 )
		{
			if (myqueue.empty()) break;
		}
	} while (!myqueue.empty());
	
	cout << "\nvisited array" << endl;
	for (int i=0;i<10;i++)
	{
		cout << " " << visited[i];
	}
    return 0;
}

