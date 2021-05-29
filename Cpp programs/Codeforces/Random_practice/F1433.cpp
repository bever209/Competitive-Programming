#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;
using ll = long long;
int mx = 2e9;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int dp[n + 1][m + 1][m][k];

    int arr[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            for (int c = 0; c < m; ++c)
            {
                for (int d = 0; d < k; ++d)
                {
                    dp[i][j][c][d] = -mx;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int c = 0; c < m; ++c)
            {
                for (int d = 0; d < k; ++d)
                {
                    if (dp[i][j][c][d] !=-mx)
                    {
                        int a = c;
                        int b = d;

                        int ni, nj;
                        if (j == m - 1)
                        {
                            ni = i + 1;
                            nj = 0;
                        }
                        else
                        {
                            ni = i;
                            nj = j + 1;
                        }
                        int r=(b+arr[i][j])%k;

                        if (ni != i)
                        {
                            dp[ni][nj][0][b] = max(dp[ni][nj][0][b], dp[i][j][a][b]);
                            if (c + 1 <= m / 2)
                            {
                                dp[ni][nj][0][r] = max(dp[ni][nj][0][r], dp[i][j][a][b] + arr[i][j]);
                            }
                        }
                        else
                        {
                            dp[ni][nj][a][b] = max(dp[ni][nj][a][b], dp[i][j][a][b]);

                            if (c + 1 <= m / 2)
                            {
                                dp[ni][nj][a + 1][r] = max(dp[ni][nj][a + 1][r], dp[i][j][a][b] + arr[i][j]);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    ans = max(ans, dp[n][0][0][0]);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}