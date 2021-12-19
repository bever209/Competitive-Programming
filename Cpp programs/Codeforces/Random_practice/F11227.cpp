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
const ll mod=998244353;
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    int rotated[n];
    for (int i=1;i<=n;++i){
        rotated[i-1]=arr[i%n];
    }
    vector<vi> dp(n+1,vi(2*n+3)); // add n+1 to second index always
    dp[0][0+(n+1)]=1;

    for (int i=1;i<=n;++i){
        for (int j=-(n);j<=(n);++j){
            if (arr[i-1]==rotated[i-1]){
                dp[i][j+n+1]=(dp[i][j+n+1]+k*dp[i-1][j+n+1])%mod;
            }
            else{
                dp[i][j+n+1]=(dp[i][j+n+1]+dp[i-1][j+n])%mod;
                dp[i][j+n+1]=(dp[i][j+n+1]+dp[i-1][j+n+2])%mod;
                dp[i][j+n+1]=(dp[i][j+n+1]+(k-2)*dp[i-1][j+n+1])%mod;
            }
        }
    }
    ll ans=0;
    for (int i=0;i<2*n+3;++i){
        int num=i-(n+1);
        if (num>0){
            ans=(ans+dp[n][i])%mod;
        }
    }
    cout<<ans<<endl;



    return 0;
}

