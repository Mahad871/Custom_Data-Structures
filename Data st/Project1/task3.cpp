
#include <iostream>
using namespace std;


template <typename T>


T concatenate(T a[], T b[], int aSize, int bSize) {

	int size = aSize + bSize;
	int counter = 0;
	T* c = new T[size];


	for (int i = 0; i < aSize; i++)
	{
		c[counter] = a[i];
		counter++;
	}

	//counter++;

	for (int i = 0; i < bSize; i++)
	{
		c[counter] = b[i];

		counter++;

	}


	counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (i + 1 != size) {
			for (int j = i + 1; j < size; j++)
			{

				if (c[i] == c[j] && c[i] != -999999) {
					c[j] = -999999;
					counter++;
				}


			}
		}


	}


	cout << endl << counter;
	size -= counter;
	T* res = new T[size];

	for (int i = 0, j = 0; i < size + counter; i++)
	{

		if (c[i] != -999999) {

			res[j] = c[i];
			j++;
		}



	}

	cout << endl;

	for (int i = 0, j = 0; i < size; i++)
	{
		cout << (char)res[i] << '\t';


	}


	return 0;

}


int main() {

	int aSize = 0, bSize = 0;


	int a[3] = { 'a','b','c' }, b[3] = { 'd','b','f' }, c = 3;

	aSize = sizeof(a) / sizeof(a[0]);
	bSize = sizeof(b) / sizeof(b[0]);


	concatenate(a, b, aSize, bSize);


	return 0;
}