// Prime Factorization
// Verify : 
//
#include <bits/stdc++.h>


/* Prime Factorization */
// time complexity : O(sqrtN)
template<typename T_n>
std::map<T_n, int> prime_factor(T_n n) {
    std::map<T_n, int> ret;
    for(T_n i = 2; i*i <= n; i++){
        while(n % i == 0){
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

/* Prime Factorization with preprocessing */
// time complexity (preprocessing) : O(N loglogN)
// time complexity (query) : O(logN)
template<size_t MAX_N>
class PrimeFactorization {
  public:
    using i64 = int_fast64_t;
    constexpr PrimeFactorization()
        : smallest_prime_factors() {
        for(i64 i = 0; i <= MAX_N; ++i) {
            smallest_prime_factors[i] = i;
        }
        for(i64 i = 2; i * i <= MAX_N; ++i) {
            if(smallest_prime_factors[i] == i) {
                for(i64 j = i * i; j <= MAX_N; j += i) {
                    if(smallest_prime_factors[j] == j) {
                        smallest_prime_factors[j] = i;
                    }
                }
            }
        }
    }

    std::map<i64, i64> factorize(i64 n) {
        std::map<i64, i64> primes_map;
        while(n != 1) {
            ++primes_map[smallest_prime_factors[n]];
            n /= smallest_prime_factors[n];
        }
        return primes_map;
    }
  private:
    int_fast64_t smallest_prime_factors[MAX_N+1];
};
