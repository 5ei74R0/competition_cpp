// lowlink
// Verified : http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5229454#1
//
#include "lib/graph/graph_template.hpp"
#include <bits/stdc++.h>


/* lowlink */
// detect bridges or articulation points
// time complexity : O(V + E)
//
// Attributes
// 1. articulation_points (vector<i32>) : list of articulation points
// 2. bridges (vector<pair<i32, i32>>) : list of bridges
//
// Methods
// 1. build : build lowlink. (use at 1st)
class LowLink {
  public:
    using i32 = std::int32_t;
    std::vector<i32> articulation_points;
    std::vector<std::pair<i32, i32>> bridges;
    explicit LowLink(const Graph &graph)
        : order(graph.size()),
          low(graph.size()),
          seen(graph.size()),
          graph(graph) {}

    void build() {
        InnerDfs();
    }

  private:
    const std::vector<std::vector<i32>> &graph;
    std::vector<bool> seen;
    // order (vector<i32>) : order[vertex] = order in DFS
    std::vector<i32> order;
    // low (vector<i32>) : low[vertex] = minimum number of order[v] for all v connected to vertex
    std::vector<i32> low;

    // decide order[vertex] and low[vertex]
    // detail : decide order "top-down" -> decide low "bottom-up"
    i32 InnerDfs(i32 vertex = 0, i32 past_v = -1, i32 k = 0) {
        seen[vertex] = true;
        order[vertex] = k;

        // decide low[vertex] and judge whether vertex is articulation point
        bool is_articulation_point = false;
        low[vertex] = order[vertex];
        for (const auto &next_v : graph[vertex]) {
            if (!seen[next_v]) {
                k = InnerDfs(next_v, vertex, k+1);
                low[vertex] = std::min(low[vertex], low[next_v]);
                if (k != 1 && order[vertex] <= low[vertex]) {
                    is_articulation_point = true;
                }
                if (order[vertex] < low[next_v]) {
                    bridges.emplace_back(std::min(vertex, next_v), std::max(vertex, next_v));
                }
            }
            else if (next_v != past_v) {  // back edge
                low[vertex] = std::min(low[vertex], order[next_v]);
            }
        }
        if (k == 1 && graph[order[0]].size() > 1) is_articulation_point = true;
        if(is_articulation_point) articulation_points.push_back(vertex);
        return k;
    }
};
