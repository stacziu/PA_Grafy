//
// Created by stasi on 06.04.2025.
//

#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <vector>
#include "graph.h"
#include <iostream>
#include <list>
#include <climits>
#include <windows.h>
#include <queue>

class GraphList : public Graph {
    int V;
    std::vector<std::list<std::pair<int,int>>> adjList;
public:
    explicit GraphList(int size);
    void addEdge(int src, int dst, int weight) override;
    void print() override;
    bool checkEdge(int src, int dst) override;
    std::vector<int> Dijkstra(int src) override;
    ~GraphList() override = default;
};



#endif //GRAPHLIST_H
