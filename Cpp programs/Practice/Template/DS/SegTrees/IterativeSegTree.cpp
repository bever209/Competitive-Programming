#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;
/* Actual code from now */

const int N = 1e5+10;  // limit for array size
// NOTE THAT THIS IS 1-INDEXED
template<class T> struct it_st {
    int n;  // array size
    vector<T> t;

    void init(int _n){
        n=_n;t.resize(2*N+50);
    }

    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
    }


    void modify(T value,int p) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
    }

    T query(int l, int r) {  // sum on interval [l, r)
        T res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += t[l++];
            if (r & 1) res += t[--r];
        }
        return res;
    }
};
