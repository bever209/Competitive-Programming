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

    int n,mod;cin>>n>>mod;
    vi pow2(n+5);
    pow2[0]=1;
    for (int i=1;i<n+5;++i) pow2[i]=(pow2[i-1]*2)%mod;
    vector<vi> pascal(405,vi(405));
    for (int i=0;i<405;++i){
        for (int j=0;j<=i;++j){
            if (i==0 || j==0) pascal[i][j]=1;
            else{
                pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j]) % mod;
            }
        }
    }
    vector<vi> dp(n+2,vi(n+1));
    dp[0][0]=1;
    for (int i=0;i<=n;++i){
        for (int j=0;j<=i;++j){
            for (int k=1;k+i+1<=n+1;++k){
                dp[i+k+1][j+k]=(dp[i+k+1][j+k]+(dp[i][j] * pascal[j+k][k])%mod * pow2[k-1]) % mod;

            }
        }
    }
    ll ans=0;
    for (int i=0;i<=n;++i) ans=(ans+dp[n+1][i]) % mod;
    cout<<ans<<endl;

    return 0;
}

