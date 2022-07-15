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

    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vi x;
    vi pref;
    pref.pb(0);

    ll sub = 0;
    for (int i = n - 1; i >= k; --i) {
        ll a = arr[i] - sub;
        a=max(a,(ll)0);
        ll add = (a+k-1) / k;
        x.pb(add);
        pref.pb(pref.back() + add);

        sub += add * k;
        sub = sub - (pref.back() - pref[max(0, (int) pref.size() - k-1)]);
    }

    ll ans = pref.back();
    ll more = 0;
    ll s = 0;
//    cout<<"HI"<<endl;

    ll rsum = 0;
    for (int i = 0; i < k; ++i) {
        ll nn = (arr[i] - s + i) / (i + 1);
        more = max(more, nn);
        if (!x.empty()) {
            s = s + x.back() + rsum;
            rsum += x.back();

            x.pop_back();
        }
        else{
            s=s+rsum;
        }
    }
    cout << ans + more << endl;


    return 0;
}

