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

struct DSU {
    vector<int> v;

    DSU(int n) { v = vi(n, -1); }

    int get(int x) {
        if (v[x] < 0) {
            return x;
        } else {
            v[x] = get(v[x]);
            return v[x];
        }
    }

    bool same_set(int x, int y) {
        return get(x) == get(y);
    }

    int size(int x) {
        return -v[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) { return false; }
        if (v[x] > v[y]) { swap(x, y); }
        v[x] += v[y];
        v[y] = x;
        return true;
    }
};
vector<vector<pii>> adj;
vi dist;

void dfs(int par,int node){
    for (auto  i:adj[node]){
        if (i.f!=par) {
            dist[i.f]=dist[node]+i.s;
            dfs(node, i.f);

        }
    }
}


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int arr[n][n];
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            cin>>arr[i][j];
        }
    }
    bool c=true;
    vector<pair<int,pii>> v;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            if (arr[i][j]==0) c=false;
            v.pb({arr[i][j],{i,j}});
        }
    }
    if (!c){
        cout<<"NO";return 0;
    }
    sort(v.begin(),v.end());
    adj.resize(n);
    DSU dsu(n);
    for (auto i:v){
        int weight=i.f;
        int a=i.s.f;int b=i.s.s;
        if (!dsu.same_set(a,b)){
            dsu.unite(a,b);
            adj[a].pb({b,weight});
            adj[b].pb({a,weight});
        }
    }

    bool check=true;
    for (int i=0;i<n;++i){
        dist.clear();dist.resize(n);
        dfs(-1,i);

        for (int j=0;j<n;++j){
            if (dist[j]!=arr[i][j]){
                check=false;break;
            }
        }
    }
    if (check){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }


    return 0;
}

