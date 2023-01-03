#include"pch.h"
#include<iostream>
#include "Graph.h"
#include <gtest/gtest.h>
using namespace std;

int** arr;
int arraycount = 0;

TEST(Graph, addNodetest) {
    Graph* g = new Graph(30);
    string city[25];
    arr = ReadFromFile("GraphData.csv", city);//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    string s1 = "Sialkot: ";
    for (int i = 0; i < 25; i++)
    {
        g->addnode(city[i]);
    }

    for (int i = 0; i < g->noOfVertices; i++)
    {
        for (int j = 0; j < g->noOfVertices; j++)
        {
            if (arr[i][j] != 0)
            {
                g->addEdge1(city[i], city[j], arr[i][j]);
            }
        }
    }

    g->addnode("Sialkot");
    //    g->printGraph();

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Sialkot")));
}

TEST(Graph, addEdgetest) {
    Graph* g = new Graph(30);
    string city[25];
    arr = ReadFromFile("GraphData.csv", city);

    for (int i = 0; i < 25; i++)
    {
        g->addnode(city[i]);
    }

    for (int i = 0; i < g->noOfVertices; i++)
    {
        for (int j = 0; j < g->noOfVertices; j++)
        {
            if (arr[i][j] != 0)
            {
                g->addEdge1(city[i], city[j], arr[i][j]);
            }
        }
    }
    string s1 = "Karachi: -> Sukkur-> Peshawar";
    g->addEdge("Karachi", "Peshawar", 200);
    g->printGraph();

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Karachi")));
}

TEST(Graph, deleteNodetest) {
    Graph* g = new Graph(30);
    string city[25];
    arr = ReadFromFile("GraphData.csv", city);

    for (int i = 0; i < 25; i++)
    {
        g->addnode(city[i]);
    }

    for (int i = 0; i < g->noOfVertices; i++)
    {
        for (int j = 0; j < g->noOfVertices; j++)
        {
            if (arr[i][j] != 0)
            {
                g->addEdge1(city[i], city[j], arr[i][j]);
            }
        }
    }

    string s1 = "Multan: -> Jhang-> DG Khan-> Bahawalpur";

    g->deleteNode("Lahore");

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Multan")));
}

TEST(Graph, deleteEdgetest) {
    Graph* g = new Graph(30);
    string city[25];
    arr = ReadFromFile("GraphData.csv", city);

    for (int i = 0; i < 25; i++)
    {
        g->addnode(city[i]);
    }

    for (int i = 0; i < g->noOfVertices; i++)
    {
        for (int j = 0; j < g->noOfVertices; j++)
        {
            if (arr[i][j] != 0)
            {
                g->addEdge1(city[i], city[j], arr[i][j]);
            }
        }
    }
    string s1 = "Quetta: ";
    g->deleteEdge("Quetta", "Khuzdar");

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Quetta")));
}

TEST(Graph, shorterstPathfromOnetoalltest) {
    Graph* g = new Graph(30);
    string city[25];
    arr = ReadFromFile("GraphData.csv", city);

    for (int i = 0; i < 25; i++)
    {
        g->addnode(city[i]);
    }

    for (int i = 0; i < g->noOfVertices; i++)
    {
        for (int j = 0; j < g->noOfVertices; j++)
        {
            if (arr[i][j] != 0)
            {
                g->addEdge1(city[i], city[j], arr[i][j]);
            }
        }
    }

    shortestPathfromOnetoall("Lahore", city, arr);

    //Print all shortest Path from Lahore to all cities

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


//TEST(Graph, secondshorterstPathfromOnetoalltest) {
//    Graph* g = new Graph(30);
//    string city[25];
//    arr = ReadFromFile("GraphData.csv", city);
//
//    secondshortestPathfromOnetoall("Mansehra",city,arr);
//
//    //Print all shortest Path from Lahore to all cities
//
//    //Evaluator will verify your output from terminal
//
//    ASSERT_EQ(0, 0);
//}



TEST(Graph, shorterstPathfromalltoonetest) {
    Graph* g = new Graph(30);
    string city[25];
    arr = ReadFromFile("GraphData.csv", city);

    for (int i = 0; i < 25; i++)
    {
        g->addnode(city[i]);
    }

    for (int i = 0; i < g->noOfVertices; i++)
    {
        for (int j = 0; j < g->noOfVertices; j++)
        {
            if (arr[i][j] != 0)
            {
                g->addEdge1(city[i], city[j], arr[i][j]);
            }
        }
    }

    for (int i = 0; i < 25; i++)
    {
        cout << endl << endl;
        ShortestRoutefrompair(city[i], "Islamabad", city, arr);                     // Uses to same function that finds shortest path between 2 places. The second Argument is the place to where all paths are needed to be found 
    }



    //Print all shortest Path from  all cities to Lahore

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


//TEST(Graph, secondshorterstPathfromalltoonetest) {
//    Graph* g;
//    arr = ReadFromFile();
//    secondshortestPathfromalltoone("Lahore");
//
//    //Print all shortest Path from  all cities to Lahore
//
//    //Evaluator will verify your output from terminal
//
//    ASSERT_EQ(0, 0);
//}
//
//


TEST(Graph, ShortestRoutefrompairtest) {
    Graph* g = new Graph(30);
    string city[25];
    arr = ReadFromFile("GraphData.csv", city);

    for (int i = 0; i < 25; i++)
    {
        g->addnode(city[i]);
    }

    for (int i = 0; i < g->noOfVertices; i++)
    {
        for (int j = 0; j < g->noOfVertices; j++)
        {
            if (arr[i][j] != 0)
            {
                g->addEdge1(city[i], city[j], arr[i][j]);
            }
        }
    }


    string s1 = "Mansehra-> Murree-> Islamabad";
    string s2 = ShortestRoutefrompair("Mansehra", "Islamabad", city, arr);

    ASSERT_EQ(0, s1.compare(s2));
}





//TEST(Graph, secondShortestRoutefrompairtest) {
//    Graph* g;
//    arr = ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
//    //declared arraycount and V global for ease
//    string s1 = "Mansehra-> Hassan Abdal-> Islamabad";
//    string s2 = secondShortestRoutefrompair("Mansehra", "Islamabad");
//
//    ASSERT_EQ(0, s1.compare(s2));
//}

