//
// Created by stasi on 07.05.2024.
//

#ifndef A2_GRAPH_H
#define A2_GRAPH_H
#include <vector>



class Graph {
public:
    virtual ~Graph() = default;

    virtual void addEdge(int src, int dst, int weight) = 0;
    virtual void print() = 0;
    virtual bool checkEdge(int src, int dst) = 0;
    virtual std::vector<int> Dijkstra(int src) = 0;

};


#endif //A2_GRAPH_H
