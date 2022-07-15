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

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        vi ans(n, 1);
        vector<bool> has0(n);
        for (int i = 0; i < n; ++i) {
            int x = arr[i];
            x = n - x; // number of 0s

            if (x == n) {
                has0[i] = true;
                continue;
            }
            if (x == 0) continue;

            if (has0[i]) {
                if (x == i) continue; // less than or equal to i 0s
                int nn = n - (x - i);
                // index of the ith 0
                has0[nn] = true;
            } else {
                // there must be a 0 that goes to this
                int aa = n - x;
                has0[aa] = true;
            }
        }
        for (int i = 0; i < n; ++i) if (has0[i]) ans[i] = 0;

        for (int i:ans) cout << i << " ";
        cout << "\n";
    }


    return 0;
}

