#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 0-indexed

// node update range query

const int N = 2e5 + 5; // limit for array size

template<class T> struct rquery_st {
    int n;                 // array size

    vector<T> tree;

    int mx = 2e9;
    void init(int _n,vector<T> &arr){
        n=_n;tree.resize(4*N+5);
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
        return (s1+ s2);
    }

    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};