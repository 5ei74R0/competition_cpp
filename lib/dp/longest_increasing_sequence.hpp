// algorithm to detect LIS (longest increasing sequence)
// Verified : 
//
#include <bits/stdc++.h>


/* LIS */
// algorithm to detect LIS (longest increasing sequence)
// time complexity : O(N logN)
// 
// Parameters
// 1. a (vector<T>) : constant reference to targeted vector
// 2. strict (bool) : strictly increasing(true) or not strictly increasing(false)
// 3. up_or_not (bool) : increasing(true) or decreasing(false)
//
// Returns
// 1. lis (vector<T>) : LIS
template<class T>
std::vector<T> lis(const std::vector<T> &a, bool strict=false, bool up_or_not=true) {
    std::vector<T> lis;
    if(up_or_not) {
        for(auto &p : a) {
            typename std::vector<T>::iterator iter;
            if(strict) iter = std::lower_bound(lis.begin(), lis.end(), p);
            else iter = std::upper_bound(lis.begin(), lis.end(), p);
            if(lis.end()==iter) lis.emplace_back(p);
            else *iter = p;
        }
    }else {
        std::vector<T> rev = a;
        reverse(rev.begin(), rev.end());
        for(auto &p : rev) {
            typename std::vector<T>::iterator iter;
            if(strict) iter = std::lower_bound(lis.begin(), lis.end(), p);
            else iter = std::upper_bound(lis.begin(), lis.end(), p);
            if(lis.end()==iter) lis.emplace_back(p);
            else *iter = p;
        }
    }
    return lis;
}
