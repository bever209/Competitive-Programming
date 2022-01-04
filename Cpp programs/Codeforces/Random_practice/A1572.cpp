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

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--) {
        int n;
        cin >> n;
        vi to(n);
        vector<vi> adj(n);
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            to[i] = k;
            for (int j = 0; j < k; ++j) {
                int a;
                cin >> a;
                --a;
                adj[a].pb(i);
            }
        }

        deque<int> q;
        vector<bool> vis(n, false);
        vi dist(n, -1e9);
        for (int i = 0; i < n; ++i)
            if (to[i] == 0) {
                q.push_back(i);
                dist[i] = 0;
            }
        while (!q.empty()) {
            int x = q.front();
            q.pop_front();
            for (int i:adj[x]) {
                --to[i];
                if (to[i] >= 0) {
                    if (i > x) {
                        dist[i] = max(dist[i], dist[x]);
                    } else {
                        dist[i] = max(dist[i], dist[x] + 1);
                    }
                }
                if (to[i] == 0) {
                    if (dist[i] == dist[x]) q.push_front(i);
                    else q.push_back(i);
                }
            }

        }
        int m = -1;
        for (int i:to) m = max(m, i);
        if (m > 0) {
            cout << -1 << endl;
            continue;
        }

        int mx = -1;
        for (int i:dist) { mx = max(mx, i); }
        cout << mx + 1 << endl;

    }

    return 0;
}

