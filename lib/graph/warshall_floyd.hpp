// warshall-floyd's algorithm
#include "lib/graph/graph_template.hpp"
#include <bits/stdc++.h>


/* warshall-floyd's algorithm */
// calculate costs of APSP (All Pairs Shortest Path)
// time complexity : O(V^3)
//
// Parameters
// 1. graph (Matrix<T>) : the adjacency matrix of the weighted graph.
// 2. unconnected_param (T) : the value in adjacency matrix representing unconnected path
// Returns
// 1. costs (vector<vector<T>>) : 2d-array containing costs of APSP (costs[frm][to] == cost of "frm -> to")
template<class T>
std::vector<std::vector<T>> WarshallFloyd(const Matrix<T> &graph, T unconnected_param) {
    using i32 int_fast32_t;
    constexpr auto infinity = std::numeric_limits<T>::max();
    std::vector<std::vector<T>> costs;
    // init costs
    for (i32 i = 0; i < g.size(); ++i) {
        for (i32 j = 0; j < g.size(); ++j) {
            if (i == j) costs[i][j] = 0;
            else if (graph[i][j] == unconnected_param) costs[i][j] = infinity;
            else costs[i][j] = graph[i][j];
        }
    }
    // calc
    for (i32 inter = 0; inter < g.size(); ++inter) {
        for (i32 frm = 0; frm < g.size(); ++frm) {
            for (i32 to = 0; to < g.size(); ++to) {
                if (graph[frm][inter] == infinity ||
                    graph[inter][to] == infinity) {
                    continue;
                }
                graph[frm][to] = std::min<T>(graph[frm][to], graph[frm][inter] + graph[inter][to]);
            }
        }
    }
    return costs;
}
