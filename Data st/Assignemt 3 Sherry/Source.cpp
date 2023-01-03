#include <iostream>
#include <vector>
#include "Header.h"

using namespace std;

int main()
{
    Graph* g = new Graph;
    g->ReadFromFile();
    //g->showGraph();
    g->shorterstPathfromOnetoalltest("Attock");
    //g->ShortestRoutefrompair("Attock", "Murree");
    //g->shortestPathfromalltoone("Murree");
    return 0;
}