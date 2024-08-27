#include "Algorithms.hpp"
#include <queue>
#include <algorithm>
#include <sstream>
#include <climits>
#include <limits>

using namespace ariel;

// Helper function for cycle detection using DFS with parent tracking
bool isCycleHelper(int v, const vector<vector<int>>& adjMatrix, vector<bool>& visited, vector<int>& parent, int& cycle_start, int& cycle_end) {
    visited[v] = true;

    for (int neighbor = 0; neighbor < adjMatrix.size(); ++neighbor) {
        if (adjMatrix[v][neighbor] > 0) { // Check if there's an edge
            if (!visited[neighbor]) {
                parent[neighbor] = v;
                if (isCycleHelper(neighbor, adjMatrix, visited, parent, cycle_start, cycle_end))
                    return true;
            } else if (neighbor != parent[v]) {
                // If an adjacent vertex is visited and not the parent of the current vertex, then there is a cycle
                cycle_start = neighbor;
                cycle_end = v;
                return true;
            }
        }
    }
    return false;
}

// Checks if the graph is connected using BFS
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
    
    // Check if all vertices were visited
    for(bool v : visited){
        if(!v){return false;}
    }

    return true;
}

// Detects if the graph contains a cycle using DFS with parent tracking
bool Algorithms::isContainsCycle(const Graph &g) {
    size_t numV = g.getVertices();
    vector<bool> visited(numV, false);
    vector<int> parent(numV, -1);
    int cycle_start = -1, cycle_end = -1;
    const vector<vector<int>>& adjMatrix = g.getAdjMatrix();

    for (size_t i = 0; i < numV; ++i) {
        if (!visited[i] && isCycleHelper(static_cast<int>(i), adjMatrix, visited, parent, cycle_start, cycle_end)) {
            if (cycle_start != -1) {
                vector<int> cycle;
                cycle.push_back(cycle_start);
                for (int v = cycle_end; v != cycle_start; v = parent[v]) {
                    cycle.push_back(v);
                }
                cycle.push_back(cycle_start);
                reverse(cycle.begin(), cycle.end());

                cout << "The cycle is: ";
                for (size_t j = 0; j < cycle.size(); ++j) {
                    if (j > 0) cout << "->";
                    cout << cycle[j];
                }
                cout << endl;
            }
            return true;
        }
    }
    return false;
}

// Finds the shortest path using a modified Dijkstra's algorithm (assumes non-negative weights)
string Algorithms::shortestPath(const Graph &g, size_t start, size_t end) {
    int numV = g.getVertices();
    if (start == end) {return to_string(start);}

    vector<int> distance(numV, INT_MAX);
    vector<int> predecessor(numV, -1);
    vector<bool> visited(numV, false);

    distance[start] = 0;

    for (int count = 0; count < numV - 1; ++count) {
        // Find the vertex with the minimum distance that hasn't been visited
        int minDist = INT_MAX;
        int u = -1;

        for (int v = 0; v < numV; ++v) {
            if (!visited[v] && distance[v] <= minDist) {
                minDist = distance[v];
                u = v;
            }
        }

        // If no vertex was found, break out of the loop
        if (u == -1) break;

        visited[u] = true;

        // Relaxation step
        for (int v = 0; v < numV; ++v) {
            int weight = g.getAdjMatrix()[u][v];
            // Check if the current path is shorter than the known path
            if (weight > 0 && !visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                // Decrease key operation: updating the distance to a smaller value
                distance[v] = distance[u] + weight;
                predecessor[v] = u;  // Update the predecessor
            }
        }
    }

    if (distance[end] == INT_MAX) {
        return "-1";
    }

    vector<int> path;
    for (int track = static_cast<int>(end); track != -1; track = predecessor[track]) {
        path.push_back(track);
    }
    reverse(path.begin(), path.end());

    stringstream pathStream;
    for (size_t j = 0; j < path.size(); ++j) {
        if (j > 0) {
            pathStream << "->";
        }
        pathStream << path[j];
    }

    return pathStream.str();
}

// Checks if the graph is bipartite using BFS to color the graph
string Algorithms::isBipartite(const Graph &g) {
    size_t numV = g.getVertices();
    if (numV == 0) return "The graph is bipartite: A={}, B={}"; // An empty graph is trivially bipartite

    vector<int> color(numV, -1);  // -1 indicates uncolored
    queue<size_t> q;
    const vector<vector<int>>& adjMatrix = g.getAdjMatrix();

    // This loop ensures that we cover disconnected components as well
    for (size_t start = 0; start < numV; ++start) {
        if (color[start] == -1) {  // If this vertex has not been colored, it means it's a new component
            color[start] = 0;
            q.push(start);

            while (!q.empty()) {
                size_t u = q.front();
                q.pop();

                for (size_t v = 0; v < numV; ++v) {
                    if (adjMatrix[u][v] > 0) {  // Check if there's an edge between u and v
                        if (color[v] == -1) {  // If vertex is uncolored, color it with alternate color
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {  // If the neighbor has the same color, graph is not bipartite
                            return "0";  // Return "0" indicating not bipartite
                        }
                    }
                }
            }
        }
    }

    // Collect and return bipartite sets A and B
    stringstream ss;
    ss << "The graph is bipartite: A={";
    bool first = true;
    for (size_t i = 0; i < numV; ++i) {
        if (color[i] == 0) {
            if (!first) ss << ", ";
            ss << i;
            first = false;
        }
    }
    ss << "}, B={";
    first = true;
    for (size_t i = 0; i < numV; ++i) {
        if (color[i] == 1) {
            if (!first) ss << ", ";
            ss << i;
            first = false;
        }
    }
    ss << "}";
    return ss.str();
}

// Detects negative weight cycles using the Bellman-Ford algorithm
string Algorithms::negativeCycle(const Graph &g) {
     size_t numV = g.getVertices();
    const vector<vector<int>>& matrix = g.getAdjMatrix();

    // Initialize distances to infinity, except for a starting point (arbitrarily chosen as vertex 0)
    std::vector<int> dist(numV, numeric_limits<int>::max());
    if (numV > 0)
        dist[0] = 0;

    // Relax edges up to V-1 times
    for (size_t i = 0; i < numV - 1; i++) {
        for (size_t u = 0; u < numV; u++) {
            for (size_t v = 0; v < numV; v++) {
                if (matrix[u][v] != 0) { // There is an edge from u to v
                    int weight = matrix[u][v];
                    if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }
    }

    // Check for negative weight cycle
    for (size_t u = 0; u < numV; u++) {
        for (size_t v = 0; v < numV; v++) {
            if (matrix[u][v] != 0) { // There is an edge from u to v
                int weight = matrix[u][v];
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v]) {
                    return "The graph contains a negative weight cycle.";
                }
            }
        }
    }

    return "No negative weight cycle found.";

}