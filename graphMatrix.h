//
// Created by stasi on 06.04.2025.
//

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
#include "graph.h"
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <windows.h>

class GraphMatrix : public Graph{
    int V;
    std::vector<std::vector<int>> adjMatrix;
public:
    GraphMatrix(int size);
    void addEdge(int src, int dst, int weight) override;
    void print() override;
    bool checkEdge(int src, int dst) override;
    std::vector<int> Dijkstra(int src) override;
    int firstSrc();
    ~GraphMatrix() override = default;
};



#endif //GRAPHMATRIX_H
