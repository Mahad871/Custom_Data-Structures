#pragma once
#include<iostream>
#include<conio.h>


using namespace std;
template <class T>
class QNode
{
public:
	T data;
	QNode* next;

	QNode()
	{
		data = 0;
		next = NULL;
	}

	QNode(T d, QNode* n)
	{
		setData(d);
		setNext(n);
	}

	QNode(T d)
	{
		setData(d);
		next = NULL;

	}

	void setData(T d)
	{
		data = d;
	}

	void setNext(QNode* n)
	{
		next = n->next;

	}

	T getData()
	{
		return data;
	}

	QNode* getNext()
	{
		return this->next;
	}

};

template <class Q>

class Queue
{
public:

	QNode<Q>* front;
	QNode<Q>* rear;


	Queue()
	{
		front = NULL;
		rear = NULL;
	}


	bool isEnmpty() {
		if (front->next == NULL) {

			return true;
		}
		return false;

	}

	void enqueue(Q d) {

		QNode<Q>* nod = new QNode <Q>(d);


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



		QNode<Q>* temp;
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


		QNode<Q>* temp;
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