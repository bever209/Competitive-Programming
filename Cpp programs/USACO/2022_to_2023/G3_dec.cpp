#include <bits/stdc++.h>
#define mp make_pair
#define pq priority_queue
#define pb push_back
#define f first
#define s second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using str = string;
using vivi = vector<vi>;

using vll = vector<ll>;
using vpii = vector<pii>;
using vb = vector<bool>;

const ll inf = 2 * 1e18;

vector<vi> adj;
vb vis;
vi dfs(int node){
    vis[node]=true;
    vi a;a.pb(node);
    for (int i:adj[node]){
        if (!vis[i]){
            vi x=dfs(i);
            for (int i:x) a.pb(i);
        }
    }
    return a;
}
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
void p(int x){
    cout<<x<<endl;
}
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    adj.resize(n);

//    p(0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi d(n);
    for (int i = 0; i < n; ++i) d[i] = adj[i].size();

    vis.resize(n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            vi a = dfs(i);
            if (ans>a.size()*a.size()) continue;

            set < pii > pq;
//            int min_deg = n;

            for (int j:a) pq.insert({d[j], j});
            vpii ord; // holds degree when cut, then node
            while (!pq.empty()) {
                auto x = *(pq.begin());
                pq.erase(pq.begin()); // maybe don't need?
                for (int k:adj[x.s]) {
                    if (pq.find({d[k], k}) != pq.end()) {
                        pq.erase({d[k], k});
                        --d[k];
                        pq.insert({d[k], k});
                    }
                }
                ord.pb(x);
            }
            reverse(ord.begin(), ord.end());
            DSU dsu; // NEED TO FIX, IS O(N^2)
            dsu.init(n);
            vb in(n);
            for (auto jj:ord) {
                int j=jj.s;
                in[j]=true;
                for (int k:adj[j]){
                    if (in[k]){
                        dsu.unite(k,j);
                    }
                }
                ans=max(ans,(ll)jj.f*dsu.size(j));
            }
        }
    }
    cout << ans << endl;


    return 0;
}
