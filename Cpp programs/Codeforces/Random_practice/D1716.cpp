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
using vi = vector<ll>;
using vivi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;
const ll mod=998244353;

ll add(ll a,ll b){
    ll x=a+b;
    if (x>mod) x-=mod;
    return x;
}
ll sub(ll a,ll b){
    ll x=a-b;
    if (x<0) x+=mod;
    return x;
}
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vi dp(n + 1);
    ll ans = 0;

    dp[0] = 1;
    // after 0 moves
    vi m(k + 1000);
    vi a(n + 1);


    for (int i = k; i <= 660 + k; ++i) {
        for (int j = 0; j <= n; ++j) {
            int x = j % i;
            m[x] = add(m[x], dp[j]);
        }
        for (int j = n; j >= 0; --j) {
            int x = j % i;
            m[x] = sub(m[x], dp[j]);
            dp[j] = m[x];
            a[j] = add(a[j], dp[j]);
        }


    }
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";


    return 0;
}


