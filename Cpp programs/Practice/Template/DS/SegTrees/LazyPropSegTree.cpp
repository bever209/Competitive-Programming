#include <bits/stdc++.h>
using namespace std;
using ll = long long; // 0-indexed
//  range query and range update

const int N = 2e5 + 5; // limit for array size

template<class T> struct lazy_st {
    int n;
    vector<T> tree,lazy;
    ll mx=(ll) 1e18;

    void init(int _n,vector<T> &arr){ // arr is array of values, send it in
        n=_n;tree.resize(4*N+5);lazy.resize(4*N+5);
        construct(0, 0, n - 1,arr);
    }
    void push(int node, int l, int r) {
        if (lazy[node]==0) return;
        tree[node] += lazy[node];
        if (l != r) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }

        lazy[node] = 0;
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

    T query(int node, int l, int r, int lq, int rq) {
        push(node, l, r);
        if (l > rq || r < lq) {
            return mx;
        }
        if (l >= lq && r <= rq) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        return min(query(node * 2 + 1, l, mid, lq, rq), query(node * 2 + 2, mid + 1, r, lq, rq));
    }

    T query(int lq, int rq) {
        return query(0, 0, n - 1, lq, rq);
    }
};