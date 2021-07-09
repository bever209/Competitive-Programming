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
int ans=1e6;
vector<int> dist;
vector<bool> vis;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int m;
    cin>>n>>m;
    adj.resize(n);
    for (int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        --a;--b;
        adj[a].pb(b);adj[b].pb(a);

    }
    for (int j=0;j<n;++j) {
        dist.resize(n);
        for (int i = 0; i < n; ++i) {
            dist[i] = 1e6;
        }
        queue<int> q;
        q.push(j);
        dist[j] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i:adj[x]) {
                if (dist[i] != 1e6) {
                    if (dist[i]>=dist[x]) {
                        ans = min(ans, 1 + dist[i] + dist[x]);
                    }
                } else {
                    dist[i] = dist[x] + 1;
                    q.push(i);
                }
            }
        }
    }
    if (ans==1e6){
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
    }



    return 0;
}