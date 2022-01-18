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
const int mod=1e9+7;
int main() {
#define int ll

    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vi> dp(2e5+5,vi(10));

    for (int i=0;i<=8;++i) dp[1][i]=1;
    dp[1][9]=2; // length after 1 move
    for (int i=2;i<dp.size();++i){
        for (int j=0;j<=9;++j){
            if (j==9) dp[i][j]=(dp[i-1][0]+dp[i-1][1])%mod;
            else dp[i][j]=dp[i-1][j+1];
        }
    }
    int tc;cin>>tc;
    while (tc--){
        int n,m;cin>>n>>m;
        ll ans=0;
        vi x;
        int t=n;
        while (t>0){
            x.pb(t%10);t/=10;
        }
        for (int i:x){
           // cout<<i<<" ";
            ans=(ans+dp[m][i])%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}

