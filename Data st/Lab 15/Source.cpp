#include <iostream>
#include "graph.h"

using namespace std;

int main() {



	Graph<int, int> g2(50);
	int coice = 0;
	string city;


	
	g2.ReadFromFile();
	//g2.addNode("Sialkot");
	g2.showGraphStructure();
	cout << "\nEnter city name:";
	cin >> city;
	g2.shortestDistanceFromAllCities(city);
	cout << endl;
	//g2.BFS(0);

	return 0;
}