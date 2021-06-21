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
ll ops[4 * N + 5];
int mx = 2e9;

void comb(int node)
{
    tree[node] = (tree[node * 2 + 1]+ tree[2 * node + 2]);
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

void add(int node, int l, int r, ll val, int lq, int rq,int depth)
{
    if (l > rq || r < lq)
    {
        return;
    }
    if (l >= lq && r <= rq)
    {
        if (depth%2==0){
        ops[node] += val;}
        else{
            ops[node]-=val;
        }
        return;
    }
    int mid = (l + r) / 2;
    add(node * 2 + 1, l, mid, val, lq, rq,depth+1);
    add(node * 2 + 2, mid + 1, r, val, lq, rq,depth+1);
}

void add(ll val, int lq, int rq,int depth)
{
    add(0, 0, n - 1, val, lq, rq,depth);
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
vector<int> euler;
vector<bool> visit;
vector<int> size;

void dfs(int node,vector<int> list[]){
    visit[node]=true;
    euler.pb(node);
    for (int i:list[node]){
        if (!visit[i]){
            dfs(i,list);
            size[node]+=size[i];
        }
    }
}


int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);


    int m;
    cin>>n>>m;


    int a[n];
    for (int i=0;i<n;++i){
        cin>>a[i];
    }

    vector<int> list[n];
    for (int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        --a;--b;
        list[a].pb(b);list[b].pb(a);
    }

    for (int i=0;i<n;++i){
        visit.pb(false);
        size.pb(1);
    }

    dfs(0,list);
    for (int i=0;i<n;++i){
        arr[i]=a[euler[i]];
    }
    construct();

    int loc[n];
    for (int i=0;i<n;++i){
        loc[euler[i]]=i;
    }

    for (int i=0;i<m;++i){
        int type;
        cin>>type;
        if (type==1){
            int x,val;
            cin>>x>>val;
            --x;
            int l=loc[x];
            add(val,l,l,0);
            add(val,l+1,l+size[x]-1,1);
        }
        else{
            int x;
            cin>>x;
            --x;
            cout<<query(loc[x])<<endl;
        }
    }
    for (int i=0;i<10;++i){
        cout<<tree[i]<<" ";
        
    }
    cout<<endl;
    for (int i=0;i<10;++i){
        cout<<ops[i]<<" ";
    }

    return 0;
}