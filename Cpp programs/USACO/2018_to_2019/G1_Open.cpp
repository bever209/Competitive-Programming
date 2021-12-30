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
using str=string;

const ll inf=2*1e18;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);

    int n,k;cin>>n>>k;
    int arr[n+1];arr[0]=0;
    for (int i=0;i<n;++i){
        cin>>arr[i+1];
    }
    vector<vi> dp(n+1,vi(k+1,1e9));
    for (int i=0;i<=k;++i)dp[0][i]=0;
    int mx=0;
    int sum=0;
    for (int i=1;i<=n;++i){
        sum+=arr[i];mx=max(mx,arr[i]);
        dp[i][0]=mx*(i)-sum;
    }


    for (int i=1;i<=n;++i){
        for (int j=1;j<=k;++j){
            mx=0;sum=0;
            for (int l=i;l>=0;--l){
                dp[i][j]=min(dp[i][j],dp[l][j-1]+mx*(i-l)-sum);
                mx=max(mx,arr[l]);
                sum+=arr[l];
            }
        }
    }
    /*for (int i=0;i<=n;++i){
        for (int j=0;j<=k;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[n][k]<<endl;

    return 0;
}

