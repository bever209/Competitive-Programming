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
        int n,m;cin>>n>>m;
        ll arr[n][m];
        for (int i=0;i<n;++i) for (int j=0;j<m;++j) cin>>arr[i][j];
        ll ans=9e18;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                // keeping arr[i][j] the same
                vector<vi> dp(n,vi(m,9e18));
                for (int a=0;a<n;++a){
                    for (int b=0;b<m;++b){
                        ll to=arr[i][j]-i-j+a+b;
                        if (to<=arr[a][b]){
                            ll change=arr[a][b]-to;
                            if (a>0){
                                dp[a][b]=min(dp[a][b],dp[a-1][b]+change);

                            }
                            if (b>0){
                                dp[a][b]=min(dp[a][b],dp[a][b-1]+change);
                            }
                            if (a==0 && b==0) dp[a][b]=change;
                        }


                    }
                }
                ans=min(ans,dp[n-1][m-1]);
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}

