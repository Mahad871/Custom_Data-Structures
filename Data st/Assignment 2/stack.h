//Mahad Saleem // I210475@nu.edu.pk

#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <class T>
class node
{
public:
	T val;
	node* next;

	node()
	{
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


//
//bool precendce(char op1, char op2) {
//
//	if (op1 == '$') {
//		op1 = '^';
//	}
//	if (op2 == '$') {
//		op2 = '^';
//	}
//
//
//	if (op1 == op2) {
//		return true;
//	}
//	else if (
//			 op1 == '^' && op2 == '/' 
//			|| op1 == '^' && op2 == '*' 
//			|| op1 == '^' && op2 == '+' 
//			|| op1 == '^' && op2 == '-' 
//			|| op1 == '/' && op2 == '*' 
//			|| op1 == '*' && op2 == '/' 
//			|| op1 == '/' && op2 == '+' 
//			|| op1 == '/' && op2 == '-' 
//			|| op1 == '+' && op2 == '-' 
//			|| op1 == '-' && op2 == '+' 
//			|| op2 == ')')
//	{
//		return true;
//	}
//	else
//	{
//		false;
//	}
//
//
//
//}
//
//
//
//
//string infixToPostfix(string exp) {
//
//	cout << exp << endl;
//
//	stack<char> opBrackets, clBrackets;
//
//	for (int i = 0; i < exp.length(); i++)
//	{
//		if (exp[i] == '(') {
//			opBrackets.push(exp[i]);
//		}
//		else if (exp[i] == ')')
//		{
//			clBrackets.push(exp[i]);
//		}
//
//	}
//
//	if (opBrackets.sizeofstack() != clBrackets.sizeofstack()) {
//		return "Invalid Expression";
//	}
//
//
//	string postStr;
//
//
//	for (int i = 0; i < exp.length(); i++)
//	{
//		if (exp[i] != ' ')
//			postStr += exp[i];
//	}
//
//	exp = postStr;
//	cout << exp << endl;
//	postStr.clear();
//
//
//	char topSymb;
//
//	stack<char> opstck;
//
//	for (int i = 0; i < exp.length(); i++)
//	{
//		char currentCh = exp[i];
//		char nextCh = exp[i + 1];
//
//		if (currentCh >= 'a' && currentCh <= 'z' || currentCh >= 'A' && currentCh <= 'Z') {
//
//			postStr += currentCh;
//		}
//		else
//		{
//			while (!opstck.isEmpty() && precendce(opstck.top->val, currentCh))
//			{
//
//				topSymb = opstck.top->val;
//				if (topSymb != '(') {
//
//					postStr += topSymb;
//				}
//				opstck.pop();
//
//			}
//		}
//		if (opstck.isEmpty() || currentCh != ')') {
//			if (!(currentCh >= 'a' && currentCh <= 'z') && !(currentCh >= 'A' && currentCh <= 'Z') && currentCh != ')' && currentCh != ' ') {
//
//				opstck.push(currentCh);
//			}
//		}
//		else
//		{
//			nextCh = opstck.top->val;
//			opstck.pop();
//		}
//		/*opstck.print();
//		cout << endl;*/
//	}
//
//	while (!opstck.isEmpty())
//	{
//		char currentCh = opstck.top->val;
//		postStr += currentCh;
//		opstck.pop();
//
//	}
//	cout << postStr << endl;
//	return postStr;
//
//
//}
