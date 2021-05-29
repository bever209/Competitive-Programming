#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 0-indexed
//  range query and range update

const int N = 2e5 + 5; // limit for array size
int n;                 // array size
ll tree[4 * N + 5];
ll arr[N];
ll lazy[4 * N + 5];
ll mx = 2e9;

void push(int node, int l, int r)
{
    tree[node] += lazy[node] * (r - l + 1);

    lazy[2 * node + 1] += lazy[node];
    lazy[2 * node + 2] += lazy[node];

    lazy[node] = 0;
}
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
        lazy[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    ll a = val * (min(rq, r) - max(lq, l) + 1);
    tree[node] += a;
    add(node * 2 + 1, l, mid, val, lq, rq);
    add(node * 2 + 2, mid + 1, r, val, lq, rq);
}

void add(ll val, int lq, int rq)
{
    add(0, 0, n - 1, val, lq, rq);
}

ll query(int node, int l, int r, int lq, int rq)
{
    push(node, l, r);
    if (l > rq || r < lq)
    {
        return 0;
    }
    if (l >= lq && r <= rq)
    {
        return tree[node];
    }

    int mid = (l + r) / 2;
    ll z = 0;
    z += query(node * 2 + 1, l, mid, lq, rq);
    z += query(node * 2 + 2, mid + 1, r, lq, rq);
    return z;
}

ll query(int lq, int rq)
{
    return query(0, 0, n - 1, lq, rq);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    //cout << "hiiii";
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            add(v, l, r - 1);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(l, r - 1) << "\n";
        }
        /* for (int i = 0; i < 16; ++i)
        {
            cout << tree[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < 16; ++i)
        {
            cout << lazy[i] << " ";
        }
        cout << "\n";*/
    }

    return 0;
}