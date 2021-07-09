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

int main()
{
    #define int long long


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>> adj(n);

    for (int i=0;i<m;++i){
        int a,b; ll c;
        cin>>a>>b>>c;
        --a;--b;
        adj[a].pb({b,c}); // node then dist
    }
    vector<bool> proc(n);
    vector<ll> dist(n);
    for (int i=0;i<n;++i){
        dist[i]=1e17;
    }
    dist[0]=0;
    pq<pair<ll,int>> q;
    q.push({0,0}); // dist then node
    while (!q.empty()){
        auto x=q.top();q.pop();
        int a=x.s;
        if (!proc[a]){
            proc[a]=true;
            for (pii i:adj[a]){
                int d;ll e;
                d=i.f;e=i.s;
                if (dist[a]+e<dist[d]){
                    dist[d]=min(dist[d],dist[a]+e);
                    q.push({-dist[d],d});
                }

            }
        }
    }
    for (int i:dist){
        cout<<i<<" ";
    }



    return 0;
}
