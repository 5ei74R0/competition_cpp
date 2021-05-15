// Sieve of Eratosthenes
// Verify : 
//
#include <bits/stdc++.h>


/* Sieve of Eratosthenes */
// detect prime numbers lower than MAX_N
// time complexity : O(N loglogN)
//
// Methods
// 1. is_prime(i64 n) -> bool : judge whether n is prime number
//
// Example
// constexpr size_t n = 1e7;
// Sieve<n> sieve; sieve.is_prime(157);
//
template<size_t MAX_N>
class Sieve {
  public:
    using i64 = std::int64_t;

    constexpr Sieve(): container() {
        for(i64 i = 1; i < (MAX_N+11)/6; ++i) {
            container[i][0] = container[i][1] = true;
        }

        for(i64 i = 1; i < (MAX_N+11)/6; ++i) {
            if(container[i][0]) {  // 6i - 1 is prime
                for(i64 p = 1; p < (MAX_N+11)/6; ++p) {
                    i64 idx1 = 6*i*p + i - p;
                    i64 idx2 = 6*i*p - i - p;
                    if(idx2 >= (MAX_N+11)/6) break;
                    container[idx2][1] = false;
                    if(idx1 >= (MAX_N+11)/6) continue;
                    container[idx1][0] = false;
                }
            }
            if(container[i][1]) {  // 6i + 1 is prime
                for(i64 p = 1; p < (MAX_N+11)/6; ++p) {
                    i64 idx1 = 6*i*p + i + p;
                    i64 idx2 = 6*i*p - i + p;
                    if(idx2 >= (MAX_N+11)/6) break;
                    container[idx2][0] = false;
                    if(idx1 >= (MAX_N+11)/6) continue;
                    container[idx1][1] = false;
                }
            }
        }
    }

    bool is_prime(i64 num) {  // num > 0
        if(num == 2 || num == 3) return true;
        if((num+1)%6 == 0) return (container[(num+1)/6][0]);
        if((num-1)%6 == 0) return (container[(num-1)/6][1]);
        return false;
    }

  private:
    bool container[(MAX_N+11)/6][2];
};
