#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 0-indexed
//  range query and range update

const int N = 2e5 + 5; // limit for array size
int n = 1;            
ll tree[4 * N + 5];
ll arr[N];
ll lazy[4 * N + 5];
ll mx = (ll)1e15;

void push(int node, int l, int r)
{
    tree[node] += lazy[node];
    if (l != r)
    {
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }

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
    push(node,l,r);
    if (l > rq || r < lq)
    {
        return;
    }
    if (l >= lq && r <= rq)
    {
        lazy[node] += val;
        push(node,l,r);
        return;
    }
    int mid = (l + r) / 2;

    add(node * 2 + 1, l, mid, val, lq, rq);
    add(node * 2 + 2, mid + 1, r, val, lq, rq);
    comb(node);
}

void add(ll val, int lq, int rq)
{
    add(0, 0, n - 1, val, lq, rq);
}

ll query(int node, int l, int r, int lq, int rq)
{
    push(node,l,r);
    if (l > rq || r < lq)
    {
        return mx;
    }
    if (l >= lq && r <= rq)
    {
        return tree[node];
    }

    int mid = (l + r) / 2;

    return min(query(node * 2 + 1, l, mid, lq, rq), query(node * 2 + 2, mid + 1, r, lq, rq));
}

ll query(int lq, int rq)
{
    return query(0, 0, n - 1, lq, rq);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < 4 * N + 5; ++i)
    {
        tree[i] = -mx;
        lazy[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    construct();
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int l, r;
        /*for (int j=0;j<=8;++j){
            cout<<tree[j]<<" ";
        }
        cout<<"\n";
        for (int j=0;j<=8;++j){
            cout<<lazy[j]<<" ";
        }
        cout<<"\n";*/
        cin >> l >> r;
        if (cin.peek() != '\n')
        {
            ll c;
            cin >> c;

            if (l <= r)
            {
                add(c, l, r);
            }
            else
            {
                add(c, l, n - 1);
                add(c, 0, r);
            }
        }
        else
        {
            if (l <= r)
            {
                cout << query(l, r) << "\n";
            }
            else
            {
                cout << min(query(0, r), query(l, n - 1)) << "\n";
            }
        }
    }

    return 0;
}