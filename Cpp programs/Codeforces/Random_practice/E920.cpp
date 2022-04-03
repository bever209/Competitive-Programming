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
    vi v;
    void init(int a){
        v=vi(a,-1);
    }

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
        if (x == y) {
            return false;
        }
        if (v[x] >= v[y]) {
            swap(x, y);
        }
        v[x]=v[x]+ v[y];
        v[y] = x;
        return true;
    }
};


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int  n,m;cin>>n>>m;

    DSU x;
    x.init(n);
    vector<vi> adj(n);
    for (int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        --a;--b;
        adj[a].pb(b);adj[b].pb(a);
    }
    vi a;
    for (int i=0;i<n;++i){
        if (adj[i].size()<n/2){
            a.pb(i);
        }
        else{
            vi in(n);
            for (int j:adj[i]) in[j]=true;
            for (int j=0;j<n;++j){
                if (!in[j]){
                    x.unite(i,j);
                }
            }
        }
    }
    for (int i=1;i<a.size();++i){
        x.unite(a[i-1],a[i]);
    }
//    int ans=0;
    set<pii> s;
    for (int i=0;i<n;++i){
        s.insert({x.get(i),x.size(i)});
    }
    cout<<s.size()<<"\n";vi ans;
    for (auto i:s){
        ans.pb(i.s);
    }
    sort(ans.begin(),ans.end());
    for (int i:ans) cout<<i<<" ";


    return 0;
}

