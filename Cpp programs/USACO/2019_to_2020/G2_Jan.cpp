#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<ll>;
using str=string;

const ll inf=2*1e18;
//count[2e6+x]++;


int main() {
    int count [2000000+6];


    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i=0;i<2e6+6;++i){
        count[i]=0;
    }

    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<vi> dp(n + 1, vi(n + 1));

    for (int i = n - 1; i >= 0; --i) {

        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = dp[i][j] + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            ll neg = -(arr[i] + arr[j]);
            int ind = 1e6 + neg;
            if (ind >= 0 && ind < 2e6+6) {
                dp[i][j] += count[ind];
            }
            count[1000000 + arr[j]]++;
        }
        for (int j=i+1;j<n;++j){
            count[1000000 + arr[j]]--;
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        cout << dp[a][b] << endl;
    }
    return 0;
}

