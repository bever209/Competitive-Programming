#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int mx = 1e9 + 10;
    for (int v = 0; v < t; ++v)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int dp[n][500];
        for (int i=0;i<n;++i){
            dp[i][0]=mx;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < 500; ++j)
            {
                dp[i][j] = mx;
                if (i<=j-1)
                {
                    if (i!=0)
                    {
                        dp[i][j] = dp[i][j - 1];
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(j - arr[i]));

                    }
                    else
                    {
                        if (j!=0){
                            dp[i][j]=dp[i][j-1];
                        }
                        dp[i][j] = min(dp[i][j],abs(j - arr[i]));
                    }
                }
            }
        }
        int ans = mx;
        for (int i = 0; i < 500; ++i)
        {
            ans = min(ans, dp[n - 1][i]);
        }
        cout << ans << endl;
    }

    return 0;
}