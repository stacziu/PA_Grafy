//
// Created by stasi on 07.05.2024.
//

#ifndef A2_GRAPH_H
#define A2_GRAPH_H
#include <vector>
#include <list>
#include <iostream>
#include <queue>
#include <climits>
#include <windows.h>


class Graph {
    std::vector<std::vector<int>> AdjMatrix;
    std::vector<std::list<std::pair<int,int>>> AdjList;
    int V;

public:
    Graph(int size);
    void addEdge(int src, int dst, int weight);
    void printMatrix();
    void printList();
    bool checkEdge(int src, int dst);
    std::vector<int> DijkstraByMatrix(int src);
    std::vector<int> DijkstraByList(int src);
    float getDensity();
    int firstSrc();
};


#endif //A2_GRAPH_H
