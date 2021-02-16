// warshall-floyd's algorithm
// Verified : http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5229580#1
//
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
// 1. costs (vector<vector<T>>)
// : 2d-array containing costs of APSP
//   (costs[frm][to] == cost of "frm -> to")
//   if there is a negative cycle include "k", then costs[k][k] < 0
template<class T>
std::vector<std::vector<T>> WarshallFloyd(const Matrix<T> &graph, T unconnected_param) {
    using i32 = int_fast32_t;
    constexpr auto infinity = std::numeric_limits<T>::max();
    std::vector<std::vector<T>> costs = graph;
    // init costs
    for (i32 i = 0; i < graph.size(); ++i) {
        for (i32 j = 0; j < graph.size(); ++j) {
            if (graph[i][j] == unconnected_param) costs[i][j] = infinity;
            else costs[i][j] = graph[i][j];
        }
    }
    // calc
    for (i32 inter = 0; inter < costs.size(); ++inter) {
        for (i32 frm = 0; frm < costs.size(); ++frm) {
            for (i32 to = 0; to < costs.size(); ++to) {
                if (costs[frm][inter] == infinity ||
                    costs[inter][to] == infinity) {
                    continue;
                }
                costs[frm][to] = std::min<T>(costs[frm][to], costs[frm][inter] + costs[inter][to]);
            }
        }
    }
    return costs;
}
