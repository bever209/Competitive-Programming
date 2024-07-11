#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

// Should be good, but may not be
// If not good, just copy and paste from the usaco.guide DSU section

struct DSU {
    vi v;
    void init(int a){
        v=vi(a,-1);
    }

    int get(int x) {
        if (v[x] < 0) {
            return x;
        } else {
            v[x] = get(v[x]);
            return v[x];
        }
    }

    bool same_set(int x, int y) {
        return get(x) == get(y);
    }

    int size(int x) {
        return -v[get(x)];
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (v[x] >= v[y]) {
            swap(x, y);
        }
        v[x]=v[x]+ v[y];
        v[y] = x;
        return true;
    }
};