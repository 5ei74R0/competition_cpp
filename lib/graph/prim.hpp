// Prim's algorithm
// Verify : http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5232566#1
//
#include "lib/graph/graph_template.hpp"
#include <bits/stdc++.h>


/* Prim's algorithm */
// construct Minimum Spanning Tree
// time complexity : O(E logV)
//
// Parameters
// 1. graph (GraphWeighted<T>) : graph
//
// Returns
// 1. pair<total_cost, MST> (pair<T, GraphWeighted<T>>)
// : total cost of MST and MST.
template<class T>
std::pair<T, GraphWeighted<T>> Prim(GraphWeighted<T> &graph) {
    T total_cost = 0;
    GraphWeighted<T> MST(graph.size());
    std::vector<bool> used(graph.size(), false);

    using Tup = std::tuple<T, int_fast32_t, int_fast32_t>;
    std::priority_queue<Tup, std::vector<Tup>, std::greater<Tup>> que;
    que.emplace(0, 0, 0);

    while(!que.empty()) {
        T cost;
        int_fast32_t v;  // parent
        int_fast32_t u;  // vertex focused on
        tie(cost, u, v) = que.top();
        que.pop();
        if(used[u]) continue;
        used[u] = true;
        total_cost += cost;
        if(u != v) {
            MST[v].emplace_back(u, cost);
            MST[u].emplace_back(v, cost);
        }
        for(auto &edge : graph[u]) {
            que.emplace(edge.cost, edge.to, u);
        }
    }
    return(make_pair(total_cost, MST));
}
