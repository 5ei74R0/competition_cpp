// enumerate divisors of n
// Verify : 
//
#include <bits/stdc++.h>


/* enumerate divisors */
// enumerate divisors of n
// time complexity : O(sqrtN)
//
// Parameters
// 1. n (i64) : targeted integer
// 
// Returns
// 1. divisors (vec<i64>) : divisors of n
//
std::vector<std::int64_t> enumerate_divisors(std::int64_t n) {
    std::vector<std::int64_t> divisors;
    for (std::int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) divisors.push_back(n / i);
        }
    }
    // Option : if u do sorting -> time complexity : O(sqrtN logN)
    // std::sort(divisors.begin(), divisors.end()); 
    return divisors;
}
