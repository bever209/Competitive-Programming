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

    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);


    int n,m,c;cin>>n>>m>>c;
    int mon[n];
    for (int i=0;i<n;++i){
        cin>>mon[i];
    }
    vector<vi> adj(n);
    for (int i=0;i<m;++i){
        int a,b;cin>>a>>b;--a;--b;
        adj[a].pb(b);
    }
    vector<vi> dp(n,vi(1010,-1));
    dp[0][0]=0;
    int ans=0;
    for (int i=1;i<1005;++i){
        for (int j=0;j<n;++j){
            if (dp[j][i-1]<0) continue;
            for (int k:adj[j]){
                dp[k][i]=max(dp[k][i],dp[j][i-1]+mon[k]);
            }
        }
    }
    for (int i=0;i<1010;++i){
        //cout<<dp[0][i]<<" "<<i<<endl;
        ans=max(ans,dp[0][i]-c*i*i);
    }
    cout<<ans<<endl;

    return 0;
}

