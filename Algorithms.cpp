#include "Algorithms.hpp"

#include <queue>
#include <algorithm>
#include <sstream>

using namespace ariel;


bool Algorithms::isConnected(const Graph &g) {
    size_t numV = g.getVertices();
    if (numV == 0){return true;}


    vector<bool> visited(numV,false);
    queue<size_t> q;

    visited[0] = true;
    q.push(0);

    while (!q.empty()){
        size_t curr = q.front();
        q.pop();

        for (size_t i = 1; i < numV; i++){
            if(g.getAdjMatrix()[curr][i] != 0 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }

    }
    for(bool v : visited){
        if(!v){return false;}
    }

    return true;
}

bool Algorithms::isContainsCycle(const Graph &g) {

}

string Algorithms::shortestPath(const Graph &g, size_t start, size_t end) {
    int numV = g.getVertices();
    if(start == end){return to_string(start);}

    vector<bool> visited(numV,false);
    vector<int> distance(numV, -1);
    vector<int> predecessor(numV, -1);

    queue<size_t> Q;
    Q.push(start);
    distance[start] = 0;
    visited[start] = true;

    while (!Q.empty()) {
        size_t curr = Q.front();
        Q.pop();

        for (size_t i = 0; i < numV ;++i) {
            if(g.getAdjMatrix()[curr][i] > 0 && !visited[i]) {
                int weight = g.getAdjMatrix()[curr][i];
                visited[i] = true;
                distance[i] = weight;
                predecessor[i] = static_cast<int>(curr);

                Q.push(i);

                if(i == end) {
                    vector<int> path;

                    for (int track  = static_cast<int>(end); track != -1; track = predecessor[track]) {
                        path.push_back(track);
                    }

                    reverse(path.begin(), path.end());

                    stringstream pathStream;
                    for (size_t j = 0; j < path.size(); ++j) {
                        if (j > 0) pathStream << "->";
                        pathStream << path[j];
                    }
                    return pathStream.str();
                }
            }
        }
    }
    return "-1";
}

string Algorithms::isBipartite(const Graph &g) {

}

string Algorithms::negativeCycle(const Graph &g) {

}


