#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;


struct DSU {
    vector<int> e;
    DSU(int N) { e = vi (N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);

    int n,m;
    cin>>n>>m;
    vi adj[n];
    for (int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int del[n];
    for (int i=0;i<n;++i){
        int a;
        cin>>a;--a;
        del[i]=a;
    }
    DSU dsu(n);
    bool on[n];
    for (int i=0;i<n;++i){
        on[i]=false;
    }
    int c=0;
    int ans[n]; // 1 yes 2 = no
    for (int i=n-1;i>=0;--i){
        int node=del[i];
        on[node]=true;++c;
        for (int i:adj[node]){
            if (on[i] && !dsu.same_set(i,node)){
                --c;
                dsu.unite(i,node);
            }
        }
        if (c>1){
            ans[i]=0;
        }
        else{
            ans[i]=1;
        }
    }
    for (int i:ans){
        if (i==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
