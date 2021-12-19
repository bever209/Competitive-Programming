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

template<class T> struct rquery_st {
    int n;                 // array size

    vector<T> tree;

    ll mx = 2e18;
    void init(int _n,vector<T> &arr){
        n=_n;tree.resize(4*_n+5,0);
        construct(0, 0, n - 1,arr);
    }
    void comb(int node) {
        tree[node] = __gcd(tree[node * 2 + 1], tree[2 * node + 2]);
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
            return 0;
        }
        if (l >= lq && r <= rq) {
            return tree[node];
        }

        int mid = (l + r) / 2;
        T s1 = query(node * 2 + 1, l, mid, lq, rq);
        T s2 = query(node * 2 + 2, mid + 1, r, lq, rq);
        return __gcd(s1, s2);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;
        cin>>n;
        ll arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        if (n==1){
            cout<<1<<endl;continue;
        }

        vector<ll> diff(n-1);
        for (int i=1;i<n;++i){
            diff[i-1]=abs(arr[i]-arr[i-1]);
        }
        rquery_st<ll> seg;
        int m=n-1;
        seg.init(m,diff);

        int ans=0;
        int left=0;
        for (int right=0;right<m;++right){
            while (left<=right && seg.query(left,right)==1){
                ++left;
            }
            ans=max(ans,right-left+1);
        }

        cout<<ans+1<<"\n";
    }


    return 0;
}

