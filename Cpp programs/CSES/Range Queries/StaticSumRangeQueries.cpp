#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

void set(int ind, int v)
{
    add(ind, -arr[ind]);
    arr[ind] = v;
    add(ind, arr[ind]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;

    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        add(i, arr[i]);
    }
    for (int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
    return 0;
}