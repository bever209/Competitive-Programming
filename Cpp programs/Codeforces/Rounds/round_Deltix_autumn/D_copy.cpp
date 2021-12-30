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
struct DSU {
    vector<int> e;
    DSU(int N) { e = vi (N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    DSU dsu(n);
    int extra = 0;
    vector<pii> arr;
    for (int i = 0; i < d; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        arr.pb({a, b});
    }
    for (int i = 0; i < d; ++i) {
        int a, b;
        tie(a, b) = arr[i];
        if (!dsu.same_set(a, b)) {
            dsu.unite(a, b);
        } else {
            ++extra;
        }
        vector<bool> seen(n, false);
        vi sizes;
        for (int i = 0; i < n; ++i) {
            int n = dsu.get(i);
            if (!seen[n]) {
                sizes.pb(dsu.size(i));
                seen[n] = true;
            }
        }
        sort(sizes.rbegin(), sizes.rend());
        int ans = 0;
        for (int i = 0; i < extra + 1; ++i) {
            ans += sizes[i];
        }
        cout << ans - 1 << "\n";
    }


    return 0;
}

