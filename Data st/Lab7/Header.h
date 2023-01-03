#pragma once
#include<iostream>
using namespace std;

template <class D1, class D2>
struct Node
{
	D1 id;
	D1 cnic;
	D1 date;
	D2 salary;
	D2 bonus;
	struct Node<D1, D2>* pre;
	struct Node<D1, D2>* next;

	//default constructor
	Node()
	{
		pre = NULL;
		next = NULL;
		id = NULL;
		cnic = NULL;
		data = NULL;
		salary = 0;
		bonus = 0;
	}
	//parametrized constructor
	Node(D1 I, D1 C, D1 D, D2 S, D2 B)
	{
		id = I;
		cnic = C;
		date = D;
		salary = S;
		bonus = B;
	}

};


template <class D1, class D2>
class List
{
private:
	Node<D1, D2>* head;
	Node<D1, D2>* tail;

public:
	List()
	{
		head = NULL;
		tail = NULL;
	}

	bool isEmpty()
	{
		if (head == NULL && tail == NULL)
		{
			return true;
		}
		return false;
	}
	void insert(D1 Id, D1 Cnic, D1 Date, D2 Salary, D2 Bonus)
	{
		if (isEmpty() == true)
		{
			head = new Node<D1, D2>(Id, Cnic, Date, Salary, Bonus);
			tail = head;
			head->next = head;
			head->pre = head;

		}
		else
		{
			Node<D1, D2>* temp = new Node<D1, D2>(Id, Cnic, Date, Salary, Bonus);
			tail->next = temp;
			temp->next = tail->next;
			temp->pre = tail;
			tail = temp;
			head->pre = tail;
		}
	}
	void search(D1 i)
	{
		Node<D1, D2>* temp = head;
		if (!isEmpty())
		{
			while (temp->next != head)
			{
				if (temp->id == i)
				{
					cout << "ID : " << temp->id << endl;
					cout << "CNIC : " << temp->cnic << endl;
					cout << "JOINING DATE : " << temp->date << endl;
					cout << "SALARY : " << temp->salary << endl;
					cout << "BONUS : " << temp->bonus << endl;
					cout << endl << endl;
					return;
				}
				temp = temp->next;
			}
			if (temp->id == i)
			{
				cout << "ID : " << temp->id << endl;
				cout << "CNIC : " << temp->cnic << endl;
				cout << "JOINING DATE : " << temp->date << endl;
				cout << "SALARY : " << temp->salary << endl;
				cout << "BONUS : " << temp->bonus << endl;
				cout << endl << endl;
				return;
			}
			cout << "NOT FOUND " << endl;
			return;
		}
		else
		{
			cout << "PLEASE ENTER THE RECORD" << endl;
		}

	}
	void remove(D1 i)
	{
		Node<D1, D2>* temp = head;
		if (isEmpty())
		{
			cout << "PLEASE ENTER THE RECORD" << endl;
			return;
		}
		else if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
			return;
		}
		else
		{
			while (temp->next != head)
			{
				if (temp->id == i)
				{
					(temp->next)->pre = temp->pre;
					(temp->pre)->next = temp->next;
					delete temp;
					return;
				}
				temp = temp->next;
			}
			if (temp->id == i)
			{
				(temp->next)->pre = temp->pre;
				(temp->pre)->next = temp->next;
				delete temp;
				return;
			}
			cout << "NOT FOUND" << endl;

		}
	}
	void Update(D1 i, D2 s) {
		Node<D1, D2>* temp = head;
		if (head != NULL)
		{
			while (temp->next != head)
			{
				if (temp->id == i) {
					temp->salary = s;
					return;
				}
				temp = temp->next;
			}
			if (temp->id == i) {
				temp->salary = s;
				return;
			}
		}
		cout << "PLEASE ENTER THE RECORD" << endl;
	}
	D2 max()
	{
		Node<D1, D2>* temp = head;
		D2 max_num = 0;
		while (temp->next != head)
		{
			if (temp->salary > max_num)
			{
				max_num = temp->salary;
			}
			temp = temp->next;
		}
		if (temp->salary > max_num)
		{
			max_num = temp->salary;
		}
		return max_num;
	}
	void print() {
		Node<D1, D2>* temp = head;
		if (head != NULL)
		{
			while (temp->next != head)
			{
				cout << "-----------------------------------------" << endl;
				cout << "ID = " << temp->id << endl;
				cout << "CNIC = " << temp->cnic << endl;
				cout << "Joining Date = " << temp->date << endl;
				cout << "Salary = " << temp->salary << endl;
				cout << "Bonus = " << temp->bonus << endl;
				temp = temp->next;
				cout << "-----------------------------------------" << endl;
				cout << endl;
			}
			cout << "-----------------------------------------" << endl;
			cout << "ID = " << temp->id << endl;
			cout << "CNIC = " << temp->cnic << endl;
			cout << "Joining Date = " << temp->date << endl;
			cout << "Salary = " << temp->salary << endl;
			cout << "Bonus = " << temp->bonus << endl;
			temp = temp->next;
			cout << "-----------------------------------------" << endl;
			cout << endl;
		}
	}
};