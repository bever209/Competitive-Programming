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
const int mod=1e9+7;
vector<vi> adj;

#define endl "\n"
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
    int getHeight(int u){
        return height[u];
    }
};

ll binpow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1)
            res = (res*a) % mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}
ll twoinv;

ll dp[205][205]; // probabiility of getting to i first if it is x away and j is y away (dp[x][y])
void init(){
    for (int i=1;i<205;++i){
        for (int j=1;j<205;++j){
            dp[i][j]=(twoinv * (dp[i-1][j]+dp[i][j-1])) % mod;
        }
    }
}

int main() {
    twoinv=binpow(2,mod-2);

    ll ans=0;
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    adj.resize(n);
    for (int i=0;i<n-1;++i){
        int a,b;cin>>a>>b;--a;--b;
        adj[a].pb(b);adj[b].pb(a);
    }
    for (int i=0;i<205;++i) for (int j=0;j<205;++j) dp[i][j]=-1;
    for (int i=0;i<205;++i){
        dp[i][0]=0;dp[0][i]=1;
    }init();

    for (int i=0;i<n;++i){
        LCA lca(adj,i) ;
        for (int j=0;j<n;++j){
            for (int k=j+1;k<n;++k){
                int l=lca.lca(j,k);
                int h1=lca.getHeight(j);int h2=lca.getHeight(k);

                int sub=lca.getHeight(l);
                h1-=sub;h2-=sub;
                ans=(ans+dp[h2][h1]) % mod;

            }
        }
    }
    ans=(ans*binpow(n,mod-2)) % mod;
    while (ans<0) ans+=mod;
    cout<<ans<<endl;




    return 0;
}

