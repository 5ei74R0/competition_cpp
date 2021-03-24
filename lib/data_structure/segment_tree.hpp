// Segment Tree
// Verified : https://atcoder.jp/contests/abc125/submissions/20956216
//
#include <bits/stdc++.h>


/* Monoid */
// Example
// /* Add (Monoid) */
// struct Add {
//     using DataType = std::int_fast64_t;
//     static const DataType identity_element;
//     static DataType op(DataType l, DataType r) {
//         return l + r;
//     }
// };
// const Add::DataType Add::identity_element = 0;

/* Segment Tree */
//
// Attributes (public)
// 1. no attributes
//
// Methods (public)
// 1. set : set value at i-th element
//          time complexity : O(logN)
// 2. query : reply query to [l, r)
//            time complexity : O(logN)
// 3. lower_bound : return lower_bound index in [first, last)
//                  e.g.)
//                      index
//                          = [0, 1, 2, 3, 4, 5, 6]
//                      a
//                          = [1, 3, 5, 0, 0, 1, 1]
//                      cumulative_sum
//                          = [1, 4, 9, 9, 9,10,11]
//                    then, lower_bound(0, 7, 9) == 2
// 4. upper_bound : return upper_bound index in [first, last)
//                  e.g.)
//                      index
//                          = [0, 1, 2, 3, 4, 5, 6]
//                      a
//                          = [1, 3, 5, 0, 0, 1, 1]
//                      cumulative_sum
//                          = [1, 4, 9, 9, 9,10,11]
//                    then, upper_bound(0, 7, 9) == 5
// 5. size : return size of array
//
template <class Monoid>
class SegmentTree {
    using T = typename Monoid::DataType;

  public:
    explicit SegmentTree(std::size_t n) : siz(n), tree(n*2, Monoid::identity_element) {}
    explicit SegmentTree(const std::vector<T>& v) : siz(v.size()), tree(siz*2, Monoid::identity_element) {
        for (std::size_t i = 0; i < siz; ++i) tree[i + siz] = v[i];
        for (std::size_t i = siz - 1; i > 0; --i) {
            tree[i] = Monoid::op(tree[i << 1 | 0], tree[i << 1 | 1]);
        }
    }

    void set(T value, std::size_t idx) {
        tree[idx += size()] = value;
        while (idx >>= 1) {
            tree[idx] = Monoid::op(tree[idx << 1 | 0], tree[idx << 1 | 1]);
        }
    }

    T query(std::size_t l, std::size_t r) const {
        T result_l = Monoid::identity_element;
        T result_r = Monoid::identity_element;
        for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
            if (l & 1) result_l = Monoid::op(result_l, tree[l++]);
            if (r & 1) result_r = Monoid::op(tree[--r], result_r);
        }
        return Monoid::op(result_l, result_r);
    }

    std::size_t lower_bound(std::size_t l_idx, std::size_t r_idx, T threshold) const {
        std::size_t l = l_idx + siz;
        std::size_t r = r_idx + siz;
        std::size_t up_shift = 0;
        T cumulative_e = Monoid::identity_element;
        for (; l < r; l >>= 1, r >>= 1, ++up_shift) {
            if (l & 1) {
                T tmp = Monoid::op(cumulative_e, tree[l]);
                if (tmp >= threshold) return lower_bound_for_perfect_bin_tree(l, threshold - cumulative_e);
                cumulative_e = tmp;
                ++l;
            }
        }
        while (up_shift > 0) {
            --up_shift;
            r = r_idx >> up_shift;
            if (r & 1) {
                T tmp = Monoid::op(cumulative_e, tree[--r]);
                if (tmp >= threshold) return lower_bound_for_perfect_bin_tree(r, threshold - cumulative_e);
                cumulative_e = tmp;
            }
        }
        return r_idx;
    }

    std::size_t upper_bound(std::size_t l_idx, std::size_t r_idx, T threshold) const {
        std::size_t l = l_idx + siz;
        std::size_t r = r_idx + siz;
        std::size_t up_shift = 0;
        T cumulative_e = Monoid::identity_element;
        for (; l < r; l >>= 1, r >>= 1, ++up_shift) {
            if (l & 1) {
                T tmp = Monoid::op(cumulative_e, tree[l]);
                if (tmp > threshold) return upper_bound_for_perfect_bin_tree(l, threshold - cumulative_e);
                cumulative_e = tmp;
                ++l;
            }
        }
        while (up_shift > 0) {
            --up_shift;
            r = r_idx >> up_shift;
            if (r & 1) {
                T tmp = Monoid::op(cumulative_e, tree[--r]);
                if (tmp > threshold) return upper_bound_for_perfect_bin_tree(r, threshold - cumulative_e);
                cumulative_e = tmp;
            }
        }
        return r_idx;
    }

    std::size_t size() const noexcept { return siz; }

  private:
    const std::size_t siz;
    std::vector<T> tree;

    std::size_t lower_bound_for_perfect_bin_tree(std::size_t root, T threshold) const {
        T cumulative_e = Monoid::identity_element;
        std::size_t node = root;
        while (node < siz) {
            node <<= 1;  // move to left child
            T tmp = Monoid::op(cumulative_e, tree[node]);
            if (tmp < threshold) {
                cumulative_e = tmp;
                ++node;  // move to right brother
            }
        }
        return node - siz;
    }

    std::size_t upper_bound_for_perfect_bin_tree(std::size_t root, T threshold) const {
        T cumulative_e = Monoid::identity_element;
        std::size_t node = root;
        while (node < siz) {
            node <<= 1;  // move to left child
            T tmp = Monoid::op(cumulative_e, tree[node]);
            if (tmp <= threshold) {
                cumulative_e = tmp;
                ++node;  // move to right brother
            }
        }
        return node - siz;
    }
};


/* Sample */
// /* Add (Monoid) */
// struct Add {
//     using DataType = std::int_fast64_t;
//     static const DataType identity_element;
//     static DataType op(DataType l, DataType r) {
//         return l + r;
//     }
// };
// const Add::DataType Add::identity_element = 0;

// signed main() {
//     // fast io
//     std::cin.tie(nullptr);
//     std::ios::sync_with_stdio(false);

//     size_t n = 7;
//     std::vector<std::int_fast64_t> a = {1,3,5,0,0,1,1};  // sum := [1, 4, 9, 9, 9, 10, 11]
//     std::cout << a << '\n';

//     SegmentTree<Add> seg(a);

//     std::int_fast64_t sm;
//     std::cin >> sm;
    
//     std::cout << "sm : " << (sm) << '\n';
//     std::cout << "seg.lower_bound(0, n, sm) : " << (seg.lower_bound(0, n, sm)) << '\n';
//     std::cout << "seg.upper_bound(0, n, sm) : " << (seg.upper_bound(0, n, sm)) << '\n';
//     std::cout << "seg.upper_bound(0, n, sm) - seg.lower_bound(0, n, sm) : " << (seg.upper_bound(0, n, sm) - seg.lower_bound(0, n, sm)) << '\n';
// }
