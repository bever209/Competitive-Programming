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

    ll n, k;
    cin >> n >> k;
    auto xx = k;
    if (k < (n * (n + 1)) / 2) {
        cout << -1;
        return 0;
    }
    vi x(n);
    for (int i = 0; i < n; ++i) x[i] = i + 1;
    for (int i = 0; i < n; ++i) x[i] = max(x[i], x[n - 1 - i]);
    ll sum = 0;
    for (auto i:x) sum += i;
    for (int i = 0; i < n; ++i) x[i] = i + 1;

    if (k >= sum) {
        cout << sum << endl;
        for (auto i:x) cout << i << " ";
        cout << endl;
        reverse(x.begin(), x.end());
        for (auto i:x) cout << i << " ";
        cout << endl;
        return 0;
    }


    vi f(n);
    vi s(n);
    for (int i = 0; i < n; ++i) f[i] = s[i] = i + 1;
    for (auto i:f) k -= i;

    int ind = 0;
    while (k > 0) {
//        cout<<k<<endl;
        int small = ind ;
        int large = n - 1-ind;
        ll red = large - small;
        if (k >= red) {
            k -= red;
            swap(f[small], f[large]);
        } else {
            int less = large - k;
            swap(f[less], f[large]);

            k = 0;
        }
//        for (int i:f) cout<<i<<" ";cout<<endl;
        ++ind;
    }
    cout << xx << endl;
    for (auto i:f) cout << i << " ";
    cout << endl;
    for (int i:s) cout << i << " ";
    cout << endl;


    return 0;
}

