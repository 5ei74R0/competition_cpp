// template of graph representation
#include <bits/stdc++.h>


/* template of graph representation */
// represent edge of weighted graph
template<typename T>
struct Edge {
    std::int32_t src;  // idx of the source vertex
    std::int32_t to;  // idx of the vertex this edge reaches
    T cost;  // weight

    Edge(std::int32_t to, T cost)
        : src(-1), to(t), cost(w) {}
    Edge(std::int32_t src, std::int32_t to, T cost)
        : src(src), to(to), cost(cost) {}
};

template<typename T = std::int32_t>
using GraphWeighted = std::vector<std::vector<Edge<T>>>;  // weighted graph
using Graph = std::vector<std::vector<std::int32_t>>;  // graph
template<typename T = std::int32_t>
using Matrix = std::vector<std::vector<T>>;  // adjacency matrix


// /* example */
// signed main() {

//     size_t n; std::cin >> n;

//     GraphWeighted<double> weighted_graph(n);
//     for(int i = 0; i < n; i++) {  // build weighted_graph
//         int from, to;
//         double cost;
//         std::cin >> from >> to >> cost;
//         weighted_graph[from].emplace_back(from, to, cost);
//     }

//     Graph graph(n);
//     for(int i = 0; i < n; i++) { // build graph
//         int from, to;
//         std::cin >> from >> to;
//         graph[from].push_back(to);
//     }

//     Matrix<> matrix(n);  // adj matrix
//     for(int i = 0; i < n; ++i) {  // build matrix
//         int u, v;
//         double cost;
//         std::cin >> u >> v >> cost;
//         matrix[u][v] = matrix[v][u] = cost;
//     }
// }
