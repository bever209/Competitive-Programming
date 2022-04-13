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
vi color;

void dfs(int node,int par,int c){
    color[node]=c;
    for (int i:adj[node]){
        if (i!=par){
            dfs(i,node,1-c);
        }
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        adj.clear();
        adj.resize(n);
        for (int i=0;i<n-1;++i){
            int a,b;cin>>a>>b;
            --a;--b;adj[a].pb(b);adj[b].pb(a);

        }
        color.clear();color.resize(n);
        dfs(0,-1,0);
        vi ans(n);
        for (int i=0;i<n;++i){
            if (color[i]==0){
                // positive
                ans[i]=adj[i].size();
            }
            else ans[i]=-adj[i].size();
        }
        for (int i:ans) cout<<i<<" ";
        cout<<endl;

    }


    return 0;
}

