#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5; // limit for array size
const int n;                 // array size
int t[2 * N];
int mx = 1e9 + 10;

void build()
{ // build the tree after reading in the array
    for (int i = n - 1; i > 0; --i)
    {
        t[i] = min(t[i << 1], t[i << 1 | 1]);
    }
}

void modify(int p, int value) // call this when reading in the array data
{                             // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = min(t[p], t[p ^ 1]);
}

int query(int l, int r) // on range [l,r) remember, EXCLUSIVE ON R
{
    int res = mx;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {

        if (l & 1)
            res = min(t[l++], res);
        if (r & 1)
            res = min(t[--r], res);
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

    int q;
    cin >> n >> q;
    for (int i = 0; i < 2 * N; ++i)
    {
        t[i] = mx;
    }

    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        set_val(i, a);
    }
    build();

    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r + 1) << "\n";
    }

    return 0;
}