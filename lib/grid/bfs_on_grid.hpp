// template of bfs on Grid
//
#include "lib/grid/grid.hpp"
#include <bits/stdc++.h>


/* basic bfs on grid */
template<class T>
void bfs_on_grid(int_fast32_t start_i, int_fast32_t start_j, const Grid<T> &grid) {
    std::deque<std::pair<int_fast32_t, int_fast32_t>> que;
    que.emplace_back(start_i, start_j);
    grid.seen[start_i][start_j] = true;

    // if u have to define other movements, update following vectors
    std::vector<int_fast32_t> move_i = {1,0,-1,0};
    std::vector<int_fast32_t> move_j = {0,-1,0,1};

    while (!que.empty()) {
        int_fast32_t cur_i, cur_j;
        tie(cur_i, cur_j) = que.front();
        que.pop_front();
        for(int_fast32_t idx = 0; idx < 4; ++idx) {
            int_fast32_t nxt_i = cur_i + move_i[idx];
            int_fast32_t nxt_j = cur_j + move_j[idx];
            if(grid.seen[nxt_i][nxt_j]) continue;
            if(grid.out_of_range(nxt_i, nxt_j)) continue;

            // write any action

            grid.seen[nxt_i][nxt_j] = true;
            que.emplace_back(nxt_i, nxt_j);
        }
    }
}
