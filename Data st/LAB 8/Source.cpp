#include <iostream>
#include "Header.h"

using namespace std;

template <class T>

void task2() {

	T time = 0;
	T executionTime = 40;

	Queue<T> q1;

	q1.enqueue(50);
	q1.enqueue(30);
	q1.enqueue(80);
	q1.enqueue(100);
	//q1.print();

	while (1)
	{

		time = q1.retFront();
		cout << "\nExecution TIme: " << time;
		time -= executionTime;
		cout << "\nRemaining TIme: " << time;

		if (time > 0) {

			cout << "\nTask is not completed,it is being re - scheduled";
			q1.enqueue(time);
		}
		else if (q1.front == NULL) {
			cout << "\nTask is not completed,it is being re - scheduled";

		}
		else if (time <= 0)
		{
			cout << "\nTask completed,it is not being re - scheduled";

		}
		if (q1.isEnmpty()) {
			break;
		}
		q1.dequeue();


	}


}

void task3() {


	Queue<string> que;
	Queue<string> strque1;
	Queue<string> strque2;
	Queue<string> strque3;
	Queue<string> strque4;

	//
	strque1.enqueue("D");
	strque1.enqueue("A");
	strque1.enqueue("T");
	strque1.enqueue("A");
	//
	strque2.enqueue("S");
	strque2.enqueue("T");
	strque2.enqueue("R");
	strque2.enqueue("U");
	strque2.enqueue("C");
	strque2.enqueue("T");
	strque2.enqueue("U");
	strque2.enqueue("R");
	strque2.enqueue("E");
	//
	strque3.enqueue("A");
	strque3.enqueue("N");
	strque3.enqueue("D");
	//
	strque4.enqueue("A");
	strque4.enqueue("L");
	strque4.enqueue("G");
	strque4.enqueue("O");
	Node<string>* temp = strque1.front;
	while (temp)
	{
		que.enqueue(temp->data);
		temp = temp->next;
	}
	temp = strque2.front;
	while (temp)
	{
		que.enqueue(temp->data);
		temp = temp->next;
	}
	temp = strque3.front;
	while (temp)
	{
		que.enqueue(temp->data);
		temp = temp->next;
	}
	temp = strque4.front;
	while (temp)
	{
		que.enqueue(temp->data);
		temp = temp->next;
	}
	que.print();

}


int main() {




	Queue<int> q1;


	q1.enqueue(1);
	//task2<int>();
	task3();


	return 0;
}