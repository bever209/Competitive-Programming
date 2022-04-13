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

bool bip=true;
vector<vi> adj;vi color;vi xx;vi yy;
vector<bool> vis;int c0=0;int c1=0;
void dfs(int node,int c) {
    vis[node]=true;
    color[node] = c;

    if (c == 0) ++c0, xx.pb(node);
    if (c == 1) ++c1, yy.pb(node);
    for (int i:adj[node]) {
        if (!vis[i]) {
            dfs(i, 1 - c);
        } else {
            if (color[node] == color[i]) {
                bip = false;
            }
        }
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int x, y, z;
    cin >> x >> y >> z;

    adj.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vis.resize(n);
    color.resize(n);
    vector<pii> ops;
    vector<pair<vi, vi>> nodes;
    for (int i = 0; i < n; ++i) {
        xx.clear();
        yy.clear();
        if (!vis[i]) {
            c0 = 0;
            c1 = 0;
            dfs(i, 0);
            ops.pb({c0, c1});
            nodes.pb({xx, yy}); // make sure they aren't linked or smth
        }
    }
    if (!bip) {
        cout << "NO" << endl;
//        cout<<"not bip";
    } else {
        int need = y;
        vector<vector<pair<bool, int>>> dp(ops.size() + 1, vector<pair<bool, int>>(need + 1));
        dp[0][0] = {true, -1};
        for (int i = 1; i <= ops.size(); ++i) {
            for (int j = 0; j <= need; ++j) {
                if (j - ops[i - 1].f >= 0 && dp[i - 1][j - ops[i - 1].f].f) {
                    dp[i][j] = {true, 0}; // 0 for first, 1 for second
                }
                if (j - ops[i - 1].s >= 0 && dp[i - 1][j - ops[i - 1].s].f) {
                    dp[i][j] = {true, 1};
                }
            }
        }
        if (dp[ops.size()][need].f) {
            cout << "YES" << endl;
            int val = need;
            int num = ops.size();
            vi two;
            vi others;
            while (num > 0) {
                pii aa = dp[num][val];
                int red;
                if (aa.s == 0) {
                    red = ops[num - 1].f;
                    for (int i:nodes[num - 1].f) two.pb(i);
                    for (int i:nodes[num - 1].s) others.pb(i);
                } else {
                    red = ops[num - 1].s;
                    for (int i:nodes[num - 1].f) others.pb(i);
                    for (int i:nodes[num - 1].s) two.pb(i);

                }
                --num;
                val -= red;
            }
            vi ans(n);
            for (int i:two) ans[i] = 2;
            for (int i = 0; i < others.size(); ++i) {
                if (i < z) ans[others[i]] = 3;
                else ans[others[i]] = 1;
            }
            for (int i:ans) cout << i;
        } else {
            cout << "NO";
        }

    }


    return 0;
}

