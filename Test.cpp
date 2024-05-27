#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
using namespace ariel;


TEST_CASE("Test loadGraph") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);
}

TEST_CASE("Test printGraph") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);
    g.printGraph();
}

TEST_CASE("Test getEdgeNum - small graph") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);
    CHECK(g.getEdgeNum() == 2);
}

TEST_CASE("Test getEdgeNum - larger graph") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}
    };
    g.loadGraph(graph);
    CHECK(g.getEdgeNum() == 4);
}

TEST_CASE("Test getSize") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);
    CHECK(g.getSize() == 3);
}

TEST_CASE("Test getEdge - valid edge") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);
    CHECK(g.getEdge(0, 1) == 1);
}

TEST_CASE("Test getEdge - invalid edge") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);
    CHECK_THROWS_AS(g.getEdge(0, 3), std::out_of_range);
}

TEST_CASE("Test operator+=") {
    Graph g1;
    Graph g2;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    g1 += g2;
    CHECK(g1.getEdge(0, 1) == 2);
    CHECK(g1.getEdge(1, 2) == 2);
}

TEST_CASE("Test operator+") {
    Graph g1;
    Graph g2;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    Graph g3 = g1 + g2;
    CHECK(g3.getEdge(0, 1) == 2);
    CHECK(g3.getEdge(1, 2) == 2);
}

TEST_CASE("Test operator<<") {
    Graph g1;
    Graph g2;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    Graph g3 = g1 + g2;
    std::ostringstream oss;
    oss << g3;
    CHECK(oss.str() == "[0,2,0]\n[2,0,2]\n[0,2,0]\n");
}

TEST_CASE("Test operator-") {
    Graph g1;
    Graph g2;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    Graph g3 = g1 - g2;
    CHECK(g3.getEdge(0, 1) == 0);
    CHECK(g3.getEdge(1, 2) == 0);
}

TEST_CASE("Test operator-=") {
    Graph g1;
    Graph g2;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    g1 -= g2;
    CHECK(g1.getEdge(0, 1) == 0);
    CHECK(g1.getEdge(1, 2) == 0);
}

TEST_CASE("Test unary + operator") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    Graph g_pos = +g;
    CHECK(g_pos.getEdge(0, 1) == 1);
    CHECK(g_pos.getEdge(1, 2) == 1);
}

TEST_CASE("Test unary - operator") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    Graph g_neg = -g;
    CHECK(g_neg.getEdge(0, 1) == -1);
    CHECK(g_neg.getEdge(1, 2) == -1);
}

TEST_CASE("Test pre-increment operator") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    ++g;
    CHECK(g.getEdge(0, 1) == 2);
    CHECK(g.getEdge(1, 2) == 2);
}

TEST_CASE("Test post-decrement operator") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    g--;
    CHECK(g.getEdge(0, 1) == 0);
    CHECK(g.getEdge(1, 2) == 0);
}

TEST_CASE("Test post-increment operator") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    g++;
    CHECK(g.getEdge(0, 1) == 2);
    CHECK(g.getEdge(1, 2) == 2);
}

TEST_CASE("Test pre-decrement operator") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    --g;
    CHECK(g.getEdge(0, 1) == 0);
    CHECK(g.getEdge(1, 2) == 0);
}

TEST_CASE("Test scalar multiplication") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    g *= 2;
    CHECK(g.getEdge(0, 1) == 2);
    CHECK(g.getEdge(1, 2) == 2);
}

TEST_CASE("Test scalar division") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    g /= 2;
    CHECK(g.getEdge(0, 1) == 0);
    CHECK(g.getEdge(1, 2) == 0);
    CHECK_THROWS_AS(g /= 0, std::invalid_argument);
}

TEST_CASE("Test matrix multiplication") {
    Graph g1;
    Graph g2;
    std::vector<std::vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    std::vector<std::vector<int>> graph2 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    Graph g3 = g1 * g2;
    CHECK(g3.getEdge(0, 1) == 0);
    CHECK(g3.getEdge(1, 2) == 1);
    CHECK(g3.getEdge(0, 2) == 1);
    CHECK(g3.getEdge(2, 0) == 1);
}

TEST_CASE("Test comparison operators") {
    Graph g1;
    Graph g2;
    std::vector<std::vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    std::vector<std::vector<int>> graph2 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
    CHECK(g2 > g1);
    CHECK(g1 < g2);
    CHECK(g1 <= g2);
    CHECK(!(g1 >= g2));
    CHECK(!(g1 == g2));
}

TEST_CASE("Test self-assignment") {
    Graph g;
    std::vector<std::vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}
    };
    g.loadGraph(graph);

    g += g;
    CHECK(g.getEdge(0, 1) == 2);
    CHECK(g.getEdge(1, 2) == 2);

    g -= g;
    CHECK(g.getEdge(0, 1) == 0);
    CHECK(g.getEdge(1, 2) == 0);

    g *= 2;
    CHECK(g.getEdge(0, 1) == 0);
    CHECK(g.getEdge(1, 2) == 0);

    g /= 2;
    CHECK(g.getEdge(0, 1) == 0);
    CHECK(g.getEdge(1, 2) == 0);
}