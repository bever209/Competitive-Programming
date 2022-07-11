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
vector<vector<pii>> adj;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;

    adj.resize(n);
    for (int i=0;i<m;++i){
        int a,b,c;cin>>a>>b>>c;--a;--b;
        adj[a].pb({b,c});adj[b].pb({a,c});
    }

    


    return 0;
}

