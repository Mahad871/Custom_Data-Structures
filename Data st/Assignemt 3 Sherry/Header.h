#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <class T>
class listNode {
public:
	T data;
	listNode* next;

	listNode(T x) {
		data = x;
		next = NULL;
	}
};

template <class T>
class linkedList {
public:
	listNode<T>* head;
	listNode<T>* tail;

	linkedList() {
		head = NULL;
		tail = NULL;
	}

	void insert(T s) {
		if (head == NULL)
		{
			head = new listNode<T>(s);
			tail = head;
		}
		else
		{
			listNode<T>* temp = new listNode<T>(s);
			tail->next = temp;
			tail = temp;
		}
	}

	void deleteN(T s) {
		listNode<T>* temp;
		listNode<T>* prev;
		if (head != NULL)
		{
			if (head->data == s)
			{
				if (head == tail)
				{
					tail = NULL;
				}
				temp = head;
				head = head->next;
				delete temp;

				return;
			}
			else
			{
				prev = head;
				temp = head->next;

				while (temp->data != s && temp->next != NULL)
				{
					temp = temp->next;
					prev = prev->next;
				}
				if (temp->data == s)
				{
					if (temp == tail)
					{
						tail = prev;
					}
					prev->next = temp->next;
					delete temp;
				}
			}
		}
	}


	void print() {
		listNode<T>* temp = head;

		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

	void deleteAll() {
		//listNode<T>* temp = head;

		while (head != NULL)
		{
			deleteN(head->data);
		}
	}

	T retString(int i)
	{
		listNode<T>* temp = head;
		int c = 0;
		while (c != i)
		{
			temp = temp->next;
			c++;
		}

		return temp->data;
	}

	int retIndex(T inp)
	{
		listNode<T>* temp = head;
		int c = -1;
		while (temp != NULL)
		{
			if (temp->data == inp)
			{
				return c;
			}
			temp = temp->next;
			c++;
		}
		return c;
	}

	bool search(T x) {
		listNode<T>* temp = head;

		while (temp != NULL)
		{
			if (x == temp->data)
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	}
};

class Graph
{
public:
	int** adjMatrix;
	int size;
	string prevS;
	string nextS;
	linkedList<string> citiesList;
	Graph()
	{
		prevS = "e";
		nextS = "e";
		size = 0;
	}
	string printsingleLink(string inp)
	{
		string ret = inp;
		ret += ": ";
		int index = citiesList.retIndex(inp);
		for (int i = 0; i < size; i++)
		{
			if (adjMatrix[i][index] != 0)
			{
				string city = citiesList.retString(i + 1);
				ret = ret + "-> " + city;
			}
		}
		return ret;
	}
	void insertVertex(string inpCity)
	{
		citiesList.insert(inpCity);
		int** temp;
		temp = new int* [size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = new int[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				temp[i][j] = adjMatrix[i][j];
			}
		}
		size++;
		adjMatrix = new int* [size];
		for (int i = 0; i < size; i++)
		{
			adjMatrix[i] = new int[size];
		}
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				adjMatrix[i][j] = temp[i][j];
			}
		}
		adjMatrix[size - 1][size - 1] = 0;
		for (int i = 0; i < size - 1; i++)
		{
			adjMatrix[size - 1][i] = 0;
			adjMatrix[i][size - 1] = 0;
		}
	}

	void removeRow(int inpRow)
	{
		int** temp;
		temp = new int* [size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = new int[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				temp[i][j] = adjMatrix[i][j];
			}
		}
		adjMatrix = new int* [size - 1];
		for (int i = 0; i < size; i++)
		{
			adjMatrix[i] = new int[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i != inpRow)
				{
					adjMatrix[i][j] = temp[i][j];
				}
			}
		}
		size--;
	}

	void removeCol(int inpRow)
	{
		int** temp;
		temp = new int* [size];
		for (int i = 0; i < size; i++)
		{
			temp[i] = new int[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				temp[i][j] = adjMatrix[i][j];
			}
		}
		adjMatrix = new int* [size];
		for (int i = 0; i < size; i++)
		{
			adjMatrix[i] = new int[size - 1];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (j != inpRow)
				{
					adjMatrix[i][j] = temp[i][j];
				}
			}
		}
	}

	void insertEdge(string row, string col, int d)
	{
		int r = citiesList.retIndex(row);
		int c = citiesList.retIndex(col);
		adjMatrix[r][c] = d;
		adjMatrix[c][r] = d;
	}

	void insertEdge(int r, int c, int d)
	{
		adjMatrix[r][c] = d;
		adjMatrix[c][r] = d;
	}

	void removeVertex(string inpString)
	{
		//citiesList.deleteN(inpString);
		//citiesList.print();
		int inpRow = citiesList.retIndex(inpString);
		//cout << inpRow;
		for (int i = 0; i < size; i++)
		{
			adjMatrix[i][inpRow] = 0;
			adjMatrix[inpRow][i] = 0;
		}
		//for (int i = inpRow; i < size - 1; i++)
		//{
		//	for (int j = 0; j < size; j++)
		//	{
		//		adjMatrix[i][j] = adjMatrix[i + 1][j];
		//	}
		//}
		//for (int i = 0; i < size - 1; i++)
		//{
		//	for (int j = inpRow; j < size - 1; j++)
		//	{
		//		adjMatrix[i][j] = adjMatrix[i][j + 1];
		//	}
		//}
		//size--;

	}

	void removeEdge(int i, int j)
	{
		adjMatrix[i][j] = 0;
		adjMatrix[j][i] = 0;
	}

	void removeEdge(string a, string b)
	{
		int r = citiesList.retIndex(a);
		int c = citiesList.retIndex(b);
		adjMatrix[r][c] = 0;
		adjMatrix[c][r] = 0;
	}

	void showGraph()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << adjMatrix[i][j] << "\t";
			}
			cout << endl;
		}
	}

	void ReadFromFile()
	{
		string myFilePath = "C:\\Users\\msasd\\OneDrive\\Desktop\\Vs Code\\Semester 3\\Data st\\Assignemt 3 Sherry\\GraphData.csv";
		vector<vector<string>> fileInp;
		vector<string> rowData;
		int cities = 0;

		string lineInp, wordInp;
		string temp1;
		fstream file(myFilePath, ios::in);

		if (file.is_open())
		{
			while (getline(file, lineInp))
			{
				rowData.clear();
				stringstream str(lineInp);
				while (getline(str, wordInp, ','))
				{
					if (wordInp[0] == '"')
					{
						while (wordInp[wordInp.length() - 1] != '"')
						{
							temp1 = temp1 + wordInp;
							temp1 += ',';
							getline(str, wordInp, ',');
						}
						temp1 = temp1 + wordInp;
						wordInp = temp1;
						temp1 = "";
					}
					rowData.push_back(wordInp);
				}
				fileInp.push_back(rowData);
				cities++;
			}
		}
		else
		{
			cout << "File not present.";
		}

		cities = fileInp.size();

		file.close();

		for (int i = 0; i < cities; i++)
		{
			insertVertex(fileInp[i][0]);
		}
		for (int i = 1; i < cities; i++)
		{
			for (int j = 1; j < cities; j++)
			{
				insertEdge(i - 1, j - 1, stoi(fileInp[i][j]));
			}
		}
		removeRow(size - 1);
	}

	int NO_PARENT = -1;

	void shorterstPathfromOnetoalltest(string inp)
	{
		int choice = 1;
		int index = citiesList.retIndex(inp);
		shortestAlgorithm(adjMatrix, index, choice, 0);
		shortestAlgorithm(adjMatrix, index, choice, 0);
		ReadFromFile();
	}

	void shortestPathfromalltoone(string inp)
	{
		int choice = 2;
		int index = citiesList.retIndex(inp);
		for (int i = 1; i < 22; i++)
		{
			ShortestRoutefrompair(citiesList.retString(i), inp);
		}
	}

	void ShortestRoutefrompair(string first, string second)
	{
		int choice = 3;
		int index1 = citiesList.retIndex(first);
		int index2 = citiesList.retIndex(second);
		shortestAlgorithm(adjMatrix, index1, choice, index2);
		shortestAlgorithm(adjMatrix, index1, choice, index2);
		ReadFromFile();
	}

	void printPath(int currentVertex, vector<int> parents)
	{
		if (currentVertex == NO_PARENT) {
			return;
		}
		if (prevS == "e" && nextS == "e")
		{
			prevS = citiesList.retString(currentVertex + 1);
		}
		else if (nextS == "e")
		{
			nextS = citiesList.retString(currentVertex + 1);
		}
		else
		{
			//removeEdge(prevS, nextS);
			prevS = "e";
			nextS = "e";
		}
		printPath(parents[currentVertex], parents);
		cout << " -> " << citiesList.retString(currentVertex + 1);
	}

	//void printPath3(int currentVertex, vector<int> parents)
	//{
	//	if (currentVertex == NO_PARENT) {
	//		return;
	//	}
	//	printPath(parents[currentVertex], parents);
	//	cout << " -> " << citiesList.retString(currentVertex + 1);
	//}

	void printSolution(int startVertex, vector<int> distances, vector<int> parents)
	{
		int nVertices = distances.size();
		for (int vertexIndex = 0; vertexIndex < nVertices;
			vertexIndex++) {
			if (vertexIndex != startVertex) {
				cout << "\n" << citiesList.retString(startVertex + 1) << " -> ";
				cout << citiesList.retString(vertexIndex + 1) << " \t\t ";
				cout << distances[vertexIndex] << "km\n";
				printPath(vertexIndex, parents);
			}
			cout << endl;
		}
	}

	void printSolution3(int startVertex, vector<int> distances, vector<int> parents, int limit)
	{
		int nVertices = distances.size();
		for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++) {
			if (vertexIndex != startVertex) {
				if (limit + 1 == vertexIndex + 1)
				{
					cout << "\n" << citiesList.retString(startVertex + 1) << " -> ";
					cout << citiesList.retString(vertexIndex + 1) << " \t\t ";
					cout << distances[vertexIndex] << "km\n";
					printPath(vertexIndex, parents);
				}
			}
			cout << endl;
		}
	}



	void shortestAlgorithm(int** adjacencyMatrix, int startVertex, int c, int ind2)
	{
		if (startVertex == 2)
		{
			cout << "No possible route.\n";
		}
		else
		{
			if (c == 1)
			{
				int nVertices = 22;
				vector<int> shortestDistances(nVertices);
				vector<bool> added(nVertices);
				for (int vertexIndex = 0; vertexIndex < nVertices;
					vertexIndex++) {
					shortestDistances[vertexIndex] = INT_MAX;
					added[vertexIndex] = false;
				}
				shortestDistances[startVertex] = 0;
				vector<int> parents(nVertices);
				parents[startVertex] = NO_PARENT;
				for (int i = 1; i < nVertices; i++)
				{
					int nearestVertex = -1;
					int shortestDistance = INT_MAX;
					for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
					{
						if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance)
						{
							nearestVertex = vertexIndex;
							shortestDistance = shortestDistances[vertexIndex];
						}
					}
					added[nearestVertex] = true;
					for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
					{
						int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];
						if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex]))
						{
							parents[vertexIndex] = nearestVertex;
							shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
						}
					}
				}
				printSolution(startVertex, shortestDistances, parents);
			}
			else if (c == 3)
			{
				int nVertices = 22;
				vector<int> shortestDistances(nVertices);
				vector<bool> added(nVertices);
				for (int vertexIndex = 0; vertexIndex < nVertices;
					vertexIndex++) {
					shortestDistances[vertexIndex] = INT_MAX;
					added[vertexIndex] = false;
				}
				shortestDistances[startVertex] = 0;
				vector<int> parents(nVertices);
				parents[startVertex] = NO_PARENT;
				for (int i = 1; i < nVertices; i++)
				{
					int nearestVertex = -1;
					int shortestDistance = INT_MAX;
					for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
					{
						if (!added[vertexIndex] && shortestDistances[vertexIndex] < shortestDistance)
						{
							nearestVertex = vertexIndex;
							shortestDistance = shortestDistances[vertexIndex];
						}
					}
					added[nearestVertex] = true;
					for (int vertexIndex = 0; vertexIndex < nVertices; vertexIndex++)
					{
						int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];
						if (edgeDistance > 0 && ((shortestDistance + edgeDistance) < shortestDistances[vertexIndex]))
						{
							parents[vertexIndex] = nearestVertex;
							shortestDistances[vertexIndex] = shortestDistance + edgeDistance;
						}
					}
				}
				printSolution3(startVertex, shortestDistances, parents, ind2);
			}
		}
	}
};