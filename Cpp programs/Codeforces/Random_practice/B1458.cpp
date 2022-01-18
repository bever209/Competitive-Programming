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

    int n;cin>>n;
    pair<int,int> arr[n];
    for (int i=0;i<n;++i) cin>>arr[i].f>>arr[i].s;

    double sum=0;
    for (int i=0;i<n;++i) sum+=arr[i].s;

    vector<vector<vi>> dp(101,vector<vi>(101,vi(101*100,-1)));


    dp[0][0][0]=0;

    for (int i=1;i<=n;++i) {
        for (int k = 0; k <= i; ++k) {
            for (int q = 0; q < 101 * 100; ++q) {
                dp[k][i][q] = max(dp[k][i][q], dp[k][i - 1][q]);
                if (q - arr[i - 1].f >= 0 && k>0 && dp[k - 1][i - 1][q - arr[i - 1].f]>=0)
                    dp[k][i][q] = max(dp[k][i][q], dp[k - 1][i - 1][q - arr[i - 1].f] + arr[i - 1].s );
            }
        }
    }

    for (int k=1;k<=n;++k) {double ans = 0;
        for (int i = 0; i <= n; ++i) {

            for (int q = 0; q < 101 * 100; ++q) {
                if (dp[k][i][q]>=0)
                ans = max(ans, min((double)q, 0.5*(dp[k][i][q] + sum)));
            }
        }
        cout << fixed<<setprecision(14)<<ans << endl;
    }




    return 0;
}

