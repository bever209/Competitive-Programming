#include <bits/stdc++.h>
// FIX, DOESN'T WORK
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
vector<vi> adj;vi color;set<int> cyc;vi cnt;vector<bool> neg;

void dfs(int node){
    color[node]=1;
    for (int i:adj[node]){
        cnt[i]+=cnt[node];cnt[i]=min(cnt[i],10);
        if (color[i]==0){
            dfs(i);
        }
        else if (color[i]==1){
            cyc.insert(i);
        }
    }
    color[node]=2;
}

void bfs(const vi& start){
    queue<int> q;
    for (int i:start) q.push(i),neg[i]=true;

    while (!q.empty()){
        int x=q.front();q.pop();
        for (int i:adj[x]){
            if (!neg[i]){
                neg[i]=true;q.push(i);
            }
        }
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        adj.clear();
        adj.resize(n);
        color.clear();
        color.resize(n);
        cyc.clear();
        cnt.clear();
        cnt.resize(n);
        neg.clear();
        neg.resize(n);

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            adj[a].pb(b);
        }
        cnt[0]=1;
        dfs(0);
        vi aa;
        for (int i:cyc) aa.pb(i);
        bfs(aa);
        vi ans(n);
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == 0) ans[i] = 0;
            else if (cnt[i] == 1) ans[i] = 1;
            else ans[i] = 2;
        }
        for (int i = 0; i < n; ++i) {
            if (neg[i]) ans[i] = -1;
        }
        for (int i:ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}