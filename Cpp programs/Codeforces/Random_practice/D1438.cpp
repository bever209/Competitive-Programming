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

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int x = 0;
    for (int i:arr) x ^= i;
    if (n % 2 == 0) {
        if (x != 0) {
            cout << "NO";
            return 0;
        }
        cout << "YES\n";
        vector<pair<int, pii>> ans;
        for (int i = 2; i < n; i += 2) {
            ans.pb({i, {i - 1, i - 2}});
        }
        for (int i = n - 4; i-2 >= 0; i -= 2) {
            ans.pb({i, {i - 1, i - 2}});
        }
        cout << ans.size() << endl;
        for (auto i:ans) cout << i.f + 1 << " " << i.s.f + 1 << " " << i.s.s + 1 << endl;


    } else {

        cout << "YES\n";
        vector<pair<int, pii>> ans;
        for (int i = 2; i < n; i += 2) {
            ans.pb({i, {i - 1, i - 2}});
        }
        for (int i = n - 3; i-2 >= 0; i -= 2) {
            ans.pb({i, {i - 1, i - 2}});
        }
        cout << ans.size() << endl;
        for (auto i:ans) cout << i.f + 1 << " " << i.s.f + 1 << " " << i.s.s + 1 << endl;
    }


    return 0;
}

