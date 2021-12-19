#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);


    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        int k;cin>>k;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        vector<vi> dp(n+1,vi(n+1,0));
        for (int i=1;i<=n;++i){
            for (int j=1;j<=i;++j){
                dp[i][j]=dp[i-1][j];
                if (arr[i-1]==j){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
                else{
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
                }
            }
        }
        int ans=-1;
        for (int i=n;i>=0;--i){
            if (dp[n][i]>=k){
                ans=n-i;break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

