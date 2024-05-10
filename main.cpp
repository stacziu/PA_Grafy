#include <iostream>
#include <random>
#include <fstream>
#include <chrono>

#include "graph.h"

Graph generateRandGraph(int V, int density) {
    Graph graph(V);
    int max_edges = V * (V - 1) / 2;
    int actual_edges = (density * max_edges) / 100;

    for(int i = 0; i < actual_edges; i++) {
        bool edgeAdded = false;

        while(!edgeAdded){
            int src = rand() % V;
            int dst = rand() % V;
            while(src == dst){
                dst = rand() % V;
            }

            if(!graph.checkEdge(src, dst)){
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> distribution(1, 9);

                int weight = distribution(gen);
                graph.addEdge(src,dst,weight);
                edgeAdded = true;
            }
        }
    }

    return graph;
}

void DijkstraByMatrixTest(int V, int density, const std::string& file){
    std::ofstream results(file);
    if(!results.is_open()){
        std::cerr << "File didn't open succesfully!" << std::endl;
        return;
    }

    auto time = 0;
    for(int i = 0; i < 100; i++){
        Graph graph = generateRandGraph(V, density);
        int src = graph.firstSrc();

        auto begin = std::chrono::high_resolution_clock::now();
        graph.DijkstraByMatrix(src);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
        time += elapsed.count();
    }
    results << time / 100 << std::endl;
}

int main() {
    DijkstraByMatrixTest(10, 25, "results10_25.txt");
    DijkstraByMatrixTest(50, 25, "results50_25.txt");
    DijkstraByMatrixTest(100, 25, "results100_25.txt");
    DijkstraByMatrixTest(500, 25, "results500_25.txt");
    DijkstraByMatrixTest(1000, 25, "results1000_25.txt");

    DijkstraByMatrixTest(10, 50, "results10_50.txt");
    DijkstraByMatrixTest(50, 50, "results50_50.txt");
    DijkstraByMatrixTest(100, 50, "results100_50.txt");
    DijkstraByMatrixTest(500, 50, "results500_50.txt");
    DijkstraByMatrixTest(1000, 50, "results1000_50.txt");

    DijkstraByMatrixTest(10, 75, "results10_75.txt");
    DijkstraByMatrixTest(50, 75, "results50_75.txt");
    DijkstraByMatrixTest(100, 75, "results100_75.txt");
    DijkstraByMatrixTest(500, 75, "results500_75.txt");
    DijkstraByMatrixTest(1000, 75, "results1000_75.txt");

    DijkstraByMatrixTest(10, 99, "results10_99.txt");
    DijkstraByMatrixTest(50, 99, "results50_99.txt");
    DijkstraByMatrixTest(100, 99, "results100_99.txt");
    DijkstraByMatrixTest(500, 99, "results500_99.txt");
    DijkstraByMatrixTest(1000, 99, "results1000_99.txt");

    return 0;
}
