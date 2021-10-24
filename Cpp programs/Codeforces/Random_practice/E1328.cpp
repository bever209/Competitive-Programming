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
vector<vi> adj;
vi depth;vi par;vi in;vi out;int c;
void dfs(int node=0,int parent=-1){
    ++c;
    in[node]=c;
    par[node]=parent;
    for (int i:adj[node]){
        if (i!=parent){
            depth[i]=depth[node]+1;
            dfs(i,node);
        }
    }
    out[node]=c;
}
bool u_above_v(int u,int v){
    return in[u]<=in[v] && out[u]>=out[v];
}
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);


    int n,m;cin>>n>>m;
    adj.resize(n);depth.resize(n);par.resize(n);in.resize(n);out.resize(n);
    for (int i=0;i<n-1;++i){
        int a,b;cin>>a>>b;--a;--b;
        adj[a].pb(b);adj[b].pb(a);
    }
    dfs();
    for (int at=0;at<m;at++){
        c=0;
        int k;cin>>k;
        vi x;
        for (int i=0;i<k;++i){
            int a;cin>>a;--a;x.pb(a);
        }
        for (int i=0;i<k;++i){
            if (x[i]>0){
                x[i]=par[x[i]];
            }
        }
        int deepest_node=x[0];int xmax=0;
        for (int i:x){
            if (depth[i]>xmax){
                xmax=depth[i];
                deepest_node=i;
            }
        }
        bool check=true;
        int node=deepest_node;
        for (int i:x){
            if (i!=node){

                if (!u_above_v(i,node)){
                    check=false;break;
                }
            }
        }

        if (check){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }


    return 0;
}

