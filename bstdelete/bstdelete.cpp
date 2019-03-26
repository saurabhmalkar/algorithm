// bst1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<tuple>
using namespace std;

struct node
{
	int val;
	node* left;
	node* right;
};

node* root = NULL;
node* newnode(int);
node* insertbst(node*, node*);
void inorder(node*);
void deletebst(node*,int);
tuple <node*, node*> pred(node*);
node* searchparent(node*, int);


int main()
{
	int value, n,key;
	node* tmp;
	cout << "enter the number of nodes" << endl;
	cin >> n;
	while (n > 0)
	{
		cout << "enter the value of " << n << "th node" << endl;
		cin >> value;
		node* tmp = newnode(value);
		insertbst(root, tmp);
		n--;
	}
	inorder(root);
	cout << endl;
	cout << "enter the value of the node you want to delete" << endl;
	cin >> key;
	tmp = searchparent(root, key);
	if (tmp != NULL)
	{
		cout << "parent:" << tmp->val;
		deletebst(tmp, key);
	}
	else
	{
		deletebst(root, key);
	}
	cout << "bst after deleting: " << key << endl;
	inorder(root);
	getchar();
	return 0;
}

node* newnode(int value)
{
	node* tmp = new node;
	tmp->val = value;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

node* insertbst(node* current, node* n)
{
	node* tmp1;
	if (root == NULL)
	{
		root = n;
		return 0;
	}
	if (current->val == n->val)
	{
		tmp1 = current->right;
		current->right = n;
		n->right = tmp1;
	}
	if (current->val > n->val)
	{
		if (current->left == NULL)
		{
			current->left = n;
			return 0;
		}
		else
		{
			insertbst(current->left, n);
		}
	}
	else
	{
		if (current->right == NULL)
		{
			current->right = n;
			return 0;
		}
		else
		{
			insertbst(current->right, n);
		}


	}
}

void inorder(node* n)
{
	if (n->left != NULL)
	{
		inorder(n->left);
	}
	cout << n->val << " ";
	if (n->right != NULL)
	{
		inorder(n->right);
	}
	return;

}

node* searchparent(node* n, int key)
{
	node* tmp;
	if (n == NULL) return NULL;
	if (n->val == key) return NULL;
	if (n->left != NULL)
	{
		
		
			if (n->left->val == key) return n;
		
	}
	if (n->right != NULL)
	{
		
			if (n->right->val == key) return n;
		
	}

	tmp = searchparent(n->left, key);
	if (tmp == NULL) tmp = searchparent(n->right, key);
	return tmp;
}

tuple<node*,node*> pred(node* n)
{
	node* predc;
	node* parents=NULL;
	predc = n->left;
	while (predc->right != NULL)
	{
		parents = predc;
		predc = predc->right;
	}
	return make_tuple(predc,parents);
}

void deletebst(node* n, int key)
{
	node* tmp;
	node* tmpl;
	node* tmp2;
	if (n->val == key)
	{
		tmpl = n;
		if (tmpl->left == NULL)
		{
			if (tmpl->right == NULL)
			{
				n = NULL;
			}
			else
			{
				n = tmpl->right;
			}
		}
		else
		{
			if (tmpl->right == NULL)
			{
				tie(tmp, tmp2) = pred(tmpl);
				n = tmp;
				if (tmpl->left != tmp) tmp->left = tmpl->left;
				tmp->right = tmpl->right;
				if (tmp2 != NULL) tmp2->right = NULL;

			}
			else
			{
				tie(tmp, tmp2) = pred(tmpl);
				n = tmp;
				if (tmpl->left != tmp) tmp->left = tmpl->left;
				tmp->right = tmpl->right;
				if (tmp2 != NULL) tmp2->right = NULL;
			}
		}
		root = n;
	}
	
	if (n->left != NULL)
	{
		if ((n->left)->val == key)
		{
			tmpl = n->left;
			if (tmpl->left == NULL)
			{
				if (tmpl->right == NULL)
				{
					n->left = NULL;
				}
				else
				{
					n->left = tmpl->right;
				}
			}
			else
			{
				if (tmpl->right == NULL)
				{
					tie(tmp, tmp2) = pred(tmpl);
					n->left = tmp;
					if (tmpl->left != tmp) tmp->left = tmpl->left;
					tmp->right = tmpl->right;
					if (tmp2 != NULL) tmp2->right = NULL;
				}
				else
				{
					tie(tmp, tmp2) = pred(tmpl);
					n->left = tmp;
					if (tmpl->left != tmp) tmp->left = tmpl->left;
					tmp->right = tmpl->right;
					if (tmp2 != NULL) tmp2->right = NULL;
				}
			}
		}
	}
	if (n->right != NULL)
	{
		if (n->right->val == key)
		{
			tmpl = n->right;
			if (tmpl->left == NULL)
			{
				if (tmpl->right == NULL)
				{
					n->right = NULL;
				}
				else
				{
					n->right = tmpl->right;
				}
			}
			else
			{
				if (tmpl->right == NULL)
				{
					tie(tmp, tmp2) = pred(tmpl);
					n->right = tmp;
					if (tmpl->left != tmp) tmp->left = tmpl->left;
					tmp->right = tmpl->right;
					if (tmp2 != NULL) tmp2->right = NULL;
				}
				else
				{
					tie(tmp, tmp2) = pred(tmpl);
					n->right = tmp;
					if (tmpl->left != tmp) tmp->left = tmpl->left;
					tmp->right = tmpl->right;
					if (tmp2 != NULL) tmp2->right = NULL;
				}
			}
		}
	}


}