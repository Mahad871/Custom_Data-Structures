#pragma once
#include<iostream>
#include<conio.h>

using namespace std;
template <class T, class X>
class Node
{
public:
	T vertex;
	X edge;
	Node* next;

	Node()
	{
		vertex = 0;
		edge = 0;
		next = NULL;
	}

	Node(T d, X weight, Node* n)
	{
		setData(d, weight);
		setNext(n);
	}

	Node(T d, X weight)
	{
		setData(d, weight);
		next = NULL;

	}

	void setData(T d, X weight)
	{
		vertex = d;
		edge = weight;
	}

	void setNext(Node* n)
	{
		next = n->next;

	}

	T getVertex()
	{
		return vertex;
	}
	T getEdge()
	{
		return edge;
	}

	Node* getNext()
	{
		return this->next;
	}

};

template <class T, class X>
class SLinkedList {

public:

	Node<T, X>* head;


	SLinkedList()
	{
		head = NULL;
	}

	void insert(T d, X weight) {

		Node<T, X>* nod = new Node <T, X>(d, weight);
		Node<T, X>* temp;
		temp = head;

		while (1)
		{
			if (head == NULL) {

				head = nod;
				break;

			}
			else if (temp->next == NULL) {
				temp->next = nod;
				break;
			}
			else
			{
				temp = temp->next;

			}

		}


	}


	void insertAtHead(T d, X weight) {

		Node<T, X>* nod = new Node <T>(d, weight);
		nod->next = head;
		head = nod;

	}

	bool InsertAtIndex(T d, X weight, int ind) {


		Node<T, X>* nod = new Node <T>(d, weight);
		Node<T, X>* temp;
		temp = head;

		for (int i = 0; 1; i++)
		{

			if (i == ind) {
				nod->next = temp->next;
				temp->next = nod;
				return true;

			}

			if (temp->next == NULL) {
				return false;
			}
			else
			{
				temp = temp->next;

			}

		}


	}

	int searchVertex(T d) {

		Node<T, X>* temp;
		temp = head;

		int i = 0;
		for (i = 0; 1; i++)
		{

			if (temp->vertex == d) {
				return i;
			}

			if (temp->next == NULL) {
				return -1;
			}
			else
			{
				temp = temp->next;

			}

		}
		return -1;

	}

	int searchEdge(T d) {

		Node<T, X>* temp;
		temp = head;

		int i = 0;
		for (i = 0; 1; i++)
		{

			if (temp->edge == d) {
				return i;
			}

			if (temp->next == NULL) {
				return -1;
			}
			else
			{
				temp = temp->next;

			}

		}
		return -1;

	}

	bool updateVertex(int ind, T d) {

		Node<T, X>* temp;
		temp = head;

		for (int i = 0; 1; i++)
		{

			if (i == ind) {
				temp->vertex = d;
				return true;
			}

			if (temp->next == NULL) {
				return false;
			}
			else
			{
				temp = temp->next;

			}

		}

	}

	bool updateEdge(int ind, T d) {

		Node<T, X>* temp;
		temp = head;

		for (int i = 0; 1; i++)
		{

			if (i == ind) {
				temp->edge = d;
				return true;
			}

			if (temp->next == NULL) {
				return false;
			}
			else
			{
				temp = temp->next;

			}

		}

	}


	bool remove(int ind) {

		Node<T, X>* temp;
		Node<T, X>* del;
		temp = head;

		for (int i = 0; 1; i++)
		{

			if (i + 1 == ind) {
				del = temp->next;
				temp->next = temp->next->next;

				delete del;
				return true;

			}

			if (temp->next == NULL) {
				return false;
			}
			else
			{
				temp = temp->next;

			}

		}

	}

	void print() {

		Node<T, X>* temp;
		temp = head;

		int i = 0;
		cout << "( ";
		for (i = 0; temp; i++)
		{

			cout << temp->edge << " , " ;

			if (temp->next == NULL) {
				break;
			}
			else
			{
				temp = temp->next;

			}

		}

		cout << "\b)\n";

	}

	void mergeLists(SLinkedList obj2) {

		SLinkedList list;

		Node<T, X>* l1;
		l1 = head;
		Node<T, X>* l2;
		l2 = obj2.head;

		T arr[8] = { 0 };


		for (int i = 0; i < 4; i++)
		{
			arr[i] = l1->vertex;
			l1 = l1->next;


		}
		for (int i = 4; i < 8; i++)
		{
			arr[i] = l2->vertex;
			l2 = l2->next;


		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = i + 1; j < 8; j++)
			{
				if (arr[i] > arr[j]) {
					T temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}


		}

		for (int i = 0; i < 8; i++)
		{
			cout << arr[i];


		}

		for (int i = 0; i < 8; i++)
		{

			list.insert(arr[i]);

		}

		this->head = list.head;


	}



};