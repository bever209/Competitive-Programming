#include <bits/stdc++.h>
 // fix
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll=pair<ll,ll>;
using vi = vector<int>;
using vivi=vector<vi>;
using vb=vector<bool>;
using vll=vector<ll>;
using vpii=vector<pii>;
using str = string;

const ll inf = 2 * 1e18;
int d;
const int N = 2e5 + 5; // limit for array size
struct node{
    int prod=0;
    int f=0;
    int active=0;
};
template<class T> struct lazy_st {
    int n;
    vector<T> tree;
    vi lazy; // 1 for adding f(i), -1 for subtracting, 0 for doing nothing
//    ll mx=(ll) 1e18;

    void init(int _n,vector<T> &arr){ // arr is array of values, send it in
        n=_n;tree.resize(4*N+5);lazy.resize(4*N+5);
    }
    void push(int nn, int l, int r) {
        if (lazy[nn]==0) return;
        tree[nn].prod+=tree[nn].f*lazy[nn];
        tree[nn].f+=lazy[nn]*tree[nn].active;
        if (l != r) {
            lazy[2 * nn + 1] += lazy[nn];
            lazy[2 * nn + 2] += lazy[nn];
        }

        lazy[nn] = 0;
    }

    void comb(int nn) {
        if (!tree[nn*2+1].active && !tree[2*nn+2].active){
            node x;tree[nn]=x;
        }
        else if (!tree[nn*2+1].active){
            tree[nn]=tree[nn*2+2];
        }
        else if (!tree[nn*2+2].active){
            tree[nn]=tree[nn*2+1];
        }
        else{
            tree[nn].f = (tree[nn * 2 + 1].f+ tree[2 * nn + 2].f);
            tree[nn].prod=(tree[nn * 2 + 1].prod+ tree[2 * nn + 2].prod);
            tree[nn].active=(tree[nn * 2 + 1].active+ tree[2 * nn + 2].active);
        }


    }

    void add(int nn, int l, int r, int val, int lq, int rq) {
        push(nn, l, r);
        if (l > rq || r < lq) {
            return;
        }
        if (l >= lq && r <= rq) {
            lazy[nn] += val;
            push(nn, l, r);
            return;
        }
        int mid = (l + r) / 2;

        add(nn * 2 + 1, l, mid, val, lq, rq);
        add(nn * 2 + 2, mid + 1, r, val, lq, rq);
        comb(nn);
    }

    void add(int val, int lq, int rq) {
        add(0, 0, n - 1, val, lq, rq);
    }
    void set(int nn, int l, int r, int val, int q){
        push(nn, l, r);
        if (l > q || r < q) {
            return;
        }
        if (l==q && r==q) {
            if (val==0){
                tree[nn].active=0;
                add(-1,q+1,min((int)2e5+1,q+d));
            }
            else{
//                cout<<q<<" q"<<endl;
//                cout<<nn<<" "<<q<<endl;
                tree[nn].active=1;
                add(1,q+1,min((int)2e5+1,q+d));

            }
            return;
        }
        int mid=(l+r)/2;
        set(2*nn+1,l,mid,val,q);
        set(2*nn+2,mid+1,r,val,q);

        comb(nn);
    }
    void set(int x,int val){
        set(0,0,n-1,val,x);
    }


    node query(int nn, int l, int r, int lq, int rq) {
        push(nn, l, r);
        if (l > rq || r < lq) {
            node x;
            return x;

        }
        if (l >= lq && r <= rq) {
            return tree[nn];
        }

        int mid = (l + r) / 2;

        auto a=query(nn * 2 + 1, l, mid, lq, rq);
        auto b=query(nn * 2 + 2, mid + 1, r, lq, rq);
        node c;
        c.active=a.active+b.active;
        c.f=a.f+b.f;
        c.prod=a.prod+b.prod;
        return c;
    }

    node query(int lq, int rq) {
        return query(0, 0, n - 1, lq, rq);
    }
};

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;cin>>q>>d;
    lazy_st<node> st;
    int len=10;
    vector<node> xx(len);
    st.init(len,xx);
    set<int> s; // need to keep track of how many are on from i to j
    while (q--){
        int a;cin>>a;
        if (s.count(a)){
            s.erase(s.find(a));
            st.set(a,0);
        }
        else{
//            cout<<a<<" "<<q<<endl;
            s.insert(a);
            st.set(a,1);
        }
        for (int i=0;i<=40;++i) cout<<st.tree[i].prod<<" ";cout<<endl;
        for (int i=0;i<=40;++i) cout<<st.tree[i].f<<" ";cout<<endl;
        cout<<st.query(0,2e5+4).prod<<endl;

    }


    return 0;
}

