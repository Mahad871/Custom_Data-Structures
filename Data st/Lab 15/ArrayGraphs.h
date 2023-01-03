//#pragma once
//#include <iostream>
//
//using namespace std;
//
//class ArrayGraph
//{
//public:
//
//	int** adjList;
//	int noOfVertices;
//
//	ArrayGraph(int nov)
//	{
//		noOfVertices = nov;
//		adjList = new int* [noOfVertices] ;
//
//		for (int i = 0; i < noOfVertices; i++)
//		{
//			adjList[i] = new int[noOfVertices] {INFINITY};
//		}
//
//	}
//
//	void addEdge(int i, int j,int weight) {
//
//		if (i >= noOfVertices || j >= noOfVertices) {
//			return;
//		}
//		adjList[i][j] = true;
//
//
//	}
//
//	void removeEdge(int i, int j) {
//
//		if (i >= noOfVertices || j >= noOfVertices) {
//			return;
//		}
//		adjList[i][j] = INFINITY;
//
//
//	}
//
//	int isEdge(int i, int j) {
//		
//		return adjList[i][j];
//	}
//
//	void Print() {
//
//
//		for (int i = 0; i < noOfVertices; i++)
//		{
//			cout << "|  ";
//			for (int j = 0; j < noOfVertices; j++)
//			{
//				cout << adjList[i][j] << "  ";
//			}
//			cout<< "|" << endl;
//		}
//
//
//	}
//
//
//};
