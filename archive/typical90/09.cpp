// https://atcoder.jp/contests/typical90/tasks/typical90_i
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

struct Point {
  public:
    ld x, y;

    explicit Point(ld x, ld y): x(x), y(y) {}

    ld calc_theta(Point b) const {
        return std::atan2(b.y - y, b.x - x) * 180.0 / pi;
    }
};

};

// main
signed main() {
    // fast io
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);  // fix io precision

    // edit below
    using namespace space_575;

    usize n; std::cin >> n;
    auto points = make_vec(n, Point(0, 0));
    rep (i,n) std::cin >> points[i].x >> points[i].y;

    ld ans = 0;
    vec<ld> thetas;
    rep (i,n) {
        thetas.clear();
        rep (j,n) if (i != j) thetas.push_back(points[i].calc_theta(points[j]));  // -180 ~ 180
        std::sort(all(thetas));
        rep (j,thetas.size()) {
            auto aim = thetas[j] + 180;
            if (aim > 180) aim -= 360;
            int opposite1 = (std::lower_bound(all(thetas), aim) - thetas.begin()) % thetas.size();
            int opposite2 = (opposite1 - 1 + thetas.size()) % thetas.size();
            ld theta1 = std::abs(thetas[opposite1] - thetas[j]);
            if (theta1 > 180) theta1 = 360 - theta1;
            ld theta2 = std::abs(thetas[opposite2] - thetas[j]);
            if (theta2 > 180) theta2 = 360 - theta2;
            chmax(ans, std::max(theta1, theta2));
        }
    }

    std::cout << ans << '\n';
}
