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

struct Tree {
    vector<int> height, euler, first, segtree,ss,out;
    vector<bool> visited;
    int n;

    Tree(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);ss.resize(n);out.resize(n);
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
        euler.push_back(node);ss[node]=1;
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);ss[node]+=ss[to];
            }
        }
        out[node]=euler.size();
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
    bool in(int u,int v) { // v is in the subtree of u
        return first[u]<=first[v] && out[u]>=out[v];
    }
    int subtree_size(int u){
        return ss[u];
    }
};


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);


    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        vector<vi> adj(n);
        for (int i=0;i<n-1;++i){
            int a,b;cin>>a>>b;
            adj[a].pb(b);adj[b].pb(a);
        }
        Tree x(adj);
        vector<ll> ans(n+1);

        for (int i=0;i<=n;++i){
            if (i==0){
                for (int j:adj[0]){
                    int p=x.subtree_size(j);
                    ans[0]+=(p*(p-1))/2;
                }
            }
            else{
                if (!(x.in(i-1,i) || x.in(i,i-1))){
                    
                    break;
                }
                else{

                }
            }

        }

    }


    return 0;
}

