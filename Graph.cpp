#include "Graph.hpp"

#include <iostream>


namespace ariel {
    void Graph::loadGraph(const vector<vector<int>> &graph) {
        for (size_t i = 0; i < graph.size();++i){
            if(graph.size() == 0 || graph[i].size() != graph.size()) {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }

        vertices = graph.size();
        for(size_t i = 0; i < graph.size(); ++i) {
            for (size_t j = 0 ; j < graph[0].size(); ++j) {
                if(graph[i][j] > 0){this->edges+=1;}
            }
        }
        adjMatrix = graph;

    }

    void Graph::printGraph() const{
        cout << "Graph with " <<vertices<<" vertices and " <<edges<<" edges."<<endl;
    }

    int Graph::getVertices() const {
        return this->vertices;
    }

    int Graph::getEdges() const {
        return this->vertices;
    }

    const vector<vector<int>> & Graph::getAdjMatrix() const {
        return this->adjMatrix;
    }

    Graph Graph::operator++() {
        for(size_t i = 0; i < vertices; i++) {
            for(size_t j = 0; j < vertices; j++) {
                if(adjMatrix[i][j] > 0) {adjMatrix[i][j]++;}
            }
        }
        return *this;
    }

    Graph Graph::operator++(int) {return ++(*this);}

    Graph Graph::operator--() {
        for(size_t i = 0; i < vertices; i++) {
            for(size_t j = 0; j < vertices; j++) {
                if(adjMatrix[i][j] > 0) {adjMatrix[i][j]--;}
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) {return --(*this);}

    Graph Graph::operator+(const Graph &g){
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

    Graph Graph::operator+=(const Graph &g) {
        return *this = *this + g;
    }

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

    Graph Graph::operator-=(const Graph &g) {return *this = *this - g;}

    Graph Graph::operator*(const Graph &g) {
        if (vertices != g.vertices) {
            throw invalid_argument("Cannot multiply graphs of different sizes.");
        }

        vector<vector<int>> resultM(vertices, vector<int>(vertices,0));
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

    Graph Graph::operator*=(const Graph &g) {
        return *this = *this * g;
    }

    Graph Graph::operator*(int scalar) {
        Graph result = *this;

        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                result.adjMatrix[i][j]*=scalar;
            }
        }
        return result;
    }

    Graph Graph::operator*=(int scalar) {
        return *this = *this * scalar;
    }

    Graph Graph::operator/(int scalar) {
        Graph result = *this;
        for (size_t i = 0; i < vertices; i++) {
            for (size_t j = 0; j < vertices; j++) {
                result.adjMatrix[i][j]/=scalar;
            }
        }
        return result;
    }

    Graph Graph::operator/=(int scalar) {
        return *this = *this / scalar;
    }

}
