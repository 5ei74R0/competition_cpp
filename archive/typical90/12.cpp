// https://atcoder.jp/contests/typical90/tasks/typical90_l
#include <bits/stdc++.h>

#define debug(x) std::cout <<"DEBUG: "<< #x << "\n" << (x) << '\n'
#define rep(i,n) for (std::size_t i = 0; i < ((std::size_t)(n)); ++i)
#define all(x) (x).begin(),(x).end()

// type alias
using i32 = std::int32_t;
using i64 = std::int64_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using usize = std::size_t;
using ld = long double;

template <class T> using vec = std::vector<T>;
template <class T> using maxheap = std::priority_queue<T>;
template <class T> using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using vi = vec<i32>;
using vl = vec<i64>;
using vld = vec<ld>;
using vvi = vec<vi>;
using PII = std::pair<i32, i32>;
using PLL = std::pair<i64, i64>;

// ostream-expansion
template <class T, class U> std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    std::size_t i = 0;
    os << "[";
    for (const auto& val : v) os << val << (++i < v.size() ? ", " : "]");
    return os;
}

template <class T> std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
    std::size_t i = 0;
    os << "{";
    for (const auto& val : st) os << val << (++i < st.size() ? ", " : "}");
    return os;
}

template <class T, class U> std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
    std::size_t i = 0;
    os << "{";
    for (const auto& p : mp) os << p.first << ": " << p.second << (++i < mp.size() ? ", " : "}");
    return os;
}

// constants
constexpr ld pi = M_PIf64x;
template<class T = i32> constexpr T inf = std::numeric_limits<T>::max() / 2;
template<class T = i32> constexpr T maxim = std::numeric_limits<T>::max();

// Class & Function
template <class T, class U> inline bool chmax(T &a, const U &b) {
    if (a < b) { a = b; return true; }
    return false;
}
template <class T, class U> inline bool chmin(T &a, const U &b) {
    if (a > b) { a = b; return true; }
    return false;
}

template <class T> auto make_vec(std::size_t n, const T &value) {
    return std::vector<T>(n, value);
}
template <class... Args> auto make_vec(std::size_t n, Args... args) {
    return std::vector<decltype(make_vec(args...))>(n, make_vec(args...));
}

namespace space_575 {  // unsafe: Name collisions can occur.
using namespace std;

// edit functions here

/* Disjoint Set Union (Union Find) */
// combining two sets, or judging whether two elements are in same group
// time complexity : O(\alpha(N))
//
// Methods
// 1. merge : merge the group including x and the group including y
// 2. is_same : judge whether x and y are in same group
// 3. size : return size of the group including x
class DisjointSetUnion {
  public:
    using i32 = int_fast32_t;
    explicit DisjointSetUnion(i32 sz) : parent(sz), siz(sz, 1) {
        for(i32 i = 0; i < sz; ++i) parent[i] = i;
    }

    // merge two groups
    bool merge(i32 x, i32 y) {
        x = root(x);
        y = root(y);
        if(x == y) return false;
        // merge tech
        if (siz[x] < siz[y]) std::swap(x,y);
        siz[x] += siz[y];
        parent[y] = x;
        return true;
    }
    // judge whether x and y are in same group 
    bool is_same(i32 x, i32 y) {
        return (root(x) == root(y));
    }
    // Return size of the group including x
    i32 size(i32 x) {
        return siz[root(x)];
    }

  private:
    std::vector<i32> parent;
    std::vector<i32> siz;

    // return root-id
    i32 root(i32 x) {
        while(parent[x] != x) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }
};

};

// Main
signed main() {
    // fast io
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    // std::cout << std::fixed << std::setprecision(15);  // fix io precision

    // edit below
    using namespace space_575;

    i32 h, w; std::cin >> h >> w;
    DisjointSetUnion dsu(2000 * h + w);
    auto color = make_vec(2000 * h + w, 0);

    i32 q, query; std::cin >> q;
    while (q--) {
        std::cin >> query;
        if (query == 1) {
            i32 r, c;
            std::cin >> r >> c;
            --r, --c;
            color[2000 * r + c] = 1;
            if (0 <= r-1 && color[2000 * (r-1) + c] == 1) {
                dsu.merge(2000 * r + c, 2000 * (r-1) + c);
            }
            if (r+1 < h && color[2000 * (r+1) + c] == 1) {
                dsu.merge(2000 * r + c, 2000 * (r+1) + c);
            }
            if (0 <= c-1 && color[2000 * r + (c-1)] == 1) {
                dsu.merge(2000 * r + c, 2000 * r + (c-1));
            }
            if (c+1 < w && color[2000 * r + (c+1)] == 1) {
                dsu.merge(2000 * r + c, 2000 * r + (c+1));
            }

        } else {
            i32 ra, ca, rb, cb;
            std::cin >> ra >> ca >> rb >> cb;
            --ra, --ca, --rb, --cb;
            if (color[2000 * ra + ca] == 1
                    && color[2000 * rb + cb] == 1
                    && dsu.is_same(2000 * ra + ca, 2000 * rb + cb)) {
                std::cout << "Yes" << '\n';
            } else {
                std::cout << "No" << '\n';
            }
        }
        // // DEBUG
        // for (i32 i = 0; i < h; ++i) {
        //     for (i32 j = 0; j < w; ++j) {
        //         std::cout << color[2000 * i + j] << (j == w-1 ? '\n' : ' ');
        //     }
        // }
        // std::cout << '\n';
    }
}
