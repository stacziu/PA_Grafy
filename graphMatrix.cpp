//
// Created by stasi on 06.04.2025.
//

#include "graphMatrix.h"
GraphMatrix::GraphMatrix(int size) {
    V = size;
    adjMatrix.resize(V, std::vector<int>(V,0));
}

void GraphMatrix::addEdge(int src, int dst, int weight) {
    if (checkEdge(src,dst)) {
        return;
    }
    adjMatrix[src][dst] = weight;
    adjMatrix[dst][src] = weight;
}

bool GraphMatrix::checkEdge(int src, int dst) {
    if (adjMatrix[src][dst] != 0)
        return true;
    else
    return false;
}

void GraphMatrix::print() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "Adjacency matrix: " << std::endl;
    std::cout << "   ";

    for (int i = 0; i < V; i++) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << i << "  ";
    }

    std::cout << std::endl;

    for (int i = 0; i < V; i++) {
        std::cout << i << "  ";

        for (int j = 0; j < V; j++) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            std::cout << adjMatrix[i][j] << "  ";
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}



std::vector<int> GraphMatrix::Dijkstra(int src) {
    std::vector<bool> visited(V,false);
    std::vector<int> distance(V,INT_MAX);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<>> nodes;

    distance[src] = 0;
    nodes.push({src,0});

    while(!nodes.empty()) {
        int u = nodes.top().first;
        nodes.pop();

        if(visited[u])
            continue;
        else
        visited[u] = true;

        for(int j = 0; j < V; j++) {
            if(adjMatrix[u][j] != 0 && distance[u] + adjMatrix[u][j] < distance[j]) {
                distance[j] = distance[u] + adjMatrix[u][j];
                nodes.push({j,distance[j]});
            }
        }
    }

    std::cout << "Dijkstra algorithm using matrix\n";
    for(int i = 0; i < V; i++) {
        std::cout << "Shortest path from " << src << " to " << i << " is: " << distance[i] << std::endl;
    }
    return distance;
}

int GraphMatrix::firstSrc() {
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(adjMatrix[i][j] != 0){
                return i;
            }
        }
    }
    return -1;
}
