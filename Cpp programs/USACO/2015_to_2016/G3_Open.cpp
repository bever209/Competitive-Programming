#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

int main()
{
    int maxn=260;
    ios::sync_with_stdio(false);
    cin.tie(0);


    freopen("248.in","r",stdin);
    freopen("248.out","w",stdout);

    int n;
    cin>>n;
    vi arr(n);
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }

    int dp[maxn][maxn]; // ans for l to r, including l excluding r
    for (int i=0;i<maxn;++i){
        for (int j=0;j<maxn;++j){
            dp[i][j]=-1;
        }
    }
    int ans=0;
    for (int i=0;i<n;++i){
        dp[i][i+1]=arr[i];
        ans=max(ans,arr[i]);
    }

    for (int len=2;len<=n;++len){
        for (int i=0;i<=n-len;++i){
            int end=i+len;
            int strt=i;
            for (int j=strt;j<end;++j){
               // dp[strt][end]=max(dp[strt][end],dp[strt][j]);
               // dp[strt][end]=max(dp[strt][end],dp[j][end]);
                if (dp[strt][j]==dp[j][end]){
                    dp[strt][end]=max(dp[strt][end],dp[j][end]+1);
                }
            }
            ans=max(ans,dp[strt][end]);
        }
    }
    cout<<ans<<endl;

    return 0;
}