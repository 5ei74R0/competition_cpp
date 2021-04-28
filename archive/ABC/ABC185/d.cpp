// https://atcoder.jp/contests/abc185/tasks/abc185_d
#include <bits/stdc++.h>

#define debug(x) std::cout <<"DEBUG: "<< #x << "\n" << (x) << "\n\n"
#define rep(i,n) for (std::size_t i = 0; i < ((std::size_t)(n)); ++i)
#define all(x) (x).begin(),(x).end()

// type alias
using i32 = std::int_fast32_t;
using i64 = std::int_fast64_t;
using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;
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
constexpr i64 infll = std::numeric_limits<i64>::max() / 2;
constexpr i32 inf = std::numeric_limits<i32>::max() / 2;

/* Class & Function */
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

/* Main */
signed main() {
    using namespace space_575;

    // fast io
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    // std::cout << std::fixed << std::setprecision(15);  // fix io precision

    usize n,m;
    std::cin >> n >> m;
    if (m == 0) {
        std::cout << 1 << '\n';
        return 0;
    }
    std::vector<i32> a(m);
    for (usize i = 0; i < m; ++i)
        std::cin >> a[i];
    std::sort(all(a));
    a.push_back(n+1);

    i32 min_mergin = inf;
    i32 p = 0;
    for (const auto& aa : a) {
        if (aa - p - 1 > 0) chmin(min_mergin, aa - p - 1);
        p = aa;
    }

    i32 ans = 0;
    p = 0;
    for (const auto& aa : a) {
        i32 mergin = aa - p - 1;
        if (mergin > 0)
            ans += (mergin + min_mergin - 1) / min_mergin;
        p = aa;
    }

    std::cout << ans << '\n';
}
