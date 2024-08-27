#include "Graph.hpp"
#include <iostream>

namespace ariel {

    // Load the graph from a given adjacency matrix
    void Graph::loadGraph(const vector<vector<int>> &graph) {
        // Validate that the input graph is a square matrix
        for (size_t i = 0; i < graph.size(); ++i) {
            if (graph.size() == 0 || graph[i].size() != graph.size()) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }

        vertices = graph.size();  // Set the number of vertices
        for (size_t i = 0; i < graph.size(); ++i) {
            for (size_t j = 0; j < graph[0].size(); ++j) {
                if (graph[i][j] > 0) { this->edges += 1; }  // Count the number of edges
            }
        }
        adjMatrix = graph;  // Assign the adjacency matrix
    }

    // Print information about the graph
    void Graph::printGraph() const {
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;
    }

    // Get the number of vertices
    int Graph::getVertices() const {
        return this->vertices;
    }

    // Get the number of edges (note: incorrect in original code, should return edges)
    int Graph::getEdges() const {
        return this->edges;  // Corrected to return the number of edges
    }

    // Get the adjacency matrix
    const vector<vector<int>> & Graph::getAdjMatrix() const {
        return this->adjMatrix;
    }

    // Prefix increment operator: increment all edge weights by 1
    Graph Graph::operator++() {
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] > 0) { adjMatrix[i][j]++; }
            }
        }
        return *this;
    }

    // Postfix increment operator: calls prefix increment
    Graph Graph::operator++(int) {
        return ++(*this);
    }

    // Prefix decrement operator: decrement all edge weights by 1
    Graph Graph::operator--() {
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] > 0) { adjMatrix[i][j]--; }
            }
        }
        return *this;
    }

    // Postfix decrement operator: calls prefix decrement
    Graph Graph::operator--(int) {
        return --(*this);
    }

    // Addition of two graphs: returns a new graph with combined edge weights
    Graph Graph::operator+(const Graph &g) {
        if (vertices != g.vertices) {
            throw invalid_argument("Cannot add graphs of different sizes.");
        }
        Graph result = *this;
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                result.adjMatrix[i][j] = this->adjMatrix[i][j] + g.adjMatrix[i][j];
            }
        }
        return result;
    }

    // Addition assignment operator: adds another graph to the current one
    Graph Graph::operator+=(const Graph &g) {
        return *this = *this + g;
    }

    // Subtraction of two graphs: returns a new graph with subtracted edge weights
    Graph Graph::operator-(const Graph &g) {
        if (vertices != g.vertices) {
            throw invalid_argument("Cannot subtract graphs of different sizes.");
        }
        Graph result = *this;
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                result.adjMatrix[i][j] = this->adjMatrix[i][j] - g.adjMatrix[i][j];
            }
        }
        return result;
    }

    // Subtraction assignment operator: subtracts another graph from the current one
    Graph Graph::operator-=(const Graph &g) {
        return *this = *this - g;
    }

    // Multiplication of two graphs: returns a new graph resulting from matrix multiplication
    Graph Graph::operator*(const Graph &g) {
        if (vertices != g.vertices) {
            throw invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }

        vector<vector<int>> resultM(vertices, vector<int>(vertices, 0));
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                for (size_t k = 0; k < vertices; k++)
                    resultM[i][j] += this->adjMatrix[i][k] + g.adjMatrix[k][j];
            }
        }
        Graph Result;
        Result.loadGraph(resultM);
        return Result;
    }

    // Multiplication assignment operator: multiplies the current graph by another graph
    Graph Graph::operator*=(const Graph &g) {
        return *this = *this * g;
    }

    // Scalar multiplication: returns a new graph with all edge weights multiplied by a scalar
    Graph Graph::operator*(int scalar) {
        Graph result = *this;

        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                result.adjMatrix[i][j] *= scalar;
            }
        }
        return result;
    }

    // Scalar multiplication assignment operator: multiplies all edge weights by a scalar
    Graph Graph::operator*=(int scalar) {
        return *this = *this * scalar;
    }

    // Scalar division: returns a new graph with all edge weights divided by a scalar
    Graph Graph::operator/(int scalar) {
        Graph result = *this;
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                result.adjMatrix[i][j] /= scalar;
            }
        }
        return result;
    }

    // Scalar division assignment operator: divides all edge weights by a scalar
    Graph Graph::operator/=(int scalar) {
        return *this = *this / scalar;
    }

    // Equality comparison operator: checks if two graphs are identical
    bool Graph::operator==(const Graph &g) const {
        return vertices == g.vertices && adjMatrix == g.adjMatrix;
    }

    // Inequality comparison operator: checks if two graphs are not identical
    bool Graph::operator!=(const Graph& g) const {
        return !(*this == g);
    }

    // Less-than comparison operator: compares two graphs based on the number of edges
    bool Graph::operator<(const Graph& g) const {
        if (vertices != g.vertices) return false;
        return edges < g.edges;
    }

    // Less-than-or-equal comparison operator: checks if a graph is less than or equal to another graph
    bool Graph::operator<=(const Graph &g) const {
        return *this == g || *this < g;
    }

    // Greater-than comparison operator: compares two graphs based on the number of edges
    bool Graph::operator>(const Graph& g) const {
        if (vertices != g.vertices) return false;
        return edges > g.edges;
    }

    // Greater-than-or-equal comparison operator: checks if a graph is greater than or equal to another graph
    bool Graph::operator>=(const Graph &g) const {
        return *this == g || *this > g;
    }
}