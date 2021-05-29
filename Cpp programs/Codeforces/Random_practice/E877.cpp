#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;
using ll = long long;


const int N = 2e5 + 5; // limit for array size
int n = 1;
ll tree[4 * N + 5];
ll arr[N];
ll lazy[4 * N + 5];
ll mx = (ll)1e15;

void push(int node, int l, int r)
{
    lazy[node]%=2;
    if (lazy[node]){
        tree[node]=r-l+1-tree[node];
        if (l!=r){
        lazy[2*node+1]++;
        lazy[2*node+2]++;
        }
        lazy[node]=0;
    }

}
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

void add(int node, int l, int r, int lq, int rq)
{
    push(node, l, r);
    if (l > rq || r < lq)
    {
        return;
    }
    if (l >= lq && r <= rq)
    {
        ++lazy[node];
        push(node, l, r);
        return;
    }
    int mid = (l + r) / 2;

    add(node * 2 + 1, l, mid, lq, rq);
    add(node * 2 + 2, mid + 1, r, lq, rq);
    comb(node);
}

void flip(int lq, int rq)
{
    add(0, 0, n - 1, lq, rq);
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

    return (query(node * 2 + 1, l, mid, lq, rq)+ query(node * 2 + 2, mid + 1, r, lq, rq));
}

ll query(int lq, int rq)
{
    return query(0, 0, n - 1, lq, rq);
}

vector<int> euler;
int subtree_size[200000+100];

void dfs(int node,int parent,vector<int> list[]){
    euler.pb(node);
    subtree_size[node]++;
    for (int i:list[node]){
        if (i!=parent){
            dfs(i,node,list);
            subtree_size[node]+=subtree_size[i];
        }
    }
}

int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin>>n;

    int parent[n+1];
    for (int i=2;i<=n;++i){
        cin>>parent[i];
    }
    int type[n+1];
    for (int i=1;i<=n;++i){
        cin>>type[i];
    }
    vector<int> list[n+1];
    for (int i=2;i<=n;++i){
        list[parent[i]].pb(i);
    }
    dfs(1,-1,list);
    
    int t;cin>>t;

    int loc[n+1];
    int cnt=0;
    for (int i=1;i<=n;++i){
        loc[euler.at(i-1)]=i-1;
    }


    for (int i=1;i<=n;++i){
        arr[i-1]=type[euler.at(i-1)];
    }


    construct();
    for (int v=0;v<t;++v){
        string word;cin>>word;
        int val;
        cin>>val;
        if (word=="get"){
            cout<<query(loc[val],loc[val]+subtree_size[val]-1)<<endl;

        } 
        else{
            flip(loc[val],loc[val]+subtree_size[val]-1);
        }
    }



    return 0;
}