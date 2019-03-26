// fiborec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void fiborecc(int,int,int);

int main()
{
	int n, f1,f2;
	f1=0;
	f2=1;
	cout<<"enter the limit\n";
	cin>>n;
	n-=3;
	cout<<f1<<' '<<f2;
	fiborecc(n,f1,f2);
	return 0;
}

void fiborecc(int n,int f1,int f2)
{
	int f3;
	f3=f1+f2;
	cout<<' '<<f3;
	f1=f2;
	f2=f3;
	
	if (n<=0) return ;
	else
	{
		return fiborecc(--n,f1,f3);
	}

}
