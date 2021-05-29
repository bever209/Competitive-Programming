#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;
using ll = long long;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int v = 0; v < t; ++v)
    {
        int n, m;
        cin >> n >> m;
        ll arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        ll x[m];
        for (int i = 0; i < m; ++i)
        {
            cin >> x[i];
        }

        ll pref[n];
        ll sum = 0;
        ll maxx = (ll)-2e9;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            pref[i] = sum;
            maxx = max((ll)sum, (ll)maxx);
        }
        vector<ll> bsearch;
        vector<int> inds;
        bsearch.pb(pref[0]);
        inds.pb(0);
        for (int i = 1; i < n; ++i)
        {
            if (bsearch.at(bsearch.size() - 1) < pref[i])
            {
                bsearch.pb(pref[i]);
                inds.pb(i);
            }
        }

        for (int s = 0; s < m; ++s)
        {
            ll num = x[s];
            if (num > maxx && sum <= 0)
            {
                cout << "-1 ";
                continue;
            }
            ll times = 0, ans = 0;
            if (maxx < num)
            {
                times = ((num - maxx + sum - 1) / sum);
                num = num - times * sum;
                ans += times * n;
            }

            int left = 0;
            int right = bsearch.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (bsearch.at(mid) >= num)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            ans += inds.at(left);

            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}