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
using vivi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;

    while (tc--) {
        int n;Tree<int> t;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        bool check = false;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                t.insert(a[i]);
            } else {
                if (!s.count(a[i]))
                    t.insert(a[i]);
                int x = t.order_of_key(a[i]);
                int y = t.order_of_key(a[i - 1]);
                if (abs(x - y) > 1) {
                    check = true;
                }
            }
            s.insert(a[i]);
        }
        if (check) {
            cout << "no" << endl;
        } else {
            cout << "YES" << endl;
        }

    }


    return 0;
}


