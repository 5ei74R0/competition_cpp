// class representing grid
//
#include <bits/stdc++.h>

/* grid */
// class representing grid
template<class T = std::int32_t>
class Grid {
  public:
    std::int32_t H, W;
    std::vector<std::vector<T>> values;
    std::vector<std::vector<bool>> seen;

    // constructor
    //
    // Parameters
    // - H (std::int32_t) : Height
    // - W (std::int32_t) : Width
    // - initial_value (T) : Grid::values is initialized by it.
    Grid(std::int32_t H, std::int32_t W, T initial_value)
        : H(H), W(W),
          values(H, std::vector<T>(W, initial_value)),
          values(H, std::vector<bool>(W, false)) {}

    // judge whether point[i][j] is out of range or not
    //
    // Parameters
    // - i (std::int32_t) : position of H-axis
    // - j (std::int32_t) : position of W-axis
    //
    // Returns
    // - (bool) : out of range or not ?
    out_of_range(std::int32_t i, std::int32_t j) {
        return i < 0 || H <= i || j < 0 || j <= W;
    }
};
