#pragma once
#include <fstream>
#include <iostream>

using namespace std;

int arraySum(int arr[][5], int m, int n) {

	int sum = 0;




	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

			sum += arr[i][j];

		}

	}

	return sum;


}

int* rowSum(int arr[][4], int m, int n) {


	int* sum = new int[m];

	for (int i = 0; i < m; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < n; j++)
		{
			sum[i] += arr[i][j];

		}

	}



	return sum;
}


int* colSum(int arr[][4], int m, int n) {


	int* sum = new int[m];

	for (int i = 0; i < m; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < n; j++)
		{
			sum[i] += arr[j][i];

		}

	}



	return sum;
}



int** transposeMatrix(int arr[][2], int m, int n) {



	int** transpose = new int* [2];

	for (int i = 0; i < m; i++) {

		// Declare a memory block
		// of size n
		transpose[i] = new int[2];
	}


	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
		{
			transpose[i][j] = arr[j][i];

		}

	}

	return transpose;
}

int** matrixSum(int arr[][3], int arr1[][3], int m, int n) {


	int** sum = new int* [m];

	for (int i = 0; i < m; i++) {

		// Declare a memory block
		// of size n
		sum[i] = new int[n];
	}


	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
		{
			sum[i][j] = arr[i][j] + arr1[i][j];

		}

	}

	return sum;
}



int  multiplyMatrix(int arr[][4], int arr1[][4], int m, int n, int m1, int n1) {


	int** mult = new int* [m];

	for (int i = 0; i < m; i++) {

		// Declare a memory block
		// of size n
		mult[i] = new int[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mult[i][j] = 0;
			for (int k = 0; k < n1; k++) {
				mult[i][j] += arr[i][k] * arr1[k][j];
			}
		}
	}


	int sum = 0;




	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{

			sum += mult[i][j];

		}

	}

	return sum;
}



int leftDiagonalSum(int arr[][4], int m, int n) {
	int ldsum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				ldsum += arr[i][j];
		}
	}
	return ldsum;
}
int rightDiagonalSum(int arr[][4], int m, int n) {
	int rdsum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1)
				rdsum += arr[i][j];
		}
	}
	return rdsum;
}


int* displayMiddleRow(int arr[][5], int m) {

	int middleRowNum = (m / 2);

	int* middleRow = new int[m];

	for (int j = 0; j < m; j++) {

		middleRow[j] = arr[middleRowNum][j];
	}

	return middleRow;
}
int* displayMiddleCol(int arr[][5], int m) {

	int middleRowNum = (m / 2);

	int* middleRow = new int[m];

	for (int j = 0; j < m; j++) {

		middleRow[j] = arr[j][middleRowNum];
	}

	return middleRow;
}



int* toIntArray(string str) {

	int len = str.length();
	int* arr = new int[len];

	for (int i = 0; i < len; i++)
	{
		arr[i] = ((int) str[i])-48 ;

	}


	return arr;
}

int* addTwoArray(string str, string st2)
{
	int length = 0;
	length = str.length();
	int* ptr = new int[length];
	for (int i = 0; i < length; i++)
	{
		ptr[i] = (str[i] - 48) + (st2[i] - 48);
	}
	return ptr;
}
int* subTwoArray(string str, string st2)
{
	int length = 0;
	length = str.length();
	int* ptr = new int[length];
	for (int i = 0; i < length; i++)
	{
		ptr[i] = (str[i] - 48) - (st2[i] - 48);
	}
	return ptr;
}

int* readFromFile() {

	
	ofstream MyFile("data.txt");
	MyFile << "55555";

	MyFile.close();

	string myText;

	ifstream MyreadFile("data.txt");

	
		// Output the text from the file
		MyreadFile >> myText;
		int len = myText.length();
		int* a = new int[len];
	
		a= toIntArray(myText);

	MyreadFile.close();


	return a;
}