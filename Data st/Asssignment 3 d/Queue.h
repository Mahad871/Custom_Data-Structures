#pragma once
#pragma once
#include<iostream>
using namespace std;

template <class T>
class QNode {
public:
	T data;
	QNode* next;

	QNode()
	{
		data = 0;
	}

	QNode(T D)
	{
		data = D;
		next = NULL;
	}



};


template<class T>
class Queue {
public:
	QNode<T>* front;
	QNode<T>* rear;
	int count;

	Queue()
	{
		front = NULL;
		rear = NULL;
		count = 0;
	}

	void Enqueue(T a)
	{
		QNode<T>* n = new QNode<T>(a);
		if (isEmpty())
		{
			front = n;
			rear = n;
			count++;
		}

		else
		{
			rear->next = n;
			rear = n;
			count++;
		}
	}

	T Dequeue()
	{
		if (!isEmpty())
		{
			T d = front->data;
			QNode<T>* n = front;
			if (front == rear)
			{
				front = NULL;
				rear = NULL;
				delete n;
				count--;
				return d;
			}
			else
			{
				front = front->next;
				delete n;
				count--;
				return d;
			}
		}


	}

	bool isEmpty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}

		return false;
	}

	T Front()
	{
		return front->data;
	}

	void print()
	{
		if (isEmpty())
		{
			cout << "The Queue is Empty\n";
			return;
		}

		QNode<T>* n = front;
		while (n)
		{
			cout << n->data << endl;
			n = n->next;
		}
	}

	T searchDequeue(T val)
	{
		int c = count;
		if (!isEmpty())
		{
			T d = front->data;
			QNode<T>* n = front;
			if (front == rear)
			{
				count--;
				front = NULL;
				rear = NULL;
				delete n;
				return d;
			}

			else
			{
				if (front->data == val)
				{
					count--;
					front = front->next;
					delete n;
					return d;
				}

				QNode<T>* parent = n;
				while (c != 0)
				{
					d = n->data;
					if (d == val)
					{
						count--;
						parent->next = n->next;
						delete n;
						return d;
					}
					parent = n;
					n = n->next;
					c--;
				}
			}
		}
	}


	bool citysearch(T C)
	{
		if (isEmpty())
		{
			return false;
		}

		else
		{
			int c = count;
			QNode<T>* n = front;
			while (c != 0)
			{
				if (n->data == C)
					return true;

				n = n->next;
				c--;
			}
			return false;
		}
	}

};
