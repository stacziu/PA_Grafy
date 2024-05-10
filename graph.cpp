//
// Created by stasi on 07.05.2024.
//
#include "graph.h"

Graph::Graph(int size) {
    this->V = size;
    AdjMatrix.resize(V, std::vector<int>(V,0));
    AdjList.resize(V);
}

void Graph::addEdge(int src, int dst, int weight) {
    if(checkEdge(src,dst)) {
        return;
    }
    AdjMatrix[src][dst] = weight;
    AdjMatrix[dst][src] = weight;

    AdjList[src].push_back({dst,weight});
    AdjList[dst].push_back({src,weight});
}

bool Graph::checkEdge(int src, int dst) {
    if(AdjMatrix[src][dst] != 0)
        return true;
    else
    return false;
}

void Graph::printMatrix() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "Adjacency matrix: " << std::endl;
    std::cout << "   ";

    for(int i = 0; i < V; i++) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << i << "  ";
    }

    std::cout << std::endl;

    for(int i = 0; i < V; i++) {
        std::cout << i << "  ";

        for(int j = 0; j < V; j++) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            std::cout << AdjMatrix[i][j] << "  ";
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void Graph::printList() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "Adjacency list: " << std::endl;

    for(int i = 0; i < V; i++) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << i;

        for (auto x: AdjList[i]) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            std::cout << "-> (V:" << x.first << ", w:" << x.second << ")";
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}


std::vector<int> Graph::DijkstraByMatrix(int src) {
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
            if(AdjMatrix[u][j] != 0 && distance[u] + AdjMatrix[u][j] < distance[j]) {
                distance[j] = distance[u] + AdjMatrix[u][j];
                nodes.push({j,distance[j]});
            }
        }
    }

    /*std::cout << "Dijkstra algorithm using matrix\n";
    for(int i = 0; i < V; i++) {
        std::cout << "Shortest path from " << src << " to " << i << " is: " << distance[i] << std::endl;
    }*/
    return distance;
}

std::vector<int> Graph::DijkstraByList(int src) {
    std::vector<int> distance(V, INT_MAX);
    std::vector<bool> visited(V, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> nodes;

    distance[src] = 0;
    nodes.push({src, 0});

    while (!nodes.empty()) {
        int u = nodes.top().first;
        nodes.pop();

        if(visited[u]) continue;
        visited[u] = true;

        for (auto x : AdjList[u]) {
            int dst = x.first;
            int weight = x.second;
            if(distance[u] + weight < distance[dst]){
                distance[dst] = distance[u] + weight;
                nodes.push({dst, distance[dst]});
            }
        }

    }

    /*std::cout << "Dijkstra algorithm using list\n";
    for (int i = 0; i < V; i++) {
        std::cout << "Shortest path from " << src << " to " << i << " is " << distance[i] << std::endl;
    }*/
    return distance;
}

float Graph::getDensity() {
    int max_edges = V * (V - 1) / 2;
    int actual_edges = 0;
    for (int i = 0; i < V; i++) {
        actual_edges += AdjList[i].size();
    }
    actual_edges /= 2;

    return (float)actual_edges / max_edges * 100;
}

int Graph::firstSrc() {
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(AdjMatrix[i][j] != 0){
                return i;
            }
        }
    }

}
