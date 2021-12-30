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

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<pair<int,pii>> edges;
    for (int i=0;i<n;++i){
        int c;int w,x,y,z;
        cin>>c;cin>>w>>x>>y>>z;--w;--y;--x;--z;
        edges.pb({c,{w,y}});
        edges.pb({c,{w,z}});
        edges.pb({c,{x,y}});
        edges.pb({c,{x,z}});
        edges.pb({0,{w,x}});
        edges.pb({0,{y,z}});
    }
    DSU dsu(2*n);
    sort(edges.begin(),edges.end());
    int ans=0;
    for (int ind=0;ind<edges.size();++ind){
        int c=edges[ind].f;
        int start=edges[ind].s.f;int finish=edges[ind].s.s;
        if (!dsu.same_set(start,finish)){
            ans+=c;dsu.unite(start,finish);
        }
    }
    cout<<ans<<endl;



    return 0;
}

