// https://atcoder.jp/contests/abc184/tasks/abc184_e
#include <bits/stdc++.h>

#define debug(x) std::cout <<"DEBUG: "<< #x << "\n↓\n" << (x) << '\n'
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
constexpr i64 infll = std::numeric_limits<i64>::max() >> 1;
constexpr i32 inf = std::numeric_limits<i32>::max() >> 1;

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

    usize h, w; std::cin >> h >> w;
    vec<vec<char>> a(h, vec<char>(w));
    vec<std::queue<PII>> tel(26);
    PII s, g;
    rep(i, h) rep(j, w) {
        std::cin >> a[i][j];
        if (0 <= a[i][j] - 'a' && a[i][j] - 'a' < 26) 
            tel[a[i][j] - 'a'].emplace(i, j);
        if (a[i][j] == 'S') {
            s.first = i;
            s.second = j;
        }
        if (a[i][j] == 'G') {
            g.first = i;
            g.second = j;
        }
    }

    vvi dist(h, vi(w, inf));
    dist[s.first][s.second] = 0;
    std::queue<PII> que;
    que.emplace(s.first, s.second);
    vi mvi = {0,1,0,-1};
    vi mvj = {1,0,-1,0};
    while (que.size()) {
        i32 u, v;
        std::tie(u, v) = que.front(); que.pop();
        // adjacency
        for (usize i = 0; i < 4; ++i) {
            i32 nu = u + mvi[i];
            i32 nv = v + mvj[i];
            if (nu < 0 || h <= nu || nv < 0 || w <= nv) continue;
            if (a[nu][nv] == '#') continue;
            if (dist[nu][nv] != inf) continue;
            if (chmin(dist[nu][nv], dist[u][v] + 1))
                que.emplace(nu, nv);
        }
        // teleport
        if (0 <= a[u][v] - 'a' && a[u][v] - 'a' < 26) {
            while (tel[a[u][v] - 'a'].size()) {
                i32 nu, nv;
                std::tie(nu, nv) = tel[a[u][v] - 'a'].front();
                tel[a[u][v] - 'a'].pop();
                if (chmin(dist[nu][nv], dist[u][v] + 1))
                    que.emplace(nu, nv);
            }
        }
    }

    std::cout << (dist[g.first][g.second] == inf ? -1 : dist[g.first][g.second]) << '\n';
}
