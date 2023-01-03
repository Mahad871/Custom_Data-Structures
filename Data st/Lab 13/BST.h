#pragma once
#include <iostream>
#include <queue>

using namespace std;

template <class T>

class Node
{
public:
	T data;
	Node* left;
	Node* right;

	Node()
	{
		data = NULL;
		left = NULL;
		right = NULL;
	}

	Node(T d, Node* l, Node* r)
	{
		setData(d);
		setLeft(l);
		setRight(r);
	}

	Node(T d)
	{
		setData(d);
		left = NULL;
		right = NULL;

	}

	void setData(T d)
	{
		data = d;
	}

	void setLeft(Node* n)
	{
		left = n;

	}void setRight(Node* n)
	{
		right = n;

	}

	T getData()
	{
		return data;
	}

	Node* getLeft()
	{
		return this->left;
	}
	Node* getRight()
	{
		return this->right;
	}

};


template <class T>

class BSTree
{
public:

	Node<T>* root;


	BSTree() {
		root = new Node<T>;
		root->data = NULL;

	}

	void insert(T d) {

		Node<T>* n = new Node<T>(d);
		Node<T>* temp = new Node<T>;


		if (root->data == NULL) {
			root = n;
		}
		else
		{
			temp = root;
			while (1)
			{
				if (n->data < temp->data) {

					if (temp->left == NULL) {
						temp->left = n;
						break;
					}
					else
					{
						temp = temp->left;
					}


				}
				else if (n->data > temp->data)
				{
					if (temp->right == NULL) {
						temp->right = n;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
				else
				{
					break;
				}

			}

		}


	}


	void insertNode(Node<T>* d) {

		Node<T>* n = d;
		Node<T>* temp = new Node<T>;


		if (root->data == NULL) {
			root = n;
		}
		else
		{
			temp = root;
			while (1)
			{
				if (n->data < temp->data) {

					if (temp->left == NULL) {
						temp->left = n;
						break;
					}
					else
					{
						temp = temp->left;
					}


				}
				else if (n->data > temp->data)
				{
					if (temp->right == NULL) {
						temp->right = n;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
				else
				{
					break;
				}

			}

		}


	}

	bool retrieve(T d) {


		Node<T>* temp = new Node<T>;
		temp = root;



		while (temp)
		{
			if (temp->data == d) {
				cout << "!!! Found : )\n";
				return true;
			}
			if (d < temp->data) {
				temp = temp->left;
			}
			else if (d > temp->data)
			{
				temp = temp->right;

			}
		}
		cout << "!!! NOT Found : (\n";
		return false;
	}

	void preorder(Node<T>* p) {

		if (p != NULL)
		{
			cout << p->data << " ";
			preorder(p->left);
			preorder(p->right);
		}
	}

	T getMin(bool isLeft = true) {

		Node<T>* temp;
		temp = root;
		T ans = temp->data;

		while (temp != NULL) {

			if (isLeft) {

				ans = temp->data;
				temp = temp->left;
			}
			else
			{
				ans = temp->data;
				temp = temp->right;
			}

		}
		return ans;
	}

	void deleteData(T d) {

		Node<T>* temp = new Node<T>;
		Node<T>* prev = new Node<T>;
		temp = root;
		T ans{};
		bool success = false;

		cout << "\n";
		if (!retrieve(d)) {
			return;
		}

		while (1) {

			prev = temp;

			if (d < temp->data) {
				prev = temp;
				temp = temp->left;
			}
			else
			{
				prev = temp;
				temp = temp->right;
			}

			if (temp->data == d) {

				//prev = NULL;
				if (temp->left == NULL && temp->right == NULL) {
					if (d < prev->data) {
						prev->left = NULL;
						delete temp;
					}
					else
					{
						delete prev->right;
						prev->right = NULL;
					}
				}
				else if (temp->left == NULL && temp->right != NULL || temp->left != NULL && temp->right == NULL)
				{
					if (temp->left != NULL) {
						if (d < prev->data) {
							prev->left = temp->right;
							delete temp;
						}
						else
						{
							prev->right = temp->left;
							delete temp;
						}
					}
				}
				else
				{
					T ans= getMin(false);
					deleteData(getMin(false));
					temp->data = ans;
					temp->right = NULL;
				}
				break;

			}

		}


	}

	void levelOrder(Node<T>* p) {

		queue<Node<T>*> q;
		q.push(p);
		Node<T>* temp;
		temp = q.front();

		while (!q.empty()) {

			temp = q.front();
			cout << " " << temp->data << " ";
			if (temp->left != NULL) {
				q.push(temp->left);

			}
			if (temp->right != NULL) {
				q.push(temp->right);

			}
			q.pop();

		}


	}
	void inorder(Node<T>* ptr) {
		if (ptr != NULL)
		{
			inorder(ptr->left);
			cout << ptr->data << " ";
			inorder(ptr->right);
		}
	}







};


