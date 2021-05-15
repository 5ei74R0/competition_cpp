// template of bfs on Grid
//
#include "lib/grid/grid.hpp"
#include <bits/stdc++.h>


/* basic bfs on grid */
template<class T>
void bfs_on_grid(std::int32_t start_i, std::int32_t start_j, const Grid<T> &grid) {
    std::deque<std::pair<std::int32_t, std::int32_t>> que;
    que.emplace_back(start_i, start_j);
    grid.seen[start_i][start_j] = true;

    // if u have to define other movements, update following vectors
    std::vector<std::int32_t> move_i = {1,0,-1,0};
    std::vector<std::int32_t> move_j = {0,-1,0,1};

    while (!que.empty()) {
        std::int32_t cur_i, cur_j;
        tie(cur_i, cur_j) = que.front();
        que.pop_front();
        for(std::int32_t idx = 0; idx < 4; ++idx) {
            std::int32_t nxt_i = cur_i + move_i[idx];
            std::int32_t nxt_j = cur_j + move_j[idx];
            if(grid.seen[nxt_i][nxt_j]) continue;
            if(grid.out_of_range(nxt_i, nxt_j)) continue;

            // write any action

            grid.seen[nxt_i][nxt_j] = true;
            que.emplace_back(nxt_i, nxt_j);
        }
    }
}
