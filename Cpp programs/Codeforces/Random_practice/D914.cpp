#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 0-indexed

// node update range query

const int N = 5e5 + 5; // limit for array size
int n;                 // array size
ll tree[4 * N + 5];
ll arr[N];
int mx = 2e9;
int ans = 0;
int x = 0;
int la, ra;
int d = 1;

int gcd(int a, int b)
{
    if (a < b)
    {
        swap(a, b);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void comb(int node)
{
    tree[node] = gcd(tree[node * 2 + 1], tree[2 * node + 2]);
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

void query(int node, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq || ans > 1)
    {
        return;
    }
    if (l >= lq && r <= rq)
    {
        if (tree[node] % x != 0)
        {
            while (node < d)
            {
                if (tree[2 * node + 1] % x != 0)
                {
                    if (tree[2 * node + 2] % x != 0)
                    {
                        ans += 2;
                        return;
                    }
                    node = 2 * node + 1;
                }
                else
                {
                    node = 2 * node + 2;
                }
            }
            ++ans;
        }
       
        return;
    }

    int mid = (l + r) / 2;
    query(node * 2 + 1, l, mid, lq, rq);
    query(node * 2 + 2, mid + 1, r, lq, rq);
}

void query(int l, int r)
{
    query(0, 0, n - 1, l, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int w = n;
    while (d < n)
    {
        d = d * 2;
    }
    n = d;

    for (int i = 0; i < w; ++i)
    {
        cin >> arr[i];
    }
    construct();

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;
        ans = 0;
        /* for (int i = 0; i < 32; ++i)
        {
            cout << tree[i] << " ";
        }
        cout << "\n";*/

        if (type == 1)
        {
            int l, r;
            cin >> l >> r >> x;
            query(l - 1, r - 1);
            if (ans > 1)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
        else
        {
            int a, b;
            cin >> a >> b;
            hset(b, a - 1);
            arr[a - 1] = b;
        }
    }

    return 0;
}