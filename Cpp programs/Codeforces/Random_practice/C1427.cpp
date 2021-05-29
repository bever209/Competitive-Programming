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

    int r,n;
    cin>>r>>n;
    int t[n];int x[n];int y[n];
    int dp[n];
    for (int i=0;i<n;++i){
        dp[i]=0;
    }

    for (int i=0;i<n;++i){
        cin>>t[i]>>x[i]>>y[i];

        if (t[i]>=x[i]-1+y[i]-1){
            dp[i]=1;
        }
    }
    
    int ans=0;

    for (int i=0;i<n;++i){
        for (int j=i-1;j>=0 && j>=i-4*r-3;--j){
            int time=t[i]-t[j];
            int dist=abs(x[i]-x[j])+abs(y[i]-y[j]);

            if (dist<=time && dp[j]>0){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        //cout<<dp[i]<<" ";
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;

    return 0;
}