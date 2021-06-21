#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;

const int N = 2e5 + 5; // limit for array size
int n;                 // array size
ll tree[4 * N + 5];
ll arr[N];
int mx = 2e9;

void comb(int node)
{
    tree[node] = max(tree[node * 2 + 1], tree[2 * node + 2]);
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

void change(int node, int l, int r, ll val, int q)
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
        change(node * 2 + 1, l, mid, val, q);
    }
    else
    {
        change(node * 2 + 2, mid + 1, r, val, q);
    }
    comb(node);
}

void change(ll val, int q)
{
    change(0, 0, n - 1, val, q);
}

ll query(int node, int l, int r, int lq, int rq)
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
    ll s1 = query(node * 2 + 1, l, mid, lq, rq);
    ll s2 = query(node * 2 + 2, mid + 1, r, lq, rq);
    return max(s1, s2);
}

ll query(int l, int r)
{
    return query(0, 0, n - 1, l, r);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    pair<int, int> list[n];
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        list[i] = mp(a, b);
        map[a] = i;
    }

    sort(list, list + n);
    int max_ind[n];
    for (int i = 0; i < n; ++i)
    {
        int left = i;
        int right = n - 1;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (list[mid].f < list[i].f + list[i].s)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        max_ind[i] = left;
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = max_ind[i];
    }
    construct();

    int ans[n];
    for (int i = n - 1; i >= 0; --i)
    {
        int min_ind = i;
        int maxind = max_ind[i];

        int num = query(min_ind, maxind);
        ans[map[list[i].f]] = num - i + 1;
        change(num, i);
    }
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}