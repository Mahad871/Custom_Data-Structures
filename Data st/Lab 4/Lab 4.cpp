//MAHAD SALEEM // I210475 // CS21_Y

#include <iostream>
#include <ctime>

using namespace std;



void allocate(int**& p, int nrows, int ncols) {


	p = new int* [nrows];


	for (int i = 0; i < nrows; i++)
	{
		p[i] = new int[ncols];
	}

	for (int i = 0; i < nrows; i++)
	{
		for (int j = 0; j < ncols; j++)
		{
			p[i][j] = rand() % 49;
		}

	}






}


void deallocate(int**& p, int nrows, int ncols) {





	for (int i = 0; i < nrows; i++)
	{
		delete[] p[i];
	}

	delete[] p;

}


int* max(int**& p, int nrows, int ncols) {

	int* max = new int[nrows];


	for (int i = 0; i < nrows; i++)
	{
		max[i] = p[i][0];
		for (int j = 0; j < ncols; j++)
		{
			if (p[i][j] > max[i])
			{
				max[i] = p[i][j];
			}

		}

	}

	cout << "Max Numbers are: [  ";

	for (int i = 0; i < nrows; i++)
	{
		cout << max[i] << "  ";
	}
	cout << " ]";

	return max;

}


int** sum(int nrows, int ncols) {

	int** a1;
	int** a2;
	int** a3;

	allocate(a1, nrows, ncols);
	allocate(a2, nrows, ncols);
	allocate(a3, nrows, ncols);



	for (int i = 0; i < nrows; i++)
	{
		cout << "| ";
		for (int j = 0; j < ncols; j++)
		{
			a1[i][j] = 0;
			a3[i][j] += a1[i][j] + a2[i][j];

			cout << a3[i][j] << "  ";

		}

		cout << "|" << endl;
	}

	max(a3, nrows, ncols);
	deallocate(a1, nrows, ncols);
	deallocate(a2, nrows, ncols);

	return a3;
}


void allocateThreeD(int***& p, int npages, int rows, int cols) {

	p = new int** [npages];

	for (int i = 0; i < npages; i++)
	{
		p[i] = new int* [rows];
		for (int j = 0; j < rows; j++)
		{
			p[i][j] = new int[cols];

		}

	}


}

void deAllocateThreeD(int*** p, int npages, int rows, int cols) {

	for (int i = 0; i < npages; i++)
	{

		for (int j = 0; j < rows; j++)
		{

			delete[] p[i][j];



		}
		delete[] p[i];

	}


	delete[] p;

}

int main() {

	srand(time(0));


	sum(3, 3);




	return 0;
}


