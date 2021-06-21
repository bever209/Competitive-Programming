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
vector<vector<int>> adj;
vector<bool> vis;
ll c=0;
bool cycle;

void dfs(int node){
    ++c;
    vis[node]=true;
    if (adj[node].size()==1){
        cycle=false;
    }
    for (int i:adj[node]){
        if (!vis[i]){
            dfs(i);
        }
    }

}


int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        int n,m;
        cin>>n>>m;
        adj.resize(n);
        for (int i=0;i<n;++i){
            adj[i].clear();
        }
        for (int i=0;i<m;++i){
            int c,d;
            cin>>c>>d;
            --c;
            --d;
            adj[c].pb(d);adj[d].pb(c);
        }

        vis.resize(n);
        for (int i=0;i<n;++i){
            vis[i]=false;
        }
        ll ans=0;
        for (int i=0;i<n;++i){
            c=0;
            cycle=true;
            if (!vis[i] && adj[i].size()>0){
                dfs(i);
                if (c!=1){
                    if (cycle){
                        ans+=c+1;
                    }
                    else{
                        ans+=c-1;
                    }
                }
            }
        }
        cout<<ans<<endl;


    }

    return 0;
}