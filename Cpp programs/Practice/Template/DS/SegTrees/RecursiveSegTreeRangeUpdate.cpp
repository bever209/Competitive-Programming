// For adding to a range but querying only 1 value
//  IDK IF IT WORKS, TEST USING CSES OR CF OR SMTH
#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 0-indexed
//  node query and range update

const int N = 2e5 + 5; // limit for array size

template<class T> struct rupdate_st {
    int n;                 // array size
    vector<T> tree,ops;
    int mx = 2e9;

    void init(int _n,vector<T> &arr){
        n=_n;tree.resize(4*N+5);ops.resize(4*N+5);
        construct(0, 0, n - 1,arr);
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

    void add(int node, int l, int r, T val, int lq, int rq) {
        if (l > rq || r < lq) {
            return;
        }
        if (l >= lq && r <= rq) {
            ops[node] += val;
            return;
        }
        int mid = (l + r) / 2;
        add(node * 2 + 1, l, mid, val, lq, rq);
        add(node * 2 + 2, mid + 1, r, val, lq, rq);
    }

    void add(T val, int lq, int rq) {
        add(0, 0, n - 1, val, lq, rq);
    }

    T query(int node, int l, int r, int x) {
        if (l > x || r < x) {
            return 0;
        }
        if (l == r && l == x) {
            return tree[node] + ops[node];
        }

        int mid = (l + r) / 2;
        T z = 0;
        if (mid >= x) {
            z = query(node * 2 + 1, l, mid, x);
        } else {
            z = query(node * 2 + 2, mid + 1, r, x);
        }
        return z + ops[node];
    }

    T query(int x) {
        return query(0, 0, n - 1, x);
    }
};