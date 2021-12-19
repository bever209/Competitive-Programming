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

const int N = 2e5 + 5; // limit for array size

template<class T> struct lazy_st {
    int n;
    vector<T> tree,lazy;
    int mx=1e9;

    void init(int _n,vector<T> &arr){ // arr is array of values, send it in
        n=_n;tree.resize(4*N+5);lazy.resize(4*N+5);
        construct(0, 0, n - 1,arr);
    }
    void push(int node, int l, int r) {
        tree[node] += lazy[node];
        if (l != r) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }

        lazy[node] = 0;
    }

    void comb(int node) {
        tree[node] = min(tree[node * 2 + 1], tree[2 * node + 2]);
    }

    void construct(int node, int l, int r,vector<T> &arr) {
        if (l == r) {
            tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            construct(node * 2 + 1, l, mid,arr);
            construct(node * 2 + 2, mid + 1, r,arr);
            comb(node);
        }
    }


    void add(int node, int l, int r, T val, int lq, int rq) {
        push(node, l, r);
        if (l > rq || r < lq) {
            return;
        }
        if (l >= lq && r <= rq) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;

        add(node * 2 + 1, l, mid, val, lq, rq);
        add(node * 2 + 2, mid + 1, r, val, lq, rq);
        comb(node);
    }

    void add(T val, int lq, int rq) {
        add(0, 0, n - 1, val, lq, rq);
    }

    T query(int node, int l, int r, int lq, int rq) {
        push(node, l, r);
        //cout<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;
        if (l > rq || r < lq) {
            return mx;
        }
        if (l >= lq && r <= rq) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        return min(query(node * 2 + 1, l, mid, lq, rq), query(node * 2 + 2, mid + 1, r, lq, rq));
    }

    T query(int lq, int rq) {
        return query(0, 0, n - 1, lq, rq);
    }
};

vector<vector<pii>> adj;
vi euler;
vi start;
//vi sub_size;
vi finish;
vi dist_from_1;
vi to_1;

void dfs(int node) {
    euler.pb(node);
    start[node] = euler.size() - 1;
    for (auto i:adj[node]) {
        if (i.f != 0) {
            dist_from_1[i.f] = (dist_from_1[node] + i.s);
            dfs(i.f);
        }
        else{
            to_1[node]=i.s;
        }
    }
    finish[node] = euler.size() - 1;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    adj.resize(n);
    vector<pair<pii, int>> edges;
    for (int i = 0; i < 2 * n - 2; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj[a].pb({b, c});
        edges.pb({{a, b}, c});
    }
    start.resize(n);
    finish.resize(n);
    dist_from_1.resize(n);
    to_1.resize(n);
    dfs(0);
    vi euler_loc(n);
    for (int i = 0; i < n; ++i) {
        euler_loc[i] = start[i];
    }
    vi x;
    for (int i:euler) {
        x.pb(dist_from_1[i] + to_1[i]);
    }
    lazy_st<int> st;
    st.init(x.size(), x);
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            --b;
            auto x = edges[b];
            int diff = c - edges[b].s;
            edges[b].s = c;
            if (edges[b].f.s == 0) {
                to_1[edges[b].f.f] = c;
                st.add(diff, euler_loc[edges[b].f.f], euler_loc[edges[b].f.f]);
            } else {
                int d = edges[b].f.s;
                st.add(diff, euler_loc[d], finish[d]);
            }
        } else {
            --b;
            --c;
            if (start[b] <= start[c] && finish[b] >= finish[c]) {
                int b_val = st.query(euler_loc[b], euler_loc[b]) - to_1[b];
                int c_val = st.query(euler_loc[c], euler_loc[c]) - to_1[c];
                cout << c_val - b_val << "\n";
            } else {
                int b_val = st.query(euler_loc[b], finish[b]);
                int y = st.query(euler_loc[b], euler_loc[b]) - to_1[b];
                int c_val = st.query(euler_loc[c], euler_loc[c]) - to_1[c];
                //cout<<b_val<<" "<<y<<" "<<c_val<<endl;
                b_val -= y;
                cout << c_val + b_val << "\n";
            }
        }
    }


    return 0;
}

