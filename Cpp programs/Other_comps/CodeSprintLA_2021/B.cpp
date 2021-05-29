#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;
using ll = long long;
ll mx = (ll)1e20;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll x[n];
    ll y[n];
    for (int i = 0; i < n; ++i)
    {
        x[i] = 0;
        y[i] = 0;
        cin >> x[i];
        cin >> y[i];
    }
    bool has[n];
    for (int i=0;i<n;++i){
        has[i]=false;
    }
    has[0] = true;
    ll ans = 0;
    for (int i = 1; i < n; ++i)
    {
        int ind = 0;
        ll a = mx;
        for (int j = 1; j < n; ++j)
        {

            if (!has[j])
            {
                for (int k = 0; k < n; ++k)
                {
                    if (has[k] && j!=k)
                    {
                        ll b = abs(y[j] - y[k])+abs(x[j]-x[k]);
                        b=b*2;
                        if (b < a)
                        {
                            a=b;
                            ind = j;
                        }
                    }
                }
            }
        }
        ans += a;
        has[ind]=true;
    }
    cout << ans << endl;

    return 0;
}