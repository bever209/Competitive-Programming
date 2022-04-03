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

const int N = 3e5 + 5; // limit for array size

template<class T> struct rquery_st {
    int n;                 // array size

    vector<T> tree;

    int mx = 2e9;
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


    ios::sync_with_stdio(false);
    cin.tie(0);
#define int ll
    int n;cin>>n;
    int h[n];
    int b[n];
    for (int i=0;i<n;++i) cin>>h[i];
    for (int i=0;i<n;++i) cin>>b[i];

    rquery_st<ll> st;
    vector<ll> dp(n,-1e15);
    st.init(n,dp);

    vi sm(n,-1);
    stack<int> s;
    s.push(0);
    for (int i=1;i<n;++i){
        int x=h[i];
        while (s.size()>0 && h[s.top()]>x){
            s.pop();
        }
        if (s.size()>0){
            sm[i]=s.top();

        }
        s.push(i);
    }
    // works
    dp[0]=b[0];st.set(0,dp[0]);
    for (int i=1;i<n;++i){
        int left=sm[i];
        if (left<0){
            dp[i]=max(dp[i],b[i]);
            dp[i]=max(dp[i],st.query(0,i-1)+b[i]);
        }
        else{
            dp[i]=max(dp[i],dp[left]);
            dp[i]=max(dp[i],st.query(left,i-1)+b[i]);
        }
        st.set(i,dp[i]);
    }

//    for (int i:sm ) cout<<i<<" ";
//    cout<<endl;
//    for (int i:dp) cout<<i<<" ";
//    cout<<endl;
    cout<<dp[n-1];





    return 0;
}

