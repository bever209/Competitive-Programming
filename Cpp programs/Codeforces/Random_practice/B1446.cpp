#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    int dp[n + 1][m + 1];
    // NEED TO INITIALLY SET VALUES TO 0
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a.at(i - 1) == b.at(j - 1))
            {
                dp[i][j] = max(2, dp[i - 1][j - 1] + 2);
            }
            else
            {
                dp[i][j] = max(-2, max(dp[i - 1][j], dp[i][j - 1]) - 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    /* for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}