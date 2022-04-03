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
vector<vi> adj;
vi color;
vector<bool> vis;int n;
bool bipartite()
{
    bool bip = true;

    for(long long i = 0;i < n;i++)
        color[i] = -1;

    queue<long long> q;

    for(long long i = 0;i < n;i++){
        if(color[i] != -1)continue;

        q.push(i);
        color[i] = 0;

        while(!q.empty()){
            long long v = q.front();
            q.pop();

            for(long long u: adj[v]){
                if(color[u] == -1){
                    color[u] = color[v] ^ 1;
                    q.push(u);
                }else bip &= color[u] != color[v];
            }
        }
    }
    return bip;
}


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int m;
        cin >> n >> m;
        vi v(n);
        vi t(n);
        color.resize(n,0);
        vis.resize(n,false);
        adj.clear();
        adj.resize(n);
        vector<pii> edge_list;
        for (int i = 0; i < n; ++i) cin >> v[i];
        for (int i = 0; i < n; ++i) cin >> t[i];

        ll sum = 0;
        for (int i = 0; i < n; ++i) sum = (sum + v[i] - t[i])%2;
        sum=abs(sum);

        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            adj[x].pb(y);
            adj[y].pb(x);
            edge_list.pb({x, y});
        }
        if (sum % 2 != 0) {
            cout << "NO\n";
            continue;
        }



        if (bipartite()==false) {
            cout << "YES\n";
        } else {
            ll x = 0;
            ll y = 0;
            for (int i = 0; i < n; ++i) {
                if (color[i] == 0) {
                    x = x + (t[i] - v[i]);
                } else {
                    y = y + (t[i] - v[i]);
                }
            }
            if (x == y) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }

    }


    return 0;

}

