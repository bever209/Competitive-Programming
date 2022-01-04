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
        int low = 0;
        int high = 1e9;

        while (low < high) {
            vi x;
            for (int i:arr) x.pb(i);
            int mid = (low + 1 + high) / 2;
            for (int i = n - 1; i >= 2; --i) {
                int mx = min(arr[i] / 3, (x[i] - mid) / 3);
                mx=max(mx,0);
                x[i] -= 3 * mx;
                x[i - 1] += mx;
                x[i - 2] += 2 * mx;
            }
            bool check = true;
            for (int i:x) {
                if (i < mid) check = false;
               //cout << i << " ";
            }
            //cout << endl;
            if (check) low = mid;
            else high = mid - 1;
        }
        cout << low << endl;
    }


    return 0;
}

