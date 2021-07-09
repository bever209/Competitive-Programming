// For adding to a range but querying only 1 value
//  IDK IF IT WORKS, TEST USING CSES OR CF OR SMTH
#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 0-indexed
//  node query and range update

const int N = 2e5 + 5; // limit for array size
int n;                 // array size
ll tree[4 * N + 5];
ll arr[N];
ll ops[4 * N + 5];
int mx = 2e9;

void comb(int node)
{
    tree[node] = min(tree[node * 2 + 1], tree[2 * node + 2]);
}

void construct(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = arr[l];
    }
    else
    {
        int mid = (l + r) / 2;
        construct(node * 2 + 1, l, mid);
        construct(node * 2 + 2, mid + 1, r);
        comb(node);
    }
}
void construct()
{
    construct(0, 0, n - 1);
}

void add(int node, int l, int r, ll val, int lq, int rq)
{
    if (l > rq || r < lq)
    {
        return;
    }
    if (l >= lq && r <= rq)
    {
        ops[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    add(node * 2 + 1, l, mid, val, lq, rq);
    add(node * 2 + 2, mid + 1, r, val, lq, rq);
}

void add(ll val, int lq, int rq)
{
    add(0, 0, n - 1, val, lq, rq);
}

ll query(int node, int l, int r, int x)
{
    if (l > x || r < x)
    {
        return 0;
    }
    if (l == r && l == x)
    {
        return tree[node] + ops[node];
    }

    int mid = (l + r) / 2;
    ll z = 0;
    if (mid >= x)
    {
        z = query(node * 2 + 1, l, mid, x);
    }
    else
    {
        z = query(node * 2 + 2, mid + 1, r, x);
    }
    return z + ops[node];
}

ll query(int x)
{
    return query(0, 0, n - 1, x);
}