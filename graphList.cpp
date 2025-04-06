//
// Created by stasi on 06.04.2025.
//

#include "graphList.h"

GraphList::GraphList(int size) {
    V = size;
    adjList.resize(V);
}

void GraphList::addEdge(int src, int dst, int weight) {
    if(checkEdge(src,dst)) {
        return;
    }
    adjList[src].push_back({dst,weight});
    adjList[dst].push_back({src,weight});
}

bool GraphList::checkEdge(int src, int dst) {
    for (const auto& neighbor : adjList[src]) {
        if (neighbor.first == dst) {
            return true;
        }
    }
    return false;
}
void GraphList::print() {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "Adjacency list: " << std::endl;

    for(int i = 0; i < V; i++) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << i;

        for (auto x: adjList[i]) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            std::cout << "-> (V:" << x.first << ", w:" << x.second << ")";
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

std::vector<int> GraphList::Dijkstra(int src) {
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

        for (const auto& x : adjList[u]) {
            int dst = x.first;
            int weight = x.second;
            if(distance[u] + weight < distance[dst]){
                distance[dst] = distance[u] + weight;
                nodes.push({dst, distance[dst]});
            }
        }

    }

    std::cout << "Dijkstra algorithm using list\n";
    for (int i = 0; i < V; i++) {
        std::cout << "Shortest path from " << src << " to " << i << " is " << distance[i] << std::endl;
    }
    return distance;
}

//float GraphList::getDensity() {
//    int max_edges = V * (V - 1) / 2;
//    int actual_edges = 0;
//    for (int i = 0; i < V; i++) {
//        actual_edges += adjList[i].size();
//    }
//    actual_edges /= 2;
//
//    return (float)actual_edges / max_edges * 100;
//}
