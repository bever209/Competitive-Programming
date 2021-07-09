#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5; // limit for array size
const int n;                 // array size
ll tree[4 * N + 5];
ll arr[N];
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

void aset(int node, int l, int r, ll val, int q)
{
    if (l > q || r < q)
    {
        return;
    }
    if (q == l && q == r)
    {
        tree[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= q)
    {
        aset(node * 2 + 1, l, mid, val, q);
    }
    else
    {
        aset(node * 2 + 2, mid + 1, r, val, q);
    }
    comb(node);
}

void hset(ll val, int q)
{
    aset(0, 0, n - 1, val, q);
}

ll query(int node, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq)
    {
        return mx;
    }
    if (l >= lq && r <= rq)
    {
        return tree[node];
    }

    int mid = (l + r) / 2;
    ll s1 = query(node * 2 + 1, l, mid, lq, rq);
    ll s2 = query(node * 2 + 2, mid + 1, r, lq, rq);
    return min(s1, s2);
}

ll query(int l, int r)
{
    return query(0, 0, n - 1, l, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    construct();

    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;
        int a, b;
        cin >> a >> b;
        if (type == 1)
        {
            hset(b, a - 1);
        }
        else
        {
            cout << query(a - 1, b - 1) << "\n";
        }
    }

    return 0;
}