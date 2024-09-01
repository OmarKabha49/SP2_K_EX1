//kabhao47@gmail.com
#include "string"
#include "Graph.hpp"

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

using namespace std;

namespace ariel {

    class Algorithms {
    public:
        static bool isConnected(const Graph &g);           // Uses BFS to check if all vertices are reachable (connectivity check)
        static bool isContainsCycle(const Graph &g);       // Uses DFS with parent tracking to detect cycles
        static string shortestPath(const Graph &g , size_t start, size_t end);  // Uses a modified Dijkstra's algorithm for unweighted or uniformly weighted graphs
        static string isBipartite(const Graph &g);         // Uses BFS to check bipartiteness by coloring the graph
        static string negativeCycle(const Graph& g);       // Uses Bellman-Ford algorithm to detect negative weight cycles
        static bool isCycleHelper(int v, const vector<vector<int>>& adjMatrix,
                                  vector<bool>& visited, vector<int>& parent,
                                  int& cycle_start, int& cycle_end);    // Helper function for cycle detection using DFS with parent tracking

    };

}

#endif