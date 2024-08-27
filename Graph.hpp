#include <iostream>
#include <vector>

#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;
namespace ariel {

    class Graph {
    private:
        int vertices;
        int edges;
        vector<vector<int>> adjMatrix;

    public:
        Graph():vertices(0),edges(0){}
        void loadGraph(const vector<vector<int>> &graph);
        void printGraph() const;

        int getVertices() const;
        int getEdges() const;
        const vector<vector<int>> &getAdjMatrix() const;

        Graph operator++();// prefix increment
        Graph operator++(int);// postfix increment
        Graph operator--();// prefix decrement
        Graph operator--(int);// postfix decrement

        Graph operator +(const Graph & g);
        Graph operator +=(const Graph & g);
        Graph operator -(const Graph & g);
        Graph operator -=(const Graph & g);
        Graph operator *(const Graph & g);
        Graph operator *=(const Graph & g);
        Graph operator *(int scalar);
        Graph operator *=(int scalar);
        Graph operator /(int scalar);
        Graph operator /=(int scalar);

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