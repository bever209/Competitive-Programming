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
    /*const int maxn = 85;
    ll C[maxn + 1][maxn + 1];
    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }*/

    int x;
    cin >> x;
    int maxn = 85;

    ll dp[maxn][maxn];
    for (int i = 0; i < maxn; ++i)
    {
        for (int j = 0; j < maxn; ++j)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < maxn; ++i)
    { // first number of guardians, second number of elder
        dp[i][0] = 1;
    }
    for (int i = 0; i < maxn; ++i)
    {
        for (int j = 0; j < maxn - 1; ++j)
        {
            if (dp[j][i] == -1)
            {
                if (j == 0)
                {
                    dp[j][i] = dp[j + 1][i - 1];
                }
                else
                {
                    if (j>1){
                    dp[j][i] = dp[j - 1][i] + dp[j + 1][i - 1];}
                    else{
                        dp[j][i] = dp[j + 1][i - 1];
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout<<"\n";
    }*/

    for (int i = 0; i < x; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << endl;
    }

    return 0;
}