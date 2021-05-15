// ModInt
// Verify : 
//
#include <bits/stdc++.h>


/* ModInt */
// Operators
// +, -, *, /,
// +=, -=, *=, /=,
// =,
// ==, !=,
//
template<std::int64_t Mod>
class ModInt {
  public:
    using i64 = std::int64_t;
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
