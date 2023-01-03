#pragma once
#include <iostream>
using namespace std;

class Matrix {
private:

	float** matrix;
	int row;
	int col;

public:
	Matrix() {

		row = 0; col = 0;
		matrix = new float* [row];

		for (int i = 0; i < row; i++)
		{
			matrix[i] = new float[row];

		}


	}
	Matrix(int r, int c) {
		row = r; col = c;
		matrix = new float* [row];

		for (int i = 0; i < row; i++)
		{
			matrix[i] = new float[row];

		}
	}
	Matrix(const Matrix& cc) {

		row = cc.row; col = cc.col;
		matrix = new float* [row];

		for (int i = 0; i < row; i++)
		{
			matrix[i] = new float[row];

		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = cc.matrix[i][j];
			}
		}


	}
	void set(int i, int j, float val) {


		matrix[i][j] = val;

	}
	float get(int i, int j)const {

		return matrix[i][j];

	}
	Matrix& assign(const Matrix cc) {


		row = cc.row; col = cc.col;
		matrix = new float* [row];

		for (int i = 0; i < row; i++)
		{
			matrix[i] = new float[row];

		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] = cc.matrix[i][j];
			}
		}

		return *this;

	}
	Matrix add(const Matrix add) {

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] += add.matrix[i][j];
			}
		}


	}
	Matrix subtract(const Matrix sub) {
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] -= sub.matrix[i][j];
			}
		}
	}
	Matrix multiply(const Matrix m) {

		if (col != m.row) {
			return m;
		}
		Matrix mult;

		for (int i = 0; i < mult.row; i++) {
			for (int j = 0; j < mult.col; j++) {
				mult.matrix[i][j] = 0;
				
			}
		}

		mult.row = row;
		mult.col = m.col;

		mult.matrix = new float* [mult.row];

		for (int i = 0; i < mult.row; i++) {
			mult.matrix[i] = new float[mult.col];
		}

		for (int i = 0; i < mult.row; i++) {
			for (int j = 0; j < mult.col; j++) {
				mult.matrix[i][j] = 0;
				for (int k = 0; k < col; k++) {
					mult.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
			}
		}

		return mult;



	}
	Matrix multiplyElement(const Matrix mult) {

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] *= mult.matrix[i][j];
			}
		}

	}
	Matrix add(float n) {

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] += n;
			}
		}

	}
	Matrix multiply(float n) {

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				matrix[i][j] *= n;
			}
		}


	}
	void input() {

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << "Enter value for row " << i << " Col " << j;
				cin >> matrix[i][j];
			}
		}


	}
	void display() {

		for (int i = 0; i < row; i++)
		{
			cout << "| " ;

			for (int j = 0; j < col; j++)
			{
				cout << "Enter value for row " << i << " Col " << j;
				cout<< matrix[i][j]<<" ";
			}

			cout << "|" << endl;
		}

	}

	~Matrix() {

		delete[] matrix;

	}
	
};