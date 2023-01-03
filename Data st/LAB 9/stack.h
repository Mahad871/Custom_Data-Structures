#pragma once
#include <iostream>
#include <fstream>
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

class stack
{
public:

	node <Q>* top;
	int size;

	stack()
	{
		top = NULL;
		size = 0;
	}

	void push(Q dataItem) {

		node<Q>* temp = new node<Q>();
		temp = top;
		node<Q>* nod = new node<Q>(dataItem);


		if (!(this->isEmpty())) {

			nod->next = top;
			top = nod;
			size++;

		}
		if (this->isEmpty()) {

			top = nod;
			size++;

		}





	}
	void pop() {

		node<Q>* temp = new node<Q>();
		temp = top;


		if (!(this->isEmpty())) {

			top = top->next;
			size--;

		}


		delete temp;


	}

	int sizeofstack() {


		return size;


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

		for (int i = 0; i < size; i++)
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


		if (top == NULL || size == 0) {
			return true;
		}

		return false;

	}


	~stack()
	{
		this->clear();
	}



};



template <class T>

class MinStack
{
public:

	stack <T> s;
	stack <T> aux;

	void push(T data) {


		if (s.isEmpty() && aux.isEmpty()) {

			s.push(data);
			aux.push(data);



		}
		else if (aux.top->getval() > data) {


			s.push(data);
			aux.push(data);

		}
		else
		{
			s.push(data);

		}



	}

	void pop() {


		if (aux.top->getval() == s.top->getval()) {


			s.pop();
			aux.pop();

		}
		else
		{
			s.pop();

		}



	}
	T top() {

		return s.top->getval();
	}

	int size() {

		return s.sizeofstack();

	}

	bool isEmpty() {

		return s.isEmpty();

	}

	T getMin() {


		return aux.top->getval();
	}





};

bool validate(string fileName = "Test3.txt") {

	ifstream test1;
	string line;
	stack<char> bracketsLog;

	test1.open(fileName);

	while (getline(test1, line)) {

		//cout << " " << line;

		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == '('|| line[i] == '{'|| line[i] == '[') {
				
				bracketsLog.push(line[i]);

			}
			else if (line[i] == ')' || line[i] == '}' || line[i] == ']') {

				bracketsLog.pop();
			}
		}
	}
	bracketsLog.print();
	test1.close();

	if (bracketsLog.sizeofstack() == 0) {
		cout << "True";
		return 1;
	}
	else {
		cout << "false";

		return 0;
	}
	

}




