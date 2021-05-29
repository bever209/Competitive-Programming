#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 1-INDEXED, SO ROOT IS AT INDEX 1 AND INDEX 0 IS NOT USED!!!!!
// node update range query
const int N = 2e5 + 5; // limit for array size
int n;                 // array size - FOR CONSISTENCY MAKE A POWER OF 2 (NOT REQUIRED THOUGH)
int t[2 * N];

void build()
{ // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int p, int value)
{ // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r)
{ // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

void set_val(int ind, int val)
{
    t[ind + n] = val;
}