//Mahad Saleem //i210485
//Syed Haseeb //i210823
//Mobin Kashif //i210874
#include <iostream>
#include <list>
#include <stack>
#include "Graph.h"
using namespace std;


int main()
{
	Graph g(5);

	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);

	/*g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	g.addEdge(2, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 4);

	g.addEdge(8, 7);
	g.addEdge(7, 6);*/


	cout << "Following are strongly connected components in "
		"given graph \n\n";
	g.printSCCs();

	return 0;
}

