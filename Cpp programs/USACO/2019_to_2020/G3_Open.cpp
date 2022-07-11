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

    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
    vi primes;


    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, mod;
    cin >> n >> mod;

    vector<bool> comp(n + 1);
    for (int i = 2; i <= n; ++i) {
        if (!comp[i]) {
            primes.pb(i);
            for (int j = i; j <= n; j += i) comp[j] = true;
        }
    }

    vector<vi> dp(n + 1, vi(primes.size() +
                            1)); // sum of possible numbers if using the first n in array and use first k primes
    for (int i = 0; i <= n; ++i) dp[i][0] = 1;

    for (int i = 1; i <= primes.size(); ++i) {
        for (int j = 0; j <= n; ++j) {
            ll p = primes[i - 1];
            ll q = p;
            dp[j][i] = dp[j][i - 1];
            while (q <= j) {
                dp[j][i] = (dp[j][i] + dp[j - q][i - 1] * q) % mod;;
                q = (q * p) % mod;
            }
        }
    }
    cout << dp[n][primes.size()];


    return 0;
}

