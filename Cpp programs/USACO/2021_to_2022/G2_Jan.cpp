#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;

struct Type{
    str x;
    int y;
    int z;
};

vi ans;
vector<vi> adj;
vector<bool> on;
vector<bool> vis;
void dfs(int node,int time){
    vis[node]=true;
    ans[node]=max(ans[node],time);
    for (int i:adj[node]){
        if (!vis[i]){
            dfs(i,time);
        }
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;cin>>n>>q;
    ans.resize(n,-1);
    adj.resize(n);
    on.resize(n,true);

    vector<pii> edge_list;
    vector<bool> in; // if it is in, then true
    vector<Type> ops;

    while (q--){
        str a;cin>>a;
        if (a=="D"){
            int x;cin>>x;--x;
            on[x]=false;
            ops.pb({a,x,-1});
        }
        else if (a=="A"){
            int x,y;cin>>x>>y;--x;--y;
            edge_list.pb({x,y});
            in.pb(true);
            ops.pb({a,x,y});
        }
        else if (a=="R"){
            int x;cin>>x;
            --x;in[x]=false;
            ops.pb({a,x,-1});
        }
    }

    for (int i=0;i<edge_list.size();++i){
        int x,y;tie(x,y)=edge_list[i];
        if (in[i]){
            adj[x].pb(y);adj[y].pb(x);
        }
    }

    vis.resize(n);
    for (int i=0;i<n;++i){
        if (on[i] && !vis[i]){
            dfs(i,ops.size()-1);
        }
    }


    for (int i=ops.size()-1;i>=0;--i){
        Type x=ops[i];
        if (x.x=="D"){
            int a=x.y;on[a]=true;
            if (!vis[a]){
                dfs(a,i-1);
            }
        }
        else if (x.x=="R"){
            int a=x.y;
            pii y=edge_list[a];
            int b=y.f;int c=y.s;
            if (!vis[b] && vis[c]){
                dfs(b,i-1);
            }
            else if (vis[b] && !vis[c]){
                dfs(c,i-1);
            }
            adj[b].pb(c);adj[c].pb(b);
        }
    }
    for (int i:ans) cout<<i+1<<endl;




    return 0;
}

