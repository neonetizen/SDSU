#include "graph.h"

#include <fstream>
#include <iostream>

// Load the graph from a file
bool Graph::loadGraphFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        return false;
    }

    int numEdges;
    infile >> numNodes >> numEdges;

    adjMatrix.assign(numNodes, std::vector<int>(numNodes, INF));

    int node1, node2, weight;

    // Implement the adjacency matrix setup
    while (infile >> node1 >> node2 >> weight) {
        adjMatrix[node1-1][node2-1] = weight;
        adjMatrix[node2-1][node1-1] = weight;
    }

    // Comment this line before submission
    // std::cout << "T0DO: Implement adjacency matrix initialization here.\n";

    infile.close();
    return true;
}



// Prim's algorithm to find the MST
int Graph::primMST(std::vector<int>& mstStart, std::vector<int>& mstEnd) {
    // Placeholder for visited nodes and minimum weight initialization
    std::vector<bool> visited(numNodes, false);
    std::vector<std::tuple<int, int, int>> minHeap;
    int totalCost = 0;

    // Steps:
    // 1. Initialize visited array and minWeight array
    // 2. Start from node 1
    // 3. Use a loop to find the minimum weight edge at each step
    // 4. Update MST edges (mstStart and mstEnd vectors)
    // 5. Return the total cost of the MST

    visited[0] = true;
    // visits the first row of adjMatrix for non-INF values to add to potential valid edges
    for (int i=0; i<numNodes; ++i) {
        if (adjMatrix[0][i] < INF && i != 0) {
            minHeap.emplace_back(adjMatrix[0][i], 0, i);
        }
    }

    /* process all edges until they are not needed
     * after each iteration, smallest needed edge is popped out */
    while (!minHeap.empty()) {
        int minIndex = 0;
        // finds the minimum weight edge
        for (size_t i=0; i<minHeap.size(); ++i) {
            if (std::get<0>(minHeap[i]) < std::get<0>(minHeap[minIndex])) {
                minIndex = i;
            }
        }
        // destructuring minimum weight edge back into weight, from node, and destination node
        auto [weight, from, to] = minHeap[minIndex];
        minHeap.erase(minHeap.begin() + minIndex);
        // skips already visited nodes
        if (visited[to])
            continue;
        // updates the MST and visited nodes
        mstStart.push_back(from+1);
        mstEnd.push_back(to+1);
        totalCost += weight;
        visited[to] = true;
        // as before, adds new edges to the minheap to be processed through the while loop
        for (int i=0; i<numNodes; ++i) {
            if (!visited[i] && adjMatrix[to][i] < INF) {
                minHeap.emplace_back(adjMatrix[to][i], to, i);
            }
        }
    }

    return totalCost;
}
