#pragma once
#pragma once
#include<iostream>
using namespace std;
template<typename T> T smaller(T first, T second)
{
	if (first < second)
	{
		return first;
	}
	return second;
}
template<typename X> X smaller(X first, X second, X third)
{
	if (first < second)
	{
		if (first < third)
		{
			return first;
		}
		if (third < first)
		{
			return third;
		}
	}
	return second;
}
template<typename A>
A* sameElement(A arr1[], A arr2[], int x, int y)
{
	A* res = new A[20];
	int val = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (arr1[i] == arr2[j])
			{
				res[val] = arr1[i];
				val++;
			}

		}

	}
	return res;
}
template<typename N>
N* concatenateArrays(N arr1[], N arr2[], int x, int y)
{
	bool flag = true;
	N* res = new N[20];
	int val = 0;
	for (int i = 0; i < x; i++)
	{
		res[val] = arr1[i];
		val++;
	}
	for (int j = 0; j < y; j++)
	{
		for (int v = 0; v < x; v++)
		{
			if (arr2[j] == arr1[v])
			{
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag)
		{
			res[val] = arr2[j];
			val++;
		}
	}
	return res;
}


template <typename T>

class container
{
public:
	T* values;
	int capacity;
	int counter;
public:
	container(int x)
	{
		capacity = x;
		counter = 0;
		values = new T[capacity];
	}
	bool isFull()
	{
		bool ans = true;
		if (counter != capacity)
		{
			ans = false;
		}
		return ans;
	}
	bool insert(T value)
	{
		if (!isFull())
		{
			values[counter++] = value;
			return true;
		}
		return false;
	}
	bool search(T find)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (find = values[i])
			{
				return true;
			}
		}
		return false;
	}
	bool remove(T remove)
	{
		int index = 0;
		bool checker = false;
		T* ans = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			if (remove == values[i])
			{
				checker = true;
				index = i;
			}
		}
		if (checker)
		{
			for (int i = 0; i < capacity; i++)
			{
				if (i == index)
				{
					i++;
				}
				ans[i] = values[i];
			}
			counter--;
		}
		return checker;
	}
	void print()
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << values[i] << endl;
		}
	}
};