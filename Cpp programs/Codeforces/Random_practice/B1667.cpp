#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;
#define endl "\n"
const int N = 5e5 + 5; // limit for array size

template<class T> struct rquery_st {
    int n;                 // array size

    vector<T> tree;

    T mx = 1e9;
    void init(int _n,vector<T> &arr){
        n=_n;tree.resize(4*n+5);
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
            return -mx;
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


    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vi pref(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + arr[i];
        map < pii, int > ord;
        map < int, int > c;
        vi xx(n);
        for (int i = 0; i < n; ++i) xx[i] = pref[i];
        sort(xx.begin(), xx.end());
        for (int i = 0; i < pref.size(); ++i) c[xx[i]]++, ord[{xx[i], c[xx[i]]}] = i; // first number, then occurrence #

        vi arord(n);
        map < int, int > d;
        for (auto i:c) d.insert(i);
        for (int i = 0; i < n; ++i) arord[i] = ord[{pref[i], d[pref[i]] - c[pref[i]] + 1}], --c[pref[i]];

        map<int,int> down;
        set<int> s;
        for (int i:xx) s.insert(i);

        int tot=0;
        for (int i:s){
            down[i]=tot;
            tot+=d[i];
        }

        vi dp(n + 1, -1e9);
        rquery_st<ll> st;
        dp[0] = 0;
        st.init(n + 1, dp);
        for (int i = 1; i <= n; ++i) {

            if (arr[i - 1] > 0) dp[i] = dp[i - 1] + 1;
            else if (arr[i - 1] < 0) dp[i] = dp[i - 1] - 1;
            else dp[i] = dp[i - 1];

            int loc = arord[i - 1];
            int x = st.query(1, down[pref[i-1]]);
//            cout<<loc<<" "<<x<<endl;



            dp[i] = max(dp[i], x + i);
            if (pref[i - 1] > 0) dp[i] = max(dp[i], i);
            st.set(loc + 1, dp[i] - i);
        }

//        for (int i:pref) cout<<i<<" ";cout<<endl;
//        for (int i:arord) cout<<i<<" ";cout<<endl;
//        for (auto i:down) cout<<i.s<<" ";cout<<endl;
//        for (int i:dp) cout<<i<<" ";cout<<endl;
        cout << dp[n] << endl;

    }


    return 0;

}
