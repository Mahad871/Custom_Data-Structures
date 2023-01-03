//Mahad Saleem //i210485
//Syed Haseeb //i210823
//Mobin Kashif //i210874


#pragma once
#include <iostream>
#include <list>
#include <stack>
#include "Graph.h"
using namespace std;

template <class T>
class node
{
public:
	T val;
	node* next;

	node()
	{
		val = 0;
		next = NULL;
	}

	node(T d, node* n)
	{
		setval(d);
		setNext(n);
	}

	node(T d)
	{
		setval(d);
		next = NULL;

	}

	void setval(T d)
	{
		val = d;
	}

	void setNext(node* n)
	{
		next = n->next;

	}

	T getval()
	{
		return val;
	}

	node* getNext()
	{
		return this->next;
	}

};


template <class Q>

class Stack
{
public:

	node <Q>* top;
	int val;

	Stack()
	{
		top = NULL;
		val = 0;
	}

	void push(Q dataItem) {

		node<Q>* temp = new node<Q>();
		temp = top;
		node<Q>* nod = new node<Q>(dataItem);


		if (!(this->isEmpty())) {

			nod->next = top;
			top = nod;
			val++;

		}
		if (this->isEmpty()) {

			top = nod;
			val++;

		}





	}
	void pop() {

		node<Q>* temp = new node<Q>();
		temp = top;


		if (!(this->isEmpty())) {

			top = top->next;
			val--;

		}


		delete temp;


	}

	int valofStack() {


		return val;


	}

	void clear() {


		while (!(isEmpty()))
		{
			this->pop();

		}
	}

	void print() {
		node<Q>* temp = new node<Q>();
		temp = top;

		for (int i = 0; i < val; i++)
		{
			cout << " " << temp->val;
			if (temp->next != NULL) {

				temp = temp->next;
			}

		}

	}

	node<Q>* Peek() {


		return top;

	}

	bool isEmpty() {


		if (top == NULL || val == 0) {
			return true;
		}

		return false;

	}


	~Stack()
	{
		this->clear();
	}



};

template <class T>


class List {
public:
	T* values;
	int capacity;
	int counter;

	List(int capacity) {
		this->capacity = capacity;
		this->values = new T[capacity]{ 0 };

		this->counter = 0;
	}
	bool isEmpty() {
		return counter == 0;
	}
	bool isFull() {
		return counter == capacity;
	}
	bool insert(T item) {

		if (!isFull()) {

			this->values[counter] = item;
			counter++;
			return true;
		}

		return false;

	}
	bool insertAt(T item, int index) {




		if (index < this->capacity)
		{
			this->values[index] = item;
			return true;

		}
		return false;


	}

	bool insertAfter(T itemTobeInserted, T item) {


		List ar(this->capacity);


		if (isFull()) {


			return false;

		}

		for (int i = 0, j = 0; i < this->capacity; i++, j++)
		{
			if (this->values[i] == item)
			{
				i++;
				ar.values[i] = itemTobeInserted;
				i++;

			}
			ar.values[i] = this->values[j];
		}

		for (int i = 0; i < capacity; i++)
		{
			this->values[i] = ar.values[i];
			;
		}


	}
	bool insertBefore(T itemTobeInserted, T item) {


		List ar(this->capacity);


		if (isFull()) {


			return false;

		}

		for (int i = 0, j = 0; i < this->capacity; i++, j++)
		{
			if (this->values[i] == item)
			{

				ar.values[i] = itemTobeInserted;
				i++;

			}
			ar.values[i] = this->values[j];
		}

		for (int i = 0; i < capacity; i++)
		{
			this->values[i] = ar.values[i];
			;
		}


	}


	bool remove(T item) {


		if (isEmpty())
		{
			return false;
		}

		List ar(this->capacity);

		for (int i = 0, j = 0; i < capacity; i++)
		{
			if (this->values[i] == item)
			{
				continue;
			}
			ar.values[j] = this->values[i];
			j++;

		}

		for (int i = 0; i < capacity; i++)
		{


			this->values[i] = ar.values[i];


		}


	}

	bool removeAfter(T item) {


		if (isEmpty())
		{
			return false;
		}

		List ar(this->capacity);

		for (int i = 0, j = 0; i < capacity; i++)
		{
			if (this->values[i - 1] == item)
			{
				continue;
			}
			ar.values[j] = this->values[i];
			j++;

		}

		for (int i = 0; i < capacity; i++)
		{


			this->values[i] = ar.values[i];


		}

		print();

	}

	bool removeBefore(T item) {


		if (isEmpty())
		{
			return false;
		}

		List ar(this->capacity);

		for (int i = 0, j = 0; i < capacity; i++)
		{
			if (this->values[i + 1] == item)
			{
				continue;
			}
			ar.values[j] = this->values[i];
			j++;

		}

		for (int i = 0; i < capacity; i++)
		{


			this->values[i] = ar.values[i];


		}

		this->print();

	}


	bool operator==(List c) {

		for (int i = 0, j = 0; i < capacity; i++)
		{
			if (this->values[i] != c.values[i])
			{
				return false;
			}


		}

		return true;

	}


	void reverse() {


		List ar(this->capacity);

		for (int i = 0, j = capacity - 1; i < capacity; i++, j--)
		{

			ar.values[j] = this->values[i];


		}

		for (int i = 0; i < capacity; i++)
		{

			this->values[i] = ar.values[i];


		}


	}


	void print() {


		cout << "|";
		for (int i = 0; i < this->capacity; i++)
		{
			cout << values[i] << " ";
		}
		cout << "|";



	}


};



class Graph
{
	unsigned int V; 
	list<unsigned int>* adj;
	int size = 0;

	void fillOrder(unsigned int v, bool visited[], stack<unsigned int>& Stack);

	void DFSUtil(unsigned int v, bool visited[]);
public:
	Graph(unsigned int V);
	void addEdge(unsigned int v, unsigned int w);

	void printSCCs();

	Graph getTranspose();
};

Graph::Graph(unsigned int V)
{
	this->V = V;
	adj = new list<unsigned int>[V];
}

void Graph::DFSUtil(unsigned int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	size++;
	
	list<unsigned int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		list<unsigned int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			g.adj[*i].push_back(v);
		}
	}
	return g;
}

void Graph::addEdge(unsigned int v, unsigned int w)
{
	adj[v].push_back(w); 
}

void Graph::fillOrder(unsigned int v, bool visited[], stack<unsigned int>& Stack)
{
	visited[v] = true;

	list<unsigned int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			fillOrder(*i, visited, Stack);

	Stack.push(v);
}

void Graph::printSCCs()
{	
	int maxSize = 0;

	stack<unsigned int> Stack;

	bool* visited = new bool[V];

	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			fillOrder(i, visited, Stack);

	Graph gr = getTranspose();

	for (int i = 0; i < V; i++)
		visited[i] = false;

	while (!Stack.empty())
	{
		unsigned int v = Stack.top();
		Stack.pop();

		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
			cout<<"|  Size: "<< gr.size << endl;
			if (maxSize < gr.size) {
				maxSize = gr.size;
			}
			gr.size = 0;

		}
	}


	cout << "\nSize of Largest SCC is: " << maxSize;

}