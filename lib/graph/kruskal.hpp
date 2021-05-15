// Kruskal's algorithm
// Verified : https://atcoder.jp/contests/joisc2010/submissions/20232556
//
#include "lib/graph/graph_template.hpp"
#include <bits/stdc++.h>


/* Kruskal's algorithm */
// construct Minimum Spanning Tree
// time complexity : O(E logV)
//
// Parameters
// 1. graph (GraphWeighted<T>) : graph
// 2. number_of_trees (i32) : number of created MSTs (default : 1)
//
// Returns
// 1. pair<total_cost, MST> (pair<T, GraphWeighted<T>>)
// : total cost of MST and MST.
//   if number_of_trees > 1, then MST is forest.
template <typename T>
std::pair<T, GraphWeighted<T>> Kruskal(GraphWeighted<T> &graph, std::int32_t number_of_trees = 1) {
    std::vector<std::int32_t> forest;
    std::vector<std::int32_t> siz(graph.size(), 1);
    GraphWeighted<T> MST(graph.size());
    T total_cost = 0;
    std::int32_t num_of_trees = graph.size();

    for(std::int32_t i = 0; i < graph.size(); ++i) forest.push_back(i);
    std::vector<std::tuple<T, std::int32_t, std::int32_t>> edges;
    for(std::int32_t u = 0; u < graph.size(); ++u) for(auto v : graph[u]) edges.emplace_back(v.cost, u, v.to);
    std::sort(edges.begin(), edges.end());

    for(auto e : edges) {
        if(num_of_trees == number_of_trees) break;
        std::int32_t U, V; T cost;
        std::tie(cost, U, V) = e;
        std::int32_t u = U, v = V;
        u = [&]() {while(forest[u] != u) {u = forest[u] = forest[forest[u]];} return u;}();
        v = [&]() {while(forest[v] != v) {v = forest[v] = forest[forest[v]];} return v;}();
        if(forest[u] == forest[v]) continue;
        if(siz[u] < siz[v]) std::swap(u, v);
        siz[u] += siz[v];
        forest[v] = u;
        --num_of_trees;
        MST[U].push_back(Edge<T>(V, cost));
        MST[V].push_back(Edge<T>(U, cost));
        total_cost += cost;
    }
    return std::make_pair(total_cost, MST);
}
