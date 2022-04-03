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
const int N=1e6+1;
template<class T> struct lazyst {
    int n;
    vector<T> min_tree, max_tree, lazy;
    int mx = 1e6 + 5;

    void init(int _n, vector<T> &arr) { // arr is array of values, send it in
        n = _n;
        min_tree.resize(4 * N + 5);
        lazy.resize(4 * N + 5);
        max_tree.resize(4 * N + 5);
        //construct(0, 0, n - 1, arr); no need to call as all elements are 0
    }

    void push(int node, int l, int r) {
        if (lazy[node]==0) return;
        max_tree[node] += lazy[node];
        min_tree[node] += lazy[node];
        if (l != r) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }

        lazy[node] = 0;
    }

    void comb(int node) {
        max_tree[node] = max(max_tree[node * 2 + 1], max_tree[2 * node + 2]);
        min_tree[node] = min(min_tree[node * 2 + 1], min_tree[2 * node + 2]);
    }

    void construct(int node, int l, int r, vector<T> &arr) {
        if (l == r) {
            min_tree[node] = arr[l];
            max_tree[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            construct(node * 2 + 1, l, mid, arr);
            construct(node * 2 + 2, mid + 1, r, arr);
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

    T query_max(int node, int l, int r, int lq, int rq) {
        push(node, l, r);
        if (l > rq || r < lq) {
            return 0;
        }
        if (l >= lq && r <= rq) {
            return max_tree[node];
        }

        int mid = (l + r) / 2;

        return max(query_max(node * 2 + 1, l, mid, lq, rq), query_max(node * 2 + 2, mid + 1, r, lq, rq));
    }

    T query_max(int lq, int rq) {
        return query_max(0, 0, n - 1, lq, rq);
    }

    T query_min(int node, int l, int r, int lq, int rq) {
        push(node, l, r);
        if (l > rq || r < lq) {
            return mx;
        }
        if (l >= lq && r <= rq) {
            return min_tree[node];
        }

        int mid = (l + r) / 2;

        return min(query_min(node * 2 + 1, l, mid, lq, rq), query_min(node * 2 + 2, mid + 1, r, lq, rq));
    }

    T query_min(int lq, int rq) {
        return query_min(0, 0, n - 1, lq, rq);
    }

};


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    str s;cin>>s;
    vi qq(n);
    lazyst<int> st;
    st.init(n,qq);
    string fin;int ind=0;
    int end=0;
    for (int i=0;i<n;++i){
        fin.pb('a');
        char x=s.at(i);
        if (x=='R'){
            ++ind;
        }
        else if (x=='L'){
            --ind;ind=max(0,ind);
        }
        else{
            char q=fin.at(ind);
            fin[ind]=x;
            if (q==')'){
                st.add(1,ind,n-1);++end;

            }
            else if (q=='('){
                st.add(-1,ind,n-1); --end;
            }

            if (x=='('){
                st.add(1,ind,n-1);++end;
            }
            else if (x==')'){
                st.add(-1,ind,n-1);--end;
            }
        }

        int mx=st.query_max(0,n-1);
        int mn=st.query_min(0,n-1);
//        cout<<mx<<" "<<mn<<" "<<end<<endl;
        if (end==0 && mn>=0){
            cout<<mx<<" ";
        }
        else{
            cout<<-1<<" ";
        }

    }


    return 0;
}

