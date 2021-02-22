// class representing grid
//
#include <bits/stdc++.h>

/* grid */
// class representing grid
template<class T = int_fast32_t>
class Grid {
  public:
    int_fast32_t H, W;
    std::vector<std::vector<T>> values;
    std::vector<std::vector<bool>> seen;

    // constructor
    //
    // Parameters
    // - H (int_fast32_t) : Height
    // - W (int_fast32_t) : Width
    // - initial_value (T) : Grid::values is initialized by it.
    Grid(int_fast32_t H, int_fast32_t W, T initial_value)
        : H(H), W(W),
          values(H, std::vector<T>(W, initial_value)),
          values(H, std::vector<bool>(W, false)) {}

    // judge whether point[i][j] is out of range or not
    //
    // Parameters
    // - i (int_fast32_t) : position of H-axis
    // - j (int_fast32_t) : position of W-axis
    //
    // Returns
    // - (bool) : out of range or not ?
    out_of_range(int_fast32_t i, int_fast32_t j) {
        return i < 0 || H <= i || j < 0 || j <= W;
    }
};
