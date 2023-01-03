#pragma once
#include<iostream>
#include<conio.h>

using namespace std;
template <class T>
class Node
{
public:
	T data;
	Node* next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(T d, Node* n)
	{
		setData(d);
		setNext(n);
	}

	Node(T d)
	{
		setData(d);
		next = NULL;

	}

	void setData(T d)
	{
		data = d;
	}

	void setNext(Node* n)
	{
		next = n->next;

	}

	T getData()
	{
		return data;
	}

	Node* getNext()
	{
		return this->next;
	}

};

template <class Q>

class Queue
{
public:

	Node<Q>* front;
	Node<Q>* rear;


	Queue()
	{
		front = NULL;
		rear = NULL;
	}


	bool isEnmpty() {
		if (front->next==NULL) {

			return true;
		}
		return false;

	}

	void enqueue(Q d) {

		Node<Q>* nod = new Node <Q>(d);


		if (front == NULL && rear == NULL) {

			front = nod;
			rear = nod;
		}
		else if (front != NULL || rear != NULL) {


			rear->next = nod;
			rear = rear->next;


		}





	}

	Q dequeue() {



		Node<Q>* temp;
		temp = front;
		Q data = front->data;
		if (!(front->next == NULL)) {
			front = front->next;
		}

		delete temp;

		return data;


	}



	Q retFront() {

		Q data = front->data;


		return data;


	}


	void print() {


		Node<Q>* temp;
		temp = front;

		cout << endl;
		while (1)
		{
			cout << temp->data << "  ";
			temp = temp->next;
			if (temp->next == NULL) {
				break;
			}

		}
		cout << temp->data << "  ";

	}




};

