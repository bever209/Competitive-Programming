#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    n = n % 30;

    int ans = -1;
    for (int i = 0; i <= 2; ++i)
    {
        int d = i;
        for (int j = 1; j <= n; ++j)
        {
            if (j % 2 == 1)
            {
                if (d == 1 || d == 0)
                {
                    d = 1 - d;
                }
            }
            else
            {
                if (d == 2 || d == 1)
                {
                    d = 3 - d;
                }
            }
        }
        
        if (d == x)
        {
            ans = i;
            break;
        }
    }
    cout << ans;

    return 0;
}