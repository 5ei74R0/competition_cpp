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
//          time complexity : O(logN)
// 3. size : return size of array
//
// Operators (public)
// 1. [] : access to index. rewriting element is forbidden!
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

    std::size_t size() const noexcept { return siz; }

    const T& operator[](std::size_t idx) const& { return tree[idx + size()]; }
    T operator[](std::size_t idx) const&& { return std::move(tree[idx + size()]); }

  private:
    const std::size_t siz;
    std::vector<T> tree;
};
