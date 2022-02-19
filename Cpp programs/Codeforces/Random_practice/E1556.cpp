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


const int N = 1e5 + 5; // limit for array size

template<class T> struct min_query_st {
    int n;                 // array size

    vector<T> tree;

    ll mx = 1e14+5;
    void init(int _n,vector<T> &arr){
        n=_n;tree.resize(4*N+5);
        construct(0, 0, n - 1,arr);
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


    void set(int node, int l, int r, T val, int q) {
        if (l > q || r < q) {
            return;
        }
        if (q == l && q == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (mid >= q) {
            set(node * 2 + 1, l, mid, val, q);
        } else {
            set(node * 2 + 2, mid + 1, r, val, q);
        }
        comb(node);
    }

    void set(int q,T val) {
        set(0, 0, n - 1, val, q);
    }

    T query(int node, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) {
            return mx;
        }
        if (l >= lq && r <= rq) {
            return tree[node];
        }

        int mid = (l + r) / 2;
        T s1 = query(node * 2 + 1, l, mid, lq, rq);
        T s2 = query(node * 2 + 2, mid + 1, r, lq, rq);
        return min(s1, s2);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
template<class T> struct max_query_st {
    int n;                 // array size

    vector<T> tree;

    //int mx = 2e9;
    void init(int _n,vector<T> &arr){
        n=_n;tree.resize(4*N+5);
        construct(0, 0, n - 1,arr);
    }
    void comb(int node) {
        tree[node] = max(tree[node * 2 + 1], tree[2 * node + 2]);
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


    void set(int node, int l, int r, T val, int q) {
        if (l > q || r < q) {
            return;
        }
        if (q == l && q == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (mid >= q) {
            set(node * 2 + 1, l, mid, val, q);
        } else {
            set(node * 2 + 2, mid + 1, r, val, q);
        }
        comb(node);
    }

    void set(int q,T val) {
        set(0, 0, n - 1, val, q);
    }

    T query(int node, int l, int r, int lq, int rq) {
        if (l > rq || r < lq) {
            return -1e15;
        }
        if (l >= lq && r <= rq) {
            return tree[node];
        }

        int mid = (l + r) / 2;
        T s1 = query(node * 2 + 1, l, mid, lq, rq);
        T s2 = query(node * 2 + 2, mid + 1, r, lq, rq);
        return max(s1, s2);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
#define int ll

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,q;cin>>n>>q;
    int a[n];
    for (int i=0;i<n;++i) cin>>a[i];
    int b[n];
    for (int i=0;i<n;++i) cin>>b[i];

    vi pref(n+2);
    for (int i=1;i<=n;++i){
        pref[i]=pref[i-1]+b[i-1]-a[i-1];
    }
    min_query_st<int> st;
    st.init(n+2,pref);
    max_query_st<int> max_st;
    max_st.init(n+2,pref);

    while (q--){
        int l,r;cin>>l>>r;
        int mn=st.query(l,r);
//        cout<<mn<<" "<<pref[l-1]<<endl;
        if (pref[r]-pref[l-1]==0 && mn-pref[l-1]>=0){
            cout<<max_st.query(l,r)-pref[l-1]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }


    return 0;
}

