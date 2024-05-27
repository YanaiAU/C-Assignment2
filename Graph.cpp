#include "Graph.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace ariel {
    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        size_t size = matrix.size();
        for (unsigned int i = 0; i < matrix.size(); i++) {
            if (size != matrix[i].size()) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
            if (matrix[i][i] != 0){
            	throw std::invalid_argument("Invalid graph: Can't have vertices that connect to themselves");
            }
        }
        adjacencyMatrix = matrix;
    }

    void Graph::printGraph() const {
        size_t vertices = adjacencyMatrix.size();
        size_t edges = 0;
        for (const auto& row : adjacencyMatrix) {
            for (int val : row) {
                if (val != 0) {
                    edges++;
                }
            }
        }
        std::cout << "Graph with " << vertices << " vertices and " << edges / 2 << " edges." << std::endl;
    }

    int Graph::getEdgeNum() const{
    	int counter = 0;
    	for(unsigned int i = 0; i < adjacencyMatrix.size(); i++){
    	    for(unsigned int j = 0; j < adjacencyMatrix.size(); j++){
    	    	if(adjacencyMatrix[i][j] != 0){
    	    	    counter++;
    	    	}
    	    }
    	}
    	return counter / 2;
    }
    unsigned int Graph::getSize() const{
    	return this->getAdjacencyMatrix().size();
    }
    const int Graph::getEdge(unsigned int x, unsigned int y){
    	if(x >= adjacencyMatrix.size() || y >= adjacencyMatrix.size()){
    		throw std::out_of_range("Invalid coordinates: Out of range");
    	}
    	return adjacencyMatrix[x][y];
    }
     std::vector<std::vector<int>> Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }



    Graph &Graph::operator+=(const Graph &g) {
        if (adjacencyMatrix.size() != g.adjacencyMatrix.size()) {
            throw std::invalid_argument("Graphs must be of the same size.");
        }
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                adjacencyMatrix[i][j] += g.adjacencyMatrix[i][j];
                j++;
            }
            i++;
        }
        return *this;
    }

    Graph Graph::operator+(const Graph &g) {
        Graph result = *this;
        result += g;
        return result;
    }

    Graph &Graph::operator++() { // Prefix increment
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                ++adjacencyMatrix[i][j];
                j++;
            }
            i++;
        }
        return *this;
    }

    Graph Graph::operator++(int) { // Postfix increment
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    Graph &Graph::operator+(const int num) {
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                adjacencyMatrix[i][j] += num;
                j++;
            }
            i++;
        }
        return *this;
    }

    Graph Graph::operator+() {
        return *this;
    }

    Graph &Graph::operator-=(const Graph &g) {
        if (adjacencyMatrix.size() != g.adjacencyMatrix.size()) {
            throw std::invalid_argument("Graphs must be of the same size.");
        }
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                adjacencyMatrix[i][j] -= g.adjacencyMatrix[i][j];
                j++;
            }
            i++;
        }
        return *this;
    }

    Graph Graph::operator-(const Graph &g) {
        Graph result = *this;
        result -= g;
        return result;
    }

    Graph &Graph::operator--() { // Prefix decrement
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                --adjacencyMatrix[i][j];
                j++;
            }
            i++;
        }
        return *this;
    }

    Graph Graph::operator--(int) { // Postfix decrement
        Graph temp = *this;
        --(*this);
        return temp;
    }

    Graph &Graph::operator-(const int num) {
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                adjacencyMatrix[i][j] -= num;
                j++;
            }
            i++;
        }
        return *this;
    }

    Graph Graph::operator-() {
        Graph result;
        result.adjacencyMatrix = adjacencyMatrix;
        unsigned int i = 0;
        while (i < result.adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < result.adjacencyMatrix[i].size()) {
                result.adjacencyMatrix[i][j] = -result.adjacencyMatrix[i][j];
                j++;
            }
            i++;
        }
        return result;
    }

    Graph Graph::operator*(const Graph& g) const {
        if (adjacencyMatrix.size() != g.adjacencyMatrix.size()) {
            throw std::invalid_argument("Graphs must be of the same size.");
        }
        Graph result;
        size_t size = adjacencyMatrix.size();
        result.adjacencyMatrix.resize(size, std::vector<int>(size, 0));

        unsigned int i = 0;
        while (i < size) {
            unsigned int j = 0;
            while (j < size) {
                unsigned int k = 0;
                while (k < size) {
                    result.adjacencyMatrix[i][j] += adjacencyMatrix[i][k] * g.adjacencyMatrix[k][j];
                    k++;
                }
                j++;
            }
            i++;
        }
        return result;
    }

    Graph &Graph::operator*=(const Graph &g) {
        *this = *this * g;
        return *this;
    }

    Graph &Graph::operator*=(int num) {
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                adjacencyMatrix[i][j] *= num;
                j++;
            }
            i++;
        }
        return *this;
    }

    Graph Graph::operator*(int num) const {
        Graph result = *this;
        result *= num;
        return result;
    }

    Graph &Graph::operator/(int num) {
        if (num == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                adjacencyMatrix[i][j] /= num;
                j++;
            }
            i++;
        }
        return *this;
    }

    Graph &Graph::operator/=(int num) {
        if (num == 0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        unsigned int i = 0;
        while (i < adjacencyMatrix.size()) {
            unsigned int j = 0;
            while (j < adjacencyMatrix[i].size()) {
                adjacencyMatrix[i][j] /= num;
                j++;
            }
            i++;
        }
        return *this;
    }

    // Comparison operators
    bool Graph::operator==(const Graph& other) const {
        return adjacencyMatrix == other.adjacencyMatrix;
    }

    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

    bool Graph::operator<(const Graph& other) const {
        return getEdgeNum() < other.getEdgeNum();
    }

    bool Graph::operator<=(const Graph& other) const {
        return *this < other || *this == other;
    }

    bool Graph::operator>(const Graph& other) const {
        return !(*this <= other);
    }

    bool Graph::operator>=(const Graph& other) const {
        return !(*this < other);
    }

    ostream &operator<<(ostream &os, const Graph &g){
    	size_t g_size = g.getSize();
    	for(unsigned int i = 0; i < g_size; i++){
    	    os << "[";
    	    for(unsigned int j = 0; j < g_size; j++){
    	    	os << g.getAdjacencyMatrix()[i][j];
    	    	if(j != g_size - 1){
    	    	    os << ",";
    	    	}
    	    }
    	    os << "]\n";
    	}
    	return os;
    }
}








