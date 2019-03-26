// linklistrec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
};

node* head=NULL;
node* last=NULL;
node* insertnode(node* &head,node* &last,int n);
int display(node* head);
node* selsort(node* head,int n);

int main()
{
	int n;
	cout<<"enter the no of nodes"<<endl;
	cin>>n;
	int n1=n;
	insertnode(head,last,n);
	cout<<"list is"<<endl;
	display(head);
	head=selsort(head ,n1);
	display(head);
	getchar();
	return 0;
}

node* insertnode(node* &head,node* &last,int n)

{
	int info;
	node* tmp;
	if(n==0) return head;
	cout<<"enter value";
	cin>>info;
	if(head==NULL)
	{
	tmp=new node;
	tmp->data=info;
	tmp->next=0;
	tmp->prev=0;
	head=tmp;
	last=tmp;
	}
	else
	{
		tmp=new node;
		tmp->data=info;
		tmp->next=0;
		tmp->prev=last;
		last->next=tmp;
		last=tmp;
	}
	n--;
	insertnode(head,last,n);
	return head;
}
	
int display(node* head)
	{

		node* temp=head;
		if(temp==0) 
			{
				
				return 0;
		}
		else
		{
			
				cout<<temp->data<<endl;
				temp=temp->next;
				display(temp);
		}
		return 0;
	}
	
node* selsort(node* head,int n)
{
	int n1=n;
	int n2=n-1;
	node* tmp=head;
	node* tmp2=tmp->next;
	node* prv;
	node* nxt;
	while(n1>0)
	{
		while(n2>0)
		{
		if((tmp->data) > (tmp2->data))
		{
			if(tmp==head)
			{

				head=tmp2;
				tmp->prev=tmp2;
				tmp->next=tmp2->next;
				tmp2->next=tmp;
				tmp2->prev=0;
				tmp=tmp2;
				tmp2=tmp->next;
			}
			else
			
			{
				prv=tmp->prev;
				nxt=tmp->next;
				tmp->prev=tmp2->prev;
				tmp->next=tmp2->next;
				tmp2->next=nxt;
				tmp2->prev=prv;
				tmp=tmp2;
				tmp2=tmp2->next;
			}
		}
		n2--;
		cout<<"list is"<<endl;
		display(head);
		}
		tmp=tmp->next;
		if(tmp->next->next==0){return head;}
		tmp2=tmp->next->next;
		n1--;
	}
	return head;
}
