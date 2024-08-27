
#include <iostream>
#include "Algorithms.hpp"
using namespace std;
using namespace ariel;
int main() {

    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

    Graph g;
    g.loadGraph(graph);
    string x = Algorithms::shortestPath(g,0,2);

    cout<<x<<endl;
    return 0;
}