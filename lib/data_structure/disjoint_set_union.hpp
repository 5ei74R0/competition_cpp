// Disjoint Set Union (Union Find)
// Verified : http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=5230198#1
//
#include <bits/stdc++.h>


/* Disjoint Set Union (Union Find) */
// combining two sets, or judging whether two elements are in same group
// time complexity : O(\alpha(N))
//
// Methods
// 1. merge : merge the group including x and the group including y
// 2. is_same : judge whether x and y are in same group
// 3. size : return size of the group including x
class DisjointSetUnion {
  public:
    using i32 = int32_t;
    explicit DisjointSetUnion(i32 sz) : parent(sz), siz(sz, 1) {
        for(i32 i = 0; i < sz; ++i) parent[i] = i;
    }

    // merge two groups
    bool merge(i32 x, i32 y) {
        x = root(x);
        y = root(y);
        if(x == y) return false;
        // merge tech
        if (siz[x] < siz[y]) std::swap(x,y);
        siz[x] += siz[y];
        parent[y] = x;
        return true;
    }
    // judge whether x and y are in same group 
    bool is_same(i32 x, i32 y) {
        return (root(x) == root(y));
    }
    // Return size of the group including x
    i32 size(i32 x) {
        return siz[root(x)];
    }

  private:
    std::vector<i32> parent;
    std::vector<i32> siz;

    // return root-id
    i32 root(i32 x) {
        while(parent[x] != x) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }
};

