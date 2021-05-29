#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int s = 0;
        for (int j = i; j < n; ++j)
        {
            s += arr[j];
            int len = j - i + 1;
            if (s % len == 0)
            {
                int avg = s / len;
                for (int k = i; k <= j; ++k)
                {
                    if (arr[k] == avg)
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}