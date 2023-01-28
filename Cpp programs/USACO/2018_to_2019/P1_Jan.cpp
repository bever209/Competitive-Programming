#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
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
        auto a=tree[2*node+1];
        auto b=tree[2*node+2];
        if (a.f<b.f){
            tree[node]=a;return;
        }
        else if (b.f<a.f){
            tree[node]=b;return;
        }

        if (a.s<b.s){
            tree[node]=a;
        }
        else tree[node]=b;
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
            return {N+10,0};
        }
        if (l >= lq && r <= rq) {
            return tree[node];
        }

        int mid = (l + r) / 2;
        T s1 = query(node * 2 + 1, l, mid, lq, rq);
        T s2 = query(node * 2 + 2, mid + 1, r, lq, rq);
        if (s1.f<s2.f) return s1;
        if (s2.f<s1.f) return s2;
        if (s1.s<s2.s) return s1;
        else return s2;
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("redistricting.in","r",stdin);
    freopen("redistricting.out","w",stdout);

    int n,k;cin>>n>>k;
    str s;cin>>s;


    vi dp(n+1);
    // dp[i] minimum # of districts that are gmajority or tied
    vi pref(n+1);
    for (int i=1;i<=n;++i){
        if (s[i-1]=='H') pref[i]=1+pref[i-1];
        else pref[i]=pref[i-1]-1;
    }

    rquery_st<pii> st;
    vpii aaa(n+1);
    st.init(n+1,aaa);
//    cout<<1<<endl;
    for (int i=1;i<=n;++i){
        int mx=i-1;
        int mn=max(0,i-k);
//        cout<<mn<<" "<<mx<<" "<<i<<endl;
        auto a=st.query(mn,mx);
//        cout<<a.f<<endl;
        if (pref[i]>a.s){
            dp[i]=a.f;
        }
        else dp[i]=a.f+1;

        st.set(i,{dp[i],pref[i]});
    }
//    for (int i:dp) cout<<i<<" ";cout<<endl;
//    for (int i:pref) cout<<i<<" ";cout<<endl;
    cout<<dp[n]<<endl;



    return 0;
}

