// https://atcoder.jp/contests/typical90/tasks/typical90_f
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

    usize n,k; std::cin >> n >> k;
    std::string s; std::cin >> s;

    auto c = make_vec(n+1, 26, i64(inf<i64>));

    for (i32 i = n-1; i >= 0; --i) {
        for (usize j = 0; j < 26; ++j) {
            if (j == s[i] - 'a') {
                chmin(c[i][j], i);
            }
            chmin(c[i][j], c[i+1][j]);
        }
    }

    std::string res;
    for (usize i = 0; i < n && k > 0; ++i, --k) {
        for (usize j = 0; j < 26; ++j) {
            if (c[i][j] != inf<i64> && n - c[i][j] >= k) {
                res.push_back('a' + j);
                i = c[i][j];
                break;
            }
        }
    }

    cout << res << '\n';
}
