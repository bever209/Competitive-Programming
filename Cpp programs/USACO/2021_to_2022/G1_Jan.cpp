#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;
const ll mod=1e9+7;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    if (n%2==0){
        vector<vi> dp(n+1,vi(1005));// using first i, can the rolling sum be j ->dp[i][j]
        dp[0][0]=1;
        for (int i=1;i<=n;++i){
            for (int j=0;j<=1000;++j){
                // basically so
                // we are trying to form j right
                // so say we are looking at dp[i-1][x], then we need that y-x=j ->y=x+j and 0<=y<=arr[i-1]
                // so which x work? well y-j=x so namely we have arr[i-1]-j down to 0


                // poc
                for (int k=0;k<=arr[i-1]-j;++k){
                    dp[i][j]=(dp[i][j]+dp[i-1][k]);
                    if (dp[i][j]>mod) dp[i][j]-=mod;
                }
            }
        }
        cout<<dp[n][0];
    }
    else {
        ll ans = 0;
        int mn = 1e9;
        for (int i:arr) mn = min(mn, i);
        vector<vi> dp(n + 1, vi(1005));// using first i, can the rolling sum be j ->dp[i][j]
        vector<vi> pref(n+1,vi(1005));
        while (mn>=0) {

            dp[0][0] = 1;
            pref[0][0]=1;
            for (int i=1;i<1005;++i){
                pref[0][i]=pref[0][i-1]+dp[0][i];
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j <= 1000; ++j) {
                    dp[i][j]=0;
                    // basically so
                    // we are trying to form j right
                    // so say we are looking at dp[i-1][x], then we need that y-x=j ->y=x+j and 0<=y<=arr[i-1]
                    // so which x work? well y-j=x so namely we have arr[i-1]-j down to 0

                    if (arr[i-1]-j>=0){
                        dp[i][j]=(pref[i-1][arr[i-1]-j]);
                    }
                }
                pref[i][0]=dp[i][0];
                for (int j=1;j<1005;++j){
                    pref[i][j]=(pref[i][j-1]+dp[i][j]);
                    if (pref[i][j]>mod) pref[i][j]-=mod;
                }

            }
            for (int i=0;i<n;++i) arr[i]--;
            --mn;
            ans=(ans+dp[n][0]);
            if (ans>mod) ans-=mod;
        }
        cout<<ans;
    }



    return 0;
}

