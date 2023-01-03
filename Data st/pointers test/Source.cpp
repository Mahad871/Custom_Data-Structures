#include <iostream>
using namespace std;

void function(int arr)
{
	for (int i = 0; i < 5; i++)
	{
		arr *= 2;
	}

}


int main() {

	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << ptr[i] << '\t';
	}
	cout << endl;
	function(arr[0]);

	for (int i = 0; i < 5; i++)
	{
		cout << ptr[i] << '\t';
	}
	return 0;
}