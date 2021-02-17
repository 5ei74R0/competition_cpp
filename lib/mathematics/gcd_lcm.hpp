// GCD and LCM
// verify : https://atcoder.jp/contests/abc125/submissions/20239260
//
#include <bits/stdc++.h>


/* GCD (Greatest Common Divisor) */
// calculate GCD
//
int_fast64_t GCD(int_fast64_t a, int_fast64_t b) {
    return (b ? GCD(b, a%b) : a);
}

/* LCM (Least Common Multiple) */
// calculate LCM
//
int_fast64_t LCM(int_fast64_t a, int_fast64_t b) {
    int_fast64_t g = GCD(a, b);
    return (a/g) * (b/g) * g;
}
