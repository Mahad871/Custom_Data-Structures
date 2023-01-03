#pragma once

#include <iostream>
using namespace std;


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


}; //class