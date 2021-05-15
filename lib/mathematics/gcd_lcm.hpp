// GCD and LCM
// verify : https://atcoder.jp/contests/abc125/submissions/20239260
//
#include <bits/stdc++.h>


/* GCD (Greatest Common Divisor) */
// calculate GCD
//
std::int64_t calc_GCD(std::int64_t a, std::int64_t b) {
    return (b ? calc_GCD(b, a%b) : a);
}

/* LCM (Least Common Multiple) */
// calculate LCM
//
std::int64_t calc_LCM(std::int64_t a, std::int64_t b) {
    std::int64_t g = calc_GCD(a, b);
    return (a/g) * (b/g) * g;
}
