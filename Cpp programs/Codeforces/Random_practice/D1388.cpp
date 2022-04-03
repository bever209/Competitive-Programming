#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;
vi a;vi b;vector<vi> adj;ll ans=0;vi order;vi add_at_end;
void dfs(int node){
    for (int i:adj[node]){
        dfs(i);
    }
    if (a[node]>0){
        ans+=a[node];
        if (b[node]>=0)
        a[b[node]]+=a[node];
        order.pb(node);
    }
    else{
        add_at_end.pb(node);
        ans+=a[node];
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    a.resize(n);b.resize(n);adj.resize(n);
    for (int i=0;i<n;++i) cin>>a[i];
    for (int i=0;i<n;++i) {
        cin >> b[i];
        if (b[i]>0) --b[i];
    }
    //MAYBE NEED TO USE LLS

    for (int i=0;i<n;++i){
        if (b[i]!=-1){
            adj[b[i]].pb(i);
        }
    }
    for (int i=0;i<n;++i){
        if (b[i]==-1){
            dfs(i);
        }
    }
    cout<<ans<<"\n";
    for (int i:order) {
        cout << i + 1 << " ";
    }
    reverse(add_at_end.begin(),add_at_end.end());
    for (int i:add_at_end) {
        cout << 1 + i << " ";

    }

    return 0;
}

