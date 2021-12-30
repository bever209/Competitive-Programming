#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
#define int ll
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k; // k is what sum should be
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr + n);
        int mn = arr[0];
        int ans = 3 * 1e15;
        vi x;
        for (int i = 1; i < n; ++i) x.pb(arr[i]);

        vi pref(x.size());

        for (int i = 0; i < x.size(); ++i) {
            if (i == 0) pref[i] = x[i];
            else
                pref[i] = pref[i - 1] + x[i];
        }
        int b=pref.size();
        for (int i = -1; i < b; ++i) {
            int num = b - i - 1; // how many we are zapping
            int sum = 0;
            if (i >= 0) sum = pref[i];
            int a = (k - sum) / (num + 1);
            while (a*(num+1)+sum<=k) ++a;
            --a;
            int reduce = max((ll) 0, mn - a);
//            cout<<num<<" "<<k<<" "<<sum<<" "<<reduce<<endl;
            ans = min(ans, num + reduce);

        }
        cout << ans << endl;
    }


    return 0;
}

