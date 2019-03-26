// primeno.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int num,rem;
	int n=2;
	cout<<"enter the number\n";
	cin>>num;
	while(n<num)
	{ 
		rem=num%n;
		if(rem==0) 
			{
				cout<<num<<" is not a prime number";
				return 0;
			}
		
		else n++;
	}
	cout<<num<<" is a prime number";


	return 0;
}

