#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 1-indexed

const int mx = 2e5 + 5;
vector<ll> bit(1 + mx), arr(1 + mx); // arr contains actual values and bit is the BIT

void add(int ind, int v)
{
    for (; ind <= mx; ind += ind & (-ind))
    {
        bit[ind] += v;
    }
}
ll query(int ind)
{
    ll s = 0;
    for (; ind > 0; ind -= ind & (-ind))
    {
        s += bit[ind];
    }
    return s;
}
ll query(int l, int r)
{
    return query(r) - query(l - 1);
}

