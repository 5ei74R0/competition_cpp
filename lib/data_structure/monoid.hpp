// Monoid
// monoid class
// Verified : <url>

// dependencies
#include <cstdint>


/* Monoid */
// monoid class
//
// List of Member
// alias:
// 1. DataType: typename
// param:
// 1. identity_element: DataType
// function:
// 1. op(l_element: DataType, r_element: DataType) -> DataType
struct Monoid {
    using DataType = std::int64_t;
    inline constexpr static DataType identity_element = 0;
    inline constexpr static DataType op(DataType l_element, DataType r_element);
};


// Example
/* Add (Monoid) */
struct Add : public Monoid {
    inline constexpr static DataType op(DataType l_element, DataType r_element) {
        return l_element + r_element;
    }
};

/* Min (Monoid) */
#include <limits>
struct Min : public Monoid {
    inline constexpr static DataType identity_element = std::numeric_limits<DataType>::max();
    inline constexpr static DataType op(DataType l_element, DataType r_element) {
        return l_element + r_element;
    }
};

/* MatrixMulti (Monoid) */
// #include "lib/mathematics/matrix.hpp"
// constexpr std::size_t matrix_size = 5;
// struct MatrixMulti : public Monoid {
//     using DataType = SquareMatrix<std::int64_t>;
//     inline constexpr static DataType identity_element = DataType::make_id(matrix_size);
//     inline constexpr static DataType op(DataType l_element, DataType r_element) {
//         return l_element * r_element;
//     }
// };
