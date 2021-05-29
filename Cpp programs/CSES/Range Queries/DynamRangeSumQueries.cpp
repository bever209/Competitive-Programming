#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5; // limit for array size
int n;                 // array size
ll t[2 * N];

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

ll query(int l, int r)
{ // sum on interval [l, r)
    ll res = 0;
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll q;
    cin >> n >> q;

    for (ll i = 1; i <= n; ++i)
    {
        ll a;
        cin >> a;
        set_val(i, a);
    }
    build();

    for (ll i = 0; i < q; ++i)
    {
        ll type;
        cin >> type;
        ll a, b;
        cin >> a >> b;
        if (type == 1)
        {
            modify(a, b);
        }
        else
        {
            cout << query(a, b + 1) << "\n";
        }
    }

    return 0;
}