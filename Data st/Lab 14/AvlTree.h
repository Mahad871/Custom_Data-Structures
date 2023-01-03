#pragma once
#include<iostream>
using namespace std;
class Node
{
public:
	int height;
	int key;
	Node* left;
	Node* right;
	Node(int x = 0) {
		key = x;
		height = -1;
		left = NULL;
		right = NULL;
	}

private:

};
class AVL
{
public:
	Node* root;
	AVL()
	{
		root = NULL;
	}
	//Getting The Height Of The Node
	int getheight(Node* m)
	{
		if (m == NULL)
		{
			return -1;
		}
		return m->height;
	}
	// 
	int getbalance(Node* m)
	{
		if (m == NULL)
		{
			return -1;
		}
		return (getheight(m->left) - getheight(m->right));
	}
	int getmax(int a, int b)
	{
		return (a > b) ? a : b;
	}
	Node* insert(int element, Node* t)
	{
		///////////////
		//Empty Tree
		if (t == NULL)
		{
			t = new Node(element);
		}
		//////////////////////////////
		else if (element < t->key) {
			t->left = insert(element, t->left);
			if (getheight(t->left) - getheight(t->right) == 2)
			{
				if (element < t->left->key)
				{
					t = RRRot(t);
				}
				else {
					t = RLRot(t);
				}
			}
		}
		else if (element > t->key) {
			t->right = insert(element, t->right);
			if (getheight(t->left) - getheight(t->right) == -2)
			{
				if (element > t->right->key)
				{
					t = LLRot(t);
				}
				else {
					t = LRRot(t);
				}
			}
		}
		t->height = getmax(getheight(t->left), getheight(t->right)) + 1;

		return t;
	}



	//single rotation with right
	Node* LLRot(Node* r)
	{
		Node* n = new Node();
		n = r->right;
		r->right = n->left;
		n->left = r;
		r->height = getmax(getheight(r->left), getheight(r->right)) + 1;
		n->height = getmax(getheight(n->left), getheight(n->right)) + 1;
		return n;
	}
	//single rotation with left
	Node* RRRot(Node* r)
	{
		Node* n = new Node();
		n = r->left;
		r->left = n->right;
		n->right = r;
		r->height = getmax(getheight(r->left), getheight(r->right)) + 1;
		n->height = getmax(getheight(n->left), getheight(n->right)) + 1;
		return n;
	}
	// Double roation with right
	Node* LRRot(Node* r)
	{
		//RR rotation
		r->right = LLRot(r->right);
		//LL rotation
		return RRRot(r);
	}
	// Double rotation with left
	Node* RLRot(Node* r)
	{
		//LL Rotation
		r->left = RRRot(r->left);
		//RR Rotation
		return LLRot(r);
	}
	void preordertraversal(Node* m)
	{
		if (m != NULL)
		{
			cout << m->key << "  ";
			preordertraversal(m->left);
			preordertraversal(m->right);
		}
	}

private:

};





//