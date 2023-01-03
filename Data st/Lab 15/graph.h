#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include "Slinkedlist.h"

using namespace std;

template <class T, class X>

class Graph
{
public:
	int maxNoOfVertices;
	vector<string> cityName;
	SLinkedList<T, X>* adjList = NULL;
	int** adjMatrix = NULL;

	Graph(int maxVertices)
	{
		maxNoOfVertices = maxVertices;
		adjList = new SLinkedList <T, X>[maxNoOfVertices];
		adjMatrix = new int* [maxNoOfVertices];

		for (int i = 0; i < maxNoOfVertices; i++)
		{
			adjMatrix[i] = new int[maxNoOfVertices];

		}

		for (int i = 0; i < maxNoOfVertices; i++)
		{
			for (int j = 0; j < maxNoOfVertices; j++)
			{
				adjMatrix[i][j] = INT_MAX;

			}

		}

	}

	void insertEdge(T src, T dest, X weight) {


		adjList[src].insert(dest, weight);


	}

	void showGraphStructure() {



		for (int i = 0; i < maxNoOfVertices; i++)
		{
			cout << cityName[i] << " = ";
			adjList[i].print();

		}
		cout << "__________________________________________________________________________\n\n\t\tAdjecency Matrix\n__________________________________________________________________________\n " << endl;
		for (int i = 0; i < maxNoOfVertices; i++)
		{
			cout << "| ";
			for (int j = 0; j < maxNoOfVertices; j++)
			{
				cout << adjMatrix[i][j] << "  ";

			}
			cout << "|\n";

		}


	}

	void BFS(int startNode) {

		bool* isVisited = new bool [maxNoOfVertices] {false};
		queue<int> q;
		q.push(startNode);
		Node<int, int>* temp;
		isVisited[startNode] = true;
		cout << "Breadth First Search: ";
		while (!q.empty())
		{
			int current = q.front();
			cout << current << " ";
			q.pop();
			temp = adjList[current].head;
			while (temp)
			{
				if (!isVisited[temp->vertex]) {
					q.push(temp->vertex);
					isVisited[temp->vertex] = true;
				}
				temp = temp->next;

			}



		}


	}

	void deleteEdge(string src, string dest) {

		int i = 0;
		for (; i < maxNoOfVertices; i++)
		{
			if (cityName[i] == src) {
				break;
			}
		}

		int j = 0;
		for (; j < maxNoOfVertices; j++)
		{
			if (cityName[j] == dest) {
				break;
			}
		}

		adjMatrix[i][j] = INT_MAX;
		adjList[i].insert(j, INT_MAX);

	}

	void addNode(string node) {

		cityName.push_back(node);
		maxNoOfVertices++;

	}

	void removeNode(string node) {

		int i = 0;
		for (; i < maxNoOfVertices; i++)
		{
			if (cityName[i] == node) {
				break;
			}
		}

		for (int j = i; j < maxNoOfVertices; j++)
		{
			adjList[j] = adjList[j + 1];
			adjMatrix[j] = adjMatrix[j + 1];
		}
		maxNoOfVertices--;
	}
	void addEgde(string src, string dest, X edge) {

		int i = 0;
		for (; i < maxNoOfVertices; i++)
		{
			if (cityName[i] == src) {
				break;
			}
		}

		int j = 0;
		for (; j < maxNoOfVertices; j++)
		{
			if (cityName[j] == dest) {
				break;
			}
		}

		insertEdge(i, j, edge);
		adjMatrix[i][j] = edge;

	}

	int** ReadFromFile() {

		fstream fin;

	
		fin.open("GraphData.csv", ios::in);


		int rollnum = 0;

		vector<string> row;
		string line, word, temp;


		row.clear();

		getline(fin, line);

		int i = 0;


		while (line[i] != '\0')
		{
			while (line[i] != ',' && line[i] != '\0') {
				word += line[i];

				i++;
			}

			word;
			if (word.length() > 1)
				cityName.push_back(word);
			word.clear();
			if (line[i] == '\0') {
				break;
			}
			i++;

		}

		int j = 0;

		while (getline(fin, line))
		{
			i = 0;
			int k = -1;

			while (i < line.length())
			{
				while (line[i] != ',' && line[i] != '\0') {

					word += line[i];
					i++;
				}
				if (k >= 0) {
					this->adjList[j].insert(k, stoi(word));
					adjMatrix[j][k] = stoi(word);
				}
				word.clear();
				k++;
				i++;

			}
			j++;
		}
		maxNoOfVertices = j;
		fin.close();

		return adjMatrix;

	}

	int minDistance(int dist[], bool sptSet[])
	{

		
		int min = INT_MAX, min_index;

		for (int v = 0; v < maxNoOfVertices; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		return min_index;
	}


	void printSolution(int dist[], int src)
	{
		cout << "Vertex Distance from "<< cityName[src]<<" to all cities" << endl;
		for (int i = 0; i < maxNoOfVertices; i++)
			cout << cityName[i] << " \t\t\t\t" << dist[i] << endl;
	}

	void shortestDistanceFromAllCities(string src) {

		int i = 0;
		for (; i < maxNoOfVertices; i++)
		{
			if (cityName[i] == src) {
				break;
			}
		}

		dijkstra(i);

	}

	void dijkstra( int src)
	{

		int* dist=new int [maxNoOfVertices]; 


		bool* sptSet=new bool [maxNoOfVertices]; 

		for (int i = 0; i < maxNoOfVertices; i++)
			dist[i] = INT_MAX, sptSet[i] = false;

		dist[src] = 0;

		for (int count = 0; count < maxNoOfVertices - 1; count++) {
			
			int u = minDistance(dist, sptSet);

			sptSet[u] = true;

			
			for (int v = 0; v < maxNoOfVertices; v++)

				
				if (!sptSet[v] && adjMatrix[u][v]
					&& dist[u] != INT_MAX
					&& dist[u] + adjMatrix[u][v] < dist[v])
					dist[v] = dist[u] + adjMatrix[u][v];
		}

		
		printSolution(dist,src);
	}



};


