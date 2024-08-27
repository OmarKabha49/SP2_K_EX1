#include "string"
#include "Graph.hpp"

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP


using namespace std;


namespace ariel {

    class Algorithms {
    public:
        static bool isConnected(const Graph &g);
        static bool isContainsCycle(const Graph &g);
        static string shortestPath(const Graph &g , size_t start, size_t end);
        static string isBipartite(const Graph &g);
        static string negativeCycle(const Graph& g);
    };

}

#endif
