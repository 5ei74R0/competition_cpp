// Prime Factorization
// Verify : 
//
#include <bits/stdc++.h>


/* prime number judge */
// judge whether n is prime number or not
//
// Parameters
// 1. n (i32) : integer to be estimated
// 
// Returns
// 1. (bool) : is n prime number?
//
bool is_prime(int_fast32_t n) {
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;

    int_fast32_t sqrt_n = sqrt(n);
    for (int_fast32_t i = 3; i <= sqrt_n; i += 2){
        if (n % i == 0) return false;
    }

    return true;
}
