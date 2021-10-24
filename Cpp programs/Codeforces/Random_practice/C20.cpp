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

int main() {

// #define int long long
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];

    for (int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        --a;--b;
        adj[a].pb({b,c});adj[b].pb({a,c});
    }

    pq<pair<ll,ll>> q;
    vector<bool> vis(n,false);
    vector<ll> dist(n,inf);
    vector<int> prev(n,-1);

    q.push({-0,0}); // remember -dist,node
    dist[0]=0;
    while (!q.empty()){
        pair<int,int> y=q.top();q.pop();
        int b;b=y.s;
        if (!vis[b]) {
            vis[b]=true;
            for (pair<int,int> i:adj[b]){
                int c,d;tie(c,d)=i;
                if (dist[b]+d<dist[c]){
                    dist[c]=dist[b]+d;
                    prev[c]=b;
                    q.push({-dist[c],c});
                }

            }
        }


    }
    vi ans;
    int node=n-1;
    if (prev[node]==-1){
        cout<<-1<<endl;return 0;
    }
    while (node!=-1){
        ans.pb(node);
        node=prev[node];

    }
    reverse(ans.begin(),ans.end());
    for (int i:ans){
        cout<<i+1<<" ";
    }

    return 0;
}

