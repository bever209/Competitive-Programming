#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;
using ll = long long;


const int N = 2e5 + 5; // limit for array size
int n;                 // array size - NEEDS TO BE A POWER OF 2
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

int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("bphoto.in","r",stdin);
	freopen("bphoto.out","w",stdout);

    cin>>n;
    pair<int,int> x[n];
    for (int i=0;i<n;++i){
        int d;cin>>d;
        x[i]=make_pair(d,i);
    }
    sort(x,x+n);
    for (int i=0;i<n;++i){
        arr[x[i].s]=i;
    }
    int left[n];
    int right[n];
    for (int i=0;i<n;++i){
        add(1,0,arr[i]-1);
        left[i]=query(arr[i]);
    }
    for (int i=0;i<n;++i){
        right[i]=query(arr[i])-left[i];
    }
    int ans=0;
    for (int i=0;i<n;++i){
        //cout<<left[i]<<" "<<right[i]<<"\n";
        if (left[i]*2<right[i]||right[i]*2<left[i]){
            ++ans;
        }
    }
    cout<<ans<<endl;





    return 0;
}