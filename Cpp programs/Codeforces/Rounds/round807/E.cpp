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
const int N = 2e5 + 30; // limit for array size

template<class T> struct lazy_st {
    int n;
    vector<T> tree; // always 0 or 1
    vector<bool> lazy; // whether to swap or not
    ll mx=(ll) 1e18;

    void init(int _n,vector<T> &arr){ // arr is array of values, send it in
        n=_n;tree.resize(4*N+5);lazy.resize(4*N+5);
        construct(0, 0, n - 1,arr);
    }
    void push(int node, int l, int r) {
        if (!lazy[node]) return;
        tree[node]=(r-l+1)-tree[node];
        if (l != r) {
            lazy[2 * node + 1] = lazy[node];
            lazy[2 * node + 2] = lazy[node];
        }

        lazy[node] = false;
    }

    void comb(int node) {
        tree[node] = (tree[node * 2 + 1]+ tree[2 * node + 2]);
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


    void upd(int node, int l, int r, int lq, int rq) {
        push(node, l, r);
        if (l > rq || r < lq) {
            return;
        }
        if (l >= lq && r <= rq) {
            lazy[node] =true;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;

        upd(node * 2 + 1, l, mid, lq, rq);
        upd(node * 2 + 2, mid + 1, r,  lq, rq);
        comb(node);
    }

    void upd(int lq, int rq) {
        if (rq<lq) return;
        upd(0, 0, n - 1, lq, rq);
    }

    T query(int node, int l, int r, int lq, int rq) {
        push(node, l, r);
        if (l > rq || r < lq) {
            return 0;
        }
        if (l >= lq && r <= rq) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        return (query(node * 2 + 1, l, mid, lq, rq)+ query(node * 2 + 2, mid + 1, r, lq, rq));
    }

    T query(int lq, int rq) {
        return query(0, 0, n - 1, lq, rq);
    }

    int next_1(int start){
        int low=start;
        int high=2e5+20;

        while (low<high){
            int mid=(low+high)/2;
            if (query(start,mid)>0){
                high=mid;
            }
            else low=mid+1;
        }
        return low;
    }
    int next_0(int start){
        int low=start;
        int high=2e5+20;

        while (low<high){
            int mid=(low+high)/2;
            if (query(start,mid)<(mid-start+1)){
                high=mid;
            }
            else low=mid+1;
        }
        return low;
    }
    void add(int x){
        int num=next_0(x);
        upd(x,num);

    }
    void rem(int x){
        int num=next_1(x);
        upd(x,num);
    }
    int ans(){
        int low=0;
        int high=2e5+20;
        while (low<high){
            int mid=(low+high+1)/2;
            if (query(mid,2e5+23)>0){
                low=mid;
            }
            else high=mid-1;
        }
        return low;
    }
};

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);


    int n,q;cin>>n>>q;
    vi a(n);
    for (int i=0;i<n;++i){
        cin>>a[i];
    }

    lazy_st<int> st;
    vi x(2e5+30);
    st.init(2e5+30,x);

    for (int i:a){
        st.add(i);
    }
    while (q--){
        int c,d;cin>>c>>d;
        --c;
        st.rem(a[c]);
        st.add(d);
        cout<<st.ans()<<endl;
        a[c]=d;
    }


    return 0;
}

