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


    ios::sync_with_stdio(false);
    cin.tie(0);


    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);

    int n,m;
    cin>>n>>m; // h then g
    vector<pii> h;
    for (int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        h.pb({a,b});
    }
    vector<pii> g;
    for (int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        g.pb({a,b});
    }

    ll dp[1010][1010][2]; // h then g
    for (int i=0;i<1010;++i){
        for (int j=0;j<1010;++j){
            for (int k=0;k<2;++k) {
                dp[i][j][k] = (ll) 1e18;
            }
        }
    }
    dp[1][0][0]=0;
    for (int i=2;i<=n;++i){
        dp[i][0][0]=dp[i-1][0][0];
        ll a=pow(h[i-1].f-h[i-2].f,2);
        ll b=pow(h[i-1].s-h[i-2].s,2);
        dp[i][0][0]+=a+b;
    }
    dp[1][1][1]=pow(h[0].f-g[0].f,2)+pow(h[0].s-g[0].s,2);

    for (int i=2;i<=m;++i){
        dp[1][i][1]=dp[1][i-1][1];
        ll a=pow(g[i-1].f-g[i-2].f,2);
        ll b=pow(g[i-1].s-g[i-2].s,2);
        dp[1][i][1]+=a+b;
    }

    for (int i=2;i<=n;++i){ // h then g
        for (int j=1;j<=m;++j){
            ll a=dp[i-1][j][0]+pow(h[i-1].f-h[i-2].f,2)+pow(h[i-1].s-h[i-2].s,2);
            ll b=dp[i-1][j][1]+pow(h[i-1].f-g[j-1].f,2)+pow(h[i-1].s-g[j-1].s,2);
            dp[i][j][0]=min(a,b);

            a=dp[i][j-1][0]+pow(h[i-1].f-g[j-1].f,2)+pow(h[i-1].s-g[j-1].s,2);
            b=dp[i][j-1][1]+pow(g[j-1].f-g[j-2].f,2)+pow(g[j-1].s-g[j-2].s,2);
            dp[i][j][1]=min(a,b);


        }
    }
    cout<<dp[n][m][0]<<endl;

    return 0;
}