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

vector<vi> adj;

const ll inf = 2 * 1e18;

vi color;vi white;// 0
vi black;
void dfs(int par,int node) {
    if (node != 0) {
        color[node] = 1 - color[par];
    }
    for (int i:adj[node]) {
        if (i != par)
            dfs(node, i);
    }
}

void solve() {
    white.clear();
    black.clear();
    adj.clear();
    color.clear();

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    color.resize(n);
    int c0 = 0;
    int c1 = 0;

    dfs(-1, 0);


    for (int i = 0; i < color.size(); ++i) {
        if (color[i] == 0) {
            ++c0;
            white.pb(i);
        } else {
            ++c1;
            black.pb(i);
        }
    }
    /*cout<<"white\n";
    for (int i: white)cout<<i<<" ";
    cout<<endl;
    cout<<"black\n";
    for (int i:black)cout<<i<<" ";
    cout<<endl;*/




    int ind = 0;
    vi ans(n);
    vector<bool> used(n + 1, false);
    if (c0 >= c1) {
        swap(white, black);
        swap(c0, c1);
    }
    for (int i = 0; i <= 20; ++i) {
        if ((int) pow(2, i) & c0) {
            for (int j = pow(2, i); j < pow(2, i + 1); ++j) {
                ans[white[ind]] = j;
                ++ind;
                used[j] = true;
            }
        }
    }

    ind = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ans[black[ind]] = i;
            ++ind;
        }
    }
    for (int i:ans) cout << i << " ";
    cout << endl;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }


    return 0;
}

