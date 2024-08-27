#include <iostream>
#include <vector>

#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;

namespace ariel {

    class Graph {
    private:
        int vertices;  // Number of vertices in the graph
        int edges;     // Number of edges in the graph
        vector<vector<int>> adjMatrix;  // Adjacency matrix representing the graph

    public:
        // Default constructor initializes an empty graph
        Graph():vertices(0),edges(0){}

        // Loads the graph from a given adjacency matrix
        void loadGraph(const vector<vector<int>> &graph);

        // Prints the graph's adjacency matrix
        void printGraph() const;

        // Getter for the number of vertices
        int getVertices() const;

        // Getter for the number of edges
        int getEdges() const;

        // Getter for the adjacency matrix
        const vector<vector<int>> &getAdjMatrix() const;

        // Overloaded operators for graph manipulations

        Graph operator++();        // Prefix increment (e.g., ++g)
        Graph operator++(int);     // Postfix increment (e.g., g++)
        Graph operator--();        // Prefix decrement (e.g., --g)
        Graph operator--(int);     // Postfix decrement (e.g., g--)

        Graph operator +(const Graph & g);      // Addition of two graphs
        Graph operator +=(const Graph & g);     // Addition assignment (e.g., g1 += g2)
        Graph operator -(const Graph & g);      // Subtraction of two graphs
        Graph operator -=(const Graph & g);     // Subtraction assignment (e.g., g1 -= g2)
        Graph operator *(const Graph & g);      // Multiplication of two graphs
        Graph operator *=(const Graph & g);     // Multiplication assignment (e.g., g1 *= g2)
        Graph operator *(int scalar);           // Scalar multiplication
        Graph operator *=(int scalar);          // Scalar multiplication assignment (e.g., g *= scalar)
        Graph operator /(int scalar);           // Scalar division
        Graph operator /=(int scalar);          // Scalar division assignment (e.g., g /= scalar)

        // Comparison operators for comparing two graphs

        bool operator==(const Graph &g) const;  // Equality comparison
        bool operator!=(const Graph &g) const;  // Inequality comparison
        bool operator<(const Graph &other) const;  // Less-than comparison
        bool operator<=(const Graph &g) const;  // Less-than-or-equal comparison
        bool operator>(const Graph &g) const;   // Greater-than comparison
        bool operator>=(const Graph &g) const;  // Greater-than-or-equal comparison

        // Friend function for outputting the graph's adjacency matrix to an output stream
        friend ostream& operator<<(ostream& os , const Graph& graph) {
            const vector<vector<int>> &mat = graph.adjMatrix;
            for (size_t i = 0; i < mat.size(); ++i) {
                os << "[";
                for(size_t j = 0; j < mat[0].size(); ++j) {
                    os << mat[i][j];
                    if(j < mat[0].size() - 1){os << ", ";}
                }
                os << "]";
                if(i != mat.size() - 1) {
                    os << ", ";
                }
            }
            return os << "\n";
        }
    };

}

#endif
