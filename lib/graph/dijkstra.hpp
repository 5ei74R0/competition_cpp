// Dijkstra's algorithm
// Verified : http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5229530#1
//
#include "lib/graph/graph_template.hpp"
#include <bits/stdc++.h>


/* Dijkstra's algorithm */
// calculate costs of SSSP (Single Source Shortest Path)
// time complexity : O((E + v)logV)
// 
// Parameters
// 1. graph (GraphWeighted) : weight of every edge >= 0
// 2. start_vertex (i32) : idx of start_vertex
// Returns
// 1. min_dist (vec<T>) : min_dist[i] == cost of SSSP (start_vertex -> i)
template<class T>
std::vector<T> Dijkstra(const GraphWeighted<T> &graph, const int_fast32_t start_vertex) {
    constexpr auto infinity = std::numeric_limits<T>::max();
    std::vector<T> min_dist(graph.size(), infinity);

    using P = std::pair<T, int_fast32_t>;  // std::pair< DistFromStartingVertex, IndexOfVertex >
    std::priority_queue<P, std::vector<P>, std::greater<P>> min_heap;
    min_dist[start_vertex] = 0;
    min_heap.emplace(min_dist[start_vertex], start_vertex);

    while(!min_heap.empty()) {
        T dist;
        int_fast32_t index;
        tie(dist, index) = min_heap.top();
        min_heap.pop();
        if(dist > min_dist[index]) continue;

        for(auto &edge : graph[index]) {
            auto new_dist = dist + edge.cost;
            // compare the length of each route and change min_dist[edge.to]
            if(new_dist >= min_dist[edge.to]) continue;
            min_dist[edge.to] = new_dist;
            min_heap.emplace(min_dist[edge.to], edge.to);
        }
    }
    return min_dist;
}
