// https://atcoder.jp/contests/typical90/tasks/typical90_h
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
/* ModInt */
// Operators
// +, -, *, /, =, ==, !=,
// +=, -=, *=, /=
//
template<std::int_fast64_t Mod>
class ModInt {
  public:
    using i64 = std::int_fast64_t;
    i64 val;
    // constructor
    constexpr ModInt(const i64 p=0) noexcept : val(p>=0 ? p%Mod : (Mod+(p%Mod))%Mod) {}

    // std::cin, std::cout
    friend std::ostream &operator<<(std::ostream &os, const ModInt &x) {
        return os << x.val;
    }
    friend std::istream &operator>>(std::istream &is, ModInt &x) {
        is >> x.val;
        x.val %= Mod;
        if(x.val < 0) x.val += Mod;  // <- 負数対応
        return is;
    }

    //operator
    constexpr ModInt operator+(const ModInt b) const noexcept { return ModInt(*this) += b; }

    constexpr ModInt operator-(const ModInt b) const noexcept { return ModInt(*this) -= b; }

    constexpr ModInt operator*(const ModInt b) const noexcept { return ModInt(*this) *= b; }

    constexpr ModInt operator/(const ModInt b) const noexcept { return ModInt(*this) /= b; }

    constexpr ModInt operator-() const noexcept { return ModInt() - *this; }

    constexpr bool operator==(const ModInt &b) const noexcept { return this->val == b.val; }

    constexpr bool operator!=(const ModInt &b) const noexcept { return this->val != b.val; }

    constexpr ModInt &operator=(const ModInt b) noexcept {
        val = b.val;
        return *this;
    }
    constexpr ModInt &operator=(const i64 b) noexcept {
        val = ModInt<Mod>(b).val;
        return *this;
    }
    constexpr ModInt &operator+=(const ModInt b) noexcept {
        if((val += b.val) >= Mod) val -= Mod;
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt b) noexcept {
        if(val < b.val) val += Mod;
        val -= b.val;
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt b) noexcept {
        val = val * b.val % Mod;
        return *this;
    }
    constexpr ModInt &operator/=(ModInt b) noexcept {
        val *= b.inverse().val;
        val %= Mod;
        return *this;
    }
    // calc val^n
    constexpr  ModInt pow(i64 n) noexcept {
        ModInt res = 1, a = val;
        while(n > 0) {
            if(n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
  private:
    constexpr ModInt inverse() noexcept {
        i64 m=Mod, u=1, v=0, t=1;
        while(m) {
            t = val/m;
            val -= t*m; std::swap(val,m);
            u -= t*v; std::swap(u,v);
        }
        return ModInt(u);
    }
};
const int mod = 1000000007;
// const int mod = 998244353;
using mint = ModInt<mod>;


};

// Main
signed main() {
    // fast io
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    // std::cout << std::fixed << std::setprecision(15);  // fix io precision

    // edit below
    using namespace space_575;

    usize n; std::cin >> n;
    std::string s; std::cin >> s;

    // atcoder
    char atcoder[7] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

    auto dp = make_vec(n+1, 8, mint(0));
    dp[0][0] = 1;
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < 8; ++j) {
            dp[i+1][j] += dp[i][j];
        }
        for (std::size_t j = 0; j < 7; ++j) {
            if (s[i] == atcoder[j]) dp[i+1][j+1] += dp[i][j];
        }
    }

    // debug
    // rep(i,n+1) std::cout << dp[i] << '\n';

    std::cout << dp[n][7] << '\n';

}
