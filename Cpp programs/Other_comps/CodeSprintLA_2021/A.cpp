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
    for (int v = 0; v < t; ++v)
    {
        int n;
        cin >> n;

        int ans = 0;
        for (int i = 1; i <= 10; ++i)
        {
            if (i * 7 % 10 == n % 10)
            {
                ans = i;
                break;
            }
        }

        if (ans*7<=n){
            cout<<ans<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }

       
    }

    return 0;
}