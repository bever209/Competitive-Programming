#include <bits/stdc++.h>
using namespace std;
using ll = long long;  // 0-indexed
#define pb push_back
#define f first
#define s second

// node update range query

const int N = 2e5 + 5; // limit for array size
int n;                 // array size - NEEDS TO BE A POWER OF 2 
pair<ll,ll> tree[4 * N + 5];
ll arr[N];
int mx = 2e9;
// first is gcd, second is number of times it occurs
void comb(int node)
{
    tree[node].f = __gcd(tree[node*2+1].f,tree[node*2+2].f);
    int cnt=0;
    if (tree[node].f==tree[node*2+1].f){
        cnt+=tree[node*2+1].s;
    }
    if (tree[node].f==tree[node*2+2].f){
        cnt+=tree[node*2+2].s;
    }
    tree[node].s=cnt;
}

void construct(int node, int l, int r)
{
    if (l == r)
    {
        tree[node].f = arr[l];tree[node].s=1;
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

pair<ll,ll> query(int node, int l, int r, int lq, int rq)
{
    if (l > rq || r < lq)
    {
        return {0,0};
    }
    if (l >= lq && r <= rq)
    {
        return tree[node];
    }

    int mid = (l + r) / 2;
    pair<int,int> s1 = query(node * 2 + 1, l, mid, lq, rq);
    pair<int,int> s2 = query(node * 2 + 2, mid + 1, r, lq, rq);

    int gcd=__gcd(s1.f,s2.f);
    int ans=0;
    if (gcd==s1.f){
        ans+=s1.s;
    }
    if (gcd==s2.f){
        ans+=s2.s;
    }
    return {gcd,ans};
}

pair<int,int> query(int l, int r)
{
    return query(0, 0, n - 1, l, r);
}


int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    construct();

    int m;
    cin>>m;
    for (int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        cout<<b-a+1-query(a-1,b-1).s<<endl;
    }


    return 0;
}