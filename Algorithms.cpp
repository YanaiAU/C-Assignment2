/*
215011537
idfyanai@gmail.com
*/
#include "Algorithms.hpp"
#include <queue>
#include <stack>
#include <limits>
#include <iostream>
#include <algorithm>

namespace ariel
{
    bool Algorithms::isConnected(const Graph &g)
    {
        const auto &matrix = g.getAdjacencyMatrix();
        size_t n = matrix.size();
        std::vector<bool> visited(n, false);
        std::stack<size_t> stack;

        stack.push(0);
        visited[0] = true;

        while (!stack.empty())
        {
            size_t node = stack.top();
            stack.pop();

            for (size_t i = 0; i < n; ++i)
            {
                if (matrix[node][i] != 0 && !visited[i])
                {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }

        for (bool v : visited)
        {
            if (!v)
                return false;
        }

        return true;
    }

    std::string Algorithms::shortestPath(const Graph &g, int start, int end)
    {
        const auto &matrix = g.getAdjacencyMatrix();
        size_t n = matrix.size();
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::vector<int> pred(n, -1);
        dist[static_cast<size_t>(start)] = 0;

        for (size_t k = 0; k < n - 1; ++k)
        {
            for (size_t i = 0; i < n; ++i)
            {
                for (size_t j = 0; j < n; ++j)
                {
                    if (matrix[i][j] != 0 && dist[i] != std::numeric_limits<int>::max() &&
                        dist[i] + matrix[i][j] < dist[j])
                    {
                        dist[j] = dist[i] + matrix[i][j];
                        pred[j] = static_cast<int>(i);
                    }
                }
            }
        }

        if (dist[static_cast<size_t>(end)] == std::numeric_limits<int>::max())
            return "-1";

        std::vector<int> path;
        for (int at = end; at != -1; at = pred[static_cast<size_t>(at)])
        {
            path.push_back(at);
        }
        std::reverse(path.begin(), path.end());

        std::string result;
        for (size_t i = 0; i < path.size(); ++i)
        {
            result += std::to_string(path[i]);
            if (i < path.size() - 1)
                result += "->";
        }

        return result;
    }

    bool dfsCycleDetect(const std::vector<std::vector<int>> &matrix, std::vector<int> &visited, size_t v, size_t parent)
    {
        visited[v] = 1;
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            if (matrix[v][i] != 0)
            {
                if (!visited[i])
                {
                    if (dfsCycleDetect(matrix, visited, i, v))
                        return true;
                }
                else if (i != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool Algorithms::isContainsCycle(const Graph &g)
    {
        const auto &matrix = g.getAdjacencyMatrix();
        size_t n = matrix.size();
        std::vector<int> visited(n, 0);

        for (size_t i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                if (dfsCycleDetect(matrix, visited, i, static_cast<size_t>(-1)))
                    return true;
            }
        }

        return false;
    }

    std::string Algorithms::isBipartite(const Graph &g)
    {
        const auto &matrix = g.getAdjacencyMatrix();
        size_t n = matrix.size();
        std::vector<int> colors(n, -1);

        auto bfs = [&](size_t src, int color) -> bool
        {
            std::queue<size_t> q;
            q.push(src);
            colors[src] = color;

            while (!q.empty())
            {
                size_t u = q.front();
                q.pop();

                for (size_t v = 0; v < n; ++v)
                {
                    if (matrix[u][v] != 0 && colors[v] == -1)
                    {
                        colors[v] = 1 - colors[u];
                        q.push(v);
                    }
                    else if (matrix[u][v] != 0 && colors[v] == colors[u])
                    {
                        return false;
                    }
                }
            }
            return true;
        };

        for (size_t i = 0; i < n; ++i)
        {
            if (colors[i] == -1)
            {
                if (!bfs(i, 0))
                {
                    return "0";
                }
            }
        }

        std::string result = "The graph is bipartite: A={";
        bool firstA = true, firstB = true;
        for (size_t i = 0; i < n; ++i)
        {
            if (colors[i] == 0)
            {
                if (!firstA)
                    result += ", ";
                result += std::to_string(i);
                firstA = false;
            }
        }
        result += "}, B={";
        for (size_t i = 0; i < n; ++i)
        {
            if (colors[i] == 1)
            {
                if (!firstB)
                    result += ", ";
                result += std::to_string(i);
                firstB = false;
            }
        }
        result += "}";

        return result;
    }

    std::string Algorithms::negativeCycle(const Graph &g)
    {
        const auto &matrix = g.getAdjacencyMatrix();
        size_t n = matrix.size();
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        dist[0] = 0;

        for (size_t k = 0; k < n - 1; ++k)
        {
            for (size_t i = 0; i < n; ++i)
            {
                for (size_t j = 0; j < n; ++j)
                {
                    if (matrix[i][j] != 0 && dist[i] != std::numeric_limits<int>::max() &&
                        dist[i] + matrix[i][j] < dist[j])
                    {
                        dist[j] = dist[i] + matrix[i][j];
                    }
                }
            }
        }

        for (size_t i = 0; i < n; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (matrix[i][j] != 0 && dist[i] != std::numeric_limits<int>::max() &&
                    dist[i] + matrix[i][j] < dist[j])
                {
                    return "Negative cycle exists";
                }
            }
        }

        return "No negative cycle";
    }
}
