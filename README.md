# Graph Library

## Author Information

- **Name**: Omar Kabha
- **Email**: kabhao47@gmail.com
- **ID**: 315481721

## Overview

This project implements a `Graph` class in C++, which allows for the representation of graphs using adjacency matrices. The class includes various graph algorithms, supports multiple operators for graph manipulation and comparison, and provides utility methods for managing and interacting with graphs. Additionally, the project includes a suite of tests to verify the correctness of the implemented features.

The project also includes an `Algorithms` class that provides basic graph algorithms such as checking connectivity, finding the shortest path, detecting cycles, and more.

## Files

- **Graph.hpp**: Header file containing the declaration of the `Graph` class and its member functions.
- **Graph.cpp**: Implementation file containing the definitions of the member functions of the `Graph` class.
- **Algorithms.hpp**: Header file for the `Algorithms` class, declaring various graph algorithms.
- **Algorithms.cpp**: Implementation file for the `Algorithms` class, defining algorithms for connectivity checks, pathfinding, cycle detection, and bipartiteness.
- **tests.cpp**: Test file containing unit tests for the `Graph` and `Algorithms` classes using the `doctest` framework.

## Classes

### Graph Class

Represents a graph using an adjacency matrix.

#### Private Members

- `vector<vector<int>> adjMatrix`: The adjacency matrix representation of the graph.
- `int vertices`: The number of vertices in the graph.
- `int edges`: The number of edges in the graph.

#### Public Members

##### Constructor

- `Graph()`: Default constructor initializes an empty graph.

##### Graph Manipulation Functions

- `void loadGraph(const vector<vector<int>>& matrix)`: Loads a graph from an adjacency matrix.
- `void printGraph() const`: Prints the graph's adjacency matrix.
- `const vector<vector<int>>& getAdjMatrix() const`: Returns the adjacency matrix.
- `int getVertices() const`: Returns the number of vertices in the graph.
- `int getEdges() const`: Returns the number of edges in the graph.

##### Arithmetic Operators

- `Graph operator+(const Graph& other) const`: Adds two graphs.
- `Graph& operator+=(const Graph& other)`: Adds another graph to this graph.
- `Graph operator-(const Graph& other) const`: Subtracts another graph from this graph.
- `Graph& operator-=(const Graph& other)`: Subtracts another graph from this graph.
- `Graph operator*(const Graph& other) const`: Multiplies two graphs element-wise.
- `Graph operator*(int scalar) const`: Returns a graph multiplied by a scalar.
- `Graph& operator*=(const Graph& other)`: Multiplies another graph with this graph.
- `Graph& operator*=(int scalar)`: Multiplies the graph by a scalar.
- `Graph operator/(int scalar) const`: Returns a graph divided by a scalar.
- `Graph& operator/=(int scalar)`: Divides the graph by a scalar.
- `Graph operator-() const`: Returns the negation of the graph.

##### Comparison Operators

- `bool operator==(const Graph& other) const`: Checks if two graphs are equal.
- `bool operator!=(const Graph& other) const`: Checks if two graphs are not equal.
- `bool operator<(const Graph& other) const`: Checks if this graph is less than another graph.
- `bool operator<=(const Graph& other) const`: Checks if this graph is less than or equal to another graph.
- `bool operator>(const Graph& other) const`: Checks if this graph is greater than another graph.
- `bool operator>=(const Graph& other) const`: Checks if this graph is greater than or equal to another graph.

##### Increment/Decrement Operators

- `Graph& operator++()`: Prefix increment.
- `Graph operator++(int)`: Postfix increment.
- `Graph& operator--()`: Prefix decrement.
- `Graph operator--(int)`: Postfix decrement.

##### Output Operator

- `friend ostream& operator<<(ostream& os, const Graph& graph)`: Outputs the graph's adjacency matrix.

### Algorithms Class

The `Algorithms` class provides static methods for performing graph-related algorithms.

#### Methods

- `static bool isConnected(const Graph& g)`: Checks if the graph is connected.
- `static std::string shortestPath(const Graph& g, int start, int end)`: Finds the shortest path between two vertices in the graph.
- `static bool isContainsCycle(const Graph& g)`: Checks if the graph contains a cycle and prints it if it does.
- `static std::string isBipartite(const Graph& g)`: Checks if the graph is bipartite and returns the partition.
- `static bool negativeCycle(const Graph& g)`: Checks if the graph contains a negative weight cycle.
