#ifndef  GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
    public:
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        std::vector<std::vector<int>> getAdjacencyMatrix() const;
        int getEdgeNum() const;
        unsigned int getSize() const;
        const int getEdge(unsigned int x, unsigned int y);

        Graph &operator+=(const Graph &g);
        Graph operator+(const Graph &g);
        Graph operator++(int);
        Graph &operator++();
        Graph &operator+(int num);
        Graph operator+();

        Graph &operator-=(const Graph &g);
        Graph &operator--();
        Graph operator--(int);
        Graph operator-(const Graph &g);
        Graph &operator-(int num);
        Graph operator-();

        Graph operator*(const Graph &g) const;
        Graph &operator*=(const Graph &g);
        Graph &operator*=(int num);
        Graph operator*(int num) const;

        Graph &operator/(int num);
        Graph &operator/=(int num);

        bool operator==(const Graph &g) const;
        bool operator!=(const Graph &g) const;
        bool operator>(const Graph &g) const;
        bool operator>=(const Graph &g) const;
        bool operator<(const Graph &g) const;
        bool operator<=(const Graph &g) const;

        friend ostream &operator<<(ostream &os, const Graph &g);

    };
}

#endif
