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

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        pair<ll,ll> arr[n];
        for (int i=0;i<n;++i) cin>>arr[i].f>>arr[i].s;
        vector<vi> dp(n,vi(4,1e18));
        for (int i=0;i<4;++i){
            dp[0][i]=arr[0].s*i;
        }
        for (int i=1;i<n;++i){
            for (int j=0;j<4;++j){
                for (int k=0;k<4;++k){
                    if (arr[i].f+j!=arr[i-1].f+k){
                        dp[i][j]=min(dp[i][j],arr[i].s*j+dp[i-1][k]);
                    }
                }
            }
        }
        ll ans=1e18;
        ll x=min(dp[n-1][0],dp[n-1][1]);
        ll y=min(dp[n-1][2],dp[n-1][3]);
        cout<<min(x,y)<<endl;
    }


    return 0;
}

