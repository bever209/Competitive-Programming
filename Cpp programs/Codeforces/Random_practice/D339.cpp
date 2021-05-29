#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 0-indexed

// node update range query

const int N = 2e5 + 5; // limit for array size
ll n;                  // array size
ll tree[4 * N + 5];
ll arr[N];
ll x;
int mx = 2e9;

void comb(int node, int val)
{
    if (val % 2 == x % 2)
    {
        tree[node] = (tree[node * 2 + 1] | tree[2 * node + 2]);
    }
    else
    {
        tree[node] = (tree[node * 2 + 1] ^ tree[2 * node + 2]);
    }
}

void construct(int node, int l, int r, int val)
{
    if (l == r)
    {
        tree[node] = arr[l];
    }
    else
    {
        int mid = (l + r) / 2;
        construct(node * 2 + 1, l, mid, val + 1);
        construct(node * 2 + 2, mid + 1, r, val + 1);
        comb(node, val);
    }
}
void construct()
{
    construct(0, 0, n - 1,1);
}

void aset(int node, int l, int r, ll val, int q,int parity)
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
        aset(node * 2 + 1, l, mid, val, q,1-parity);
    }
    else
    {
        aset(node * 2 + 2, mid + 1, r, val, q,1-parity);
    }
    comb(node,parity);
}

void hset(ll val, int q)
{
    aset(0, 0, n - 1, val, q,1);
}

ll query(int node, int l, int r, int lq, int rq,int parity)
{
    if (l > rq || r < lq)
    {
        return 0;
    }
    if (l >= lq && r <= rq)
    {
        return tree[node];
    }

    int mid = (l + r) / 2;
    ll s1 = query(node * 2 + 1, l, mid, lq, rq,1-parity);
    ll s2 = query(node * 2 + 2, mid + 1, r, lq, rq,1-parity);
    if (parity==x%2){
        // or 
        return s1|s2;
    }
    else{
        return s1^s2;
    }
}

ll query(int l, int r)
{
    return query(0, 0, n - 1, l, r,1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x;
    n =(ll) pow(2, x);

    int m;
    cin >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    construct();
    /*for (int i=0;i<8;++i){
        cout<<tree[i]<<" ";
    }
    cout<<"\n";*/
    for (int i = 0; i < m; ++i)
    {
        int p, b;
        cin >> p >> b;
        hset(b, p - 1);
        cout<<query(0, n - 1)<<"\n";
    }

    return 0;
}