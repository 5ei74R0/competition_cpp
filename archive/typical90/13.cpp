// https://atcoder.jp/contests/typical90/tasks/typical90_m
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


};

// Main
signed main() {
    // fast io
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    // std::cout << std::fixed << std::setprecision(15);  // fix io precision

    // edit below
    using namespace space_575;

    usize n, m; std::cin >> n >> m;
    i32 a, b, c;

    vec<vec<std::pair<usize, i64>>> graph(n);
    rep (i,m) {
        std::cin >> a >> b >> c;
        graph[--a].emplace_back(--b, c);
        graph[b].emplace_back(a, c);
    }

    minheap<std::pair<i64, usize>> hp;
    vec<i64> dist_from_0(n, inf<i64>);
    vec<i64> dist_from_n(n, inf<i64>);
    dist_from_0[0] = 0;
    hp.emplace(0, 0);
    while (hp.size()) {
        int v, d;
        std::tie(d, v) = hp.top();
        hp.pop();
        if (d > dist_from_0[v]) continue;

        for (const auto& pr : graph[v]) {
            usize nv = pr.first;
            i64 nd = pr.second;
            if (chmin(dist_from_0[nv], d + nd)) {
                hp.emplace(d + nd, nv);
            }
        }
    }
    dist_from_n[n-1] = 0;
    hp.emplace(0, n-1);
    while (hp.size()) {
        int v, d;
        std::tie(d, v) = hp.top();
        hp.pop();
        if (d > dist_from_n[v]) continue;

        for (const auto& pr : graph[v]) {
            usize nv = pr.first;
            i64 nd = pr.second;
            if (chmin(dist_from_n[nv], d + nd)) {
                hp.emplace(d + nd, nv);
            }
        }
    }

    rep (i,n) {
        std::cout << dist_from_0[i] + dist_from_n[i] << '\n';
    }
}
