// judge  whether n is prime number or not
// Verify : 
//
#include <bits/stdc++.h>


/* prime number judge */
// judge whether n is prime number or not
// time complexity : O(sqrtN)
//
// Parameters
// 1. n (i32) : integer to be estimated
// 
// Returns
// 1. (bool) : is n prime number?
//
bool is_prime(std::int32_t n) {
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;

    std::int32_t sqrt_n = sqrt(n);
    for (std::int32_t i = 3; i <= sqrt_n; i += 2){
        if (n % i == 0) return false;
    }

    return true;
}
