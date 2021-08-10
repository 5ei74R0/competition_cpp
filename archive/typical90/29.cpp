// https://atcoder.jp/contests/typical90/tasks/typical90_ac
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
/* Lazy Segment Tree -----------*/
template <typename M>
class LazySegmentTree {
    using F = std::function<M(M, M)>;
    using G = std::function<M(M, int)>;
  private:
    int n, h;
    std::vector<M> t, d;
    const F func;
    const G func2;
    const M M_init;
    inline void calc(int p, int length) {
        if(d[p] == M_init) t[p] = func(t[p<<1], t[p<<1|1]);
        else t[p] = func2(d[p], length);
    }
    inline void apply(int p, M value, int length) {
        t[p] = func2(value, length);  // 区間更新バージョン
        // t[p] += func2(value, length);  // 区間加算バージョン
        if(p < n) d[p] = value;
    }
    void _build_(int l, int r) {
        int length = 2;
        for(l += n, r += n-1; l > 1; length <<= 1) {
            l >>= 1; r >>= 1;
            for(int i = r; i >= l; --i) calc(i, length);
        }
    }
    void push(int l, int r) {
        int s = h, length = 1 << (h-1);
        for(l += n, r += n-1; s > 0; --s, length >>= 1) {
            for(int i = (l >> s); i <= (r >> s); ++i) if(d[i] != M_init) {
                    apply(i<<1, d[i], length);
                    apply(i<<1|1, d[i], length);
                    d[i] = M_init;
                }
        }
    }
  public:
    // constructor
    LazySegmentTree(int N,F Combiner, G Func_for_segment, M M_init):
            n(N), func(Combiner), func2(Func_for_segment), M_init(M_init)
    {
        h = 0; int m = 1; while(m <= n) {m <<= 1; ++h;}
        t.assign(2*n, M_init);
        d.assign(n, M_init);
    }
    // set value at position p
    void set(int &p, const M &value) {t[p+n] = value;}
    // build
    void build() { _build_(0,n); }

    void modify(int l, int r, M value) {  // update value in [l, r)
        if(value == M_init) return;
        push(l, l+1);
        push(r-1, r);
        bool canl = false, canr = false;
        int length = 1;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1, length <<= 1) {
            if(canl) calc(l-1, length);
            if(canr) calc(r, length);
            if(l & 1) apply(l++, value, length), canl = true;
            if(r & 1) apply(--r, value, length), canr = true;
        }
        for(--l; r > 0; l >>= 1, r >>= 1, length <<= 1) {
            if(canl) calc(l, length);
            if(canr && (!canl || l != r)) calc(r, length);
        }
    }

    M query(int l, int r) {  // reply to query in [l, r)
        push(l, l+1);
        push(r-1, r);
        M resl = M_init, resr = M_init;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) resl = func(resl, t[l++]);
            if(r & 1) resr = func(t[--r], resr);
        }
        return func(resl, resr);
    }
    M operator[](int &k) { return query(k, k+1); }
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

    // Lazy segment tree smash.
    // That's all.

    usize w, n; std::cin >> w >> n;
    LazySegmentTree<i32> segtree_range_max(w + 1, [](i32 a, i32 b){ return std::max(a, b); }, [](i32 a, i32 k){ return a; }, 0);

    i32 l, r;
    for (usize i = 0; i < n; ++i) {
        std::cin >> l >> r;
        segtree_range_max.modify(l, r + 1, segtree_range_max.query(l, r + 1) + 1);
        std::cout << segtree_range_max.query(l, r + 1) << '\n';
    }
}
