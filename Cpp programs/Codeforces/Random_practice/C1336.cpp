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
const int mxn=3005;
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;cin>>a>>b;
    int n=a.size();int m=b.size();
    vector<vi> dp(mxn+1,vi(mxn+1));
    // dp[i][j] is using the first len chars from S to fill in T[i:j] (S=a,T=b)

    // just range dp basically

    for (int i=0;i<m;++i){
        if (b[i]==a[0]) dp[i+1][i+1]=2;
    }
    for (int i=m;i<n;++i) dp[i+1][i+1]=2;

    for (int i=n;i>=1;--i){
        for (int j=i+1;j<=n;++j){
            int x=j-i;
            if (j>m) dp[i][j]+=dp[i][j-1];
            else if (a[x]==b[j-1]) dp[i][j]+=dp[i][j-1];

            if (i>m) dp[i][j]+=dp[i+1][j];
            else if (a[x]==b[i-1]) dp[i][j]+=dp[i+1][j];

            dp[i][j]%=mod;
        }
    }
    ll ans=0;
    for (int i=m;i<=n;++i){
        ans=(ans+dp[1][i])%mod;
    }
    cout<<ans<<endl;




    return 0;
}

