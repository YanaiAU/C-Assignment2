/*
215011537
idfyanai@gmail.com
*/
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>
#include <string>

namespace ariel
{
    class Algorithms
    {
    public:
        static bool isConnected(const Graph &g);
        static std::string shortestPath(const Graph &g, int start, int end);
        static bool isContainsCycle(const Graph &g);
        static std::string isBipartite(const Graph &g);
        static std::string negativeCycle(const Graph &g);
    };
}

#endif
