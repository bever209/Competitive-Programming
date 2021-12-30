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
vector<pii> arr;int n,m;

ll solve(int g){ // all terms divisible by g, satisfy other two constraints
    vector<vi> dp(n+1,vi(m/g+1)); // first i vals, sum to j*g
    dp[0][0]=1;
    for (int i=1;i<=n;++i){
        int low=(arr[i-1].f+g-1)/g;int high=arr[i-1].s/g;
        if (low>high) continue;
        for (int j=0;j<=m/g;++j){
            if (low+j<=m/g){
                dp[i][low+j]=(dp[i][low+j]+dp[i-1][j])%mod;
            }
            if (high+j+1<=m/g){
                dp[i][high+j+1]=(dp[i][high+j+1]-dp[i-1][j]+mod)%mod;
            }
        }
        ll pref=0;
        for (int j=0;j<=m/g;++j){
            pref=(pref+dp[i][j])%mod;
            dp[i][j]=pref;
        }
    }
    ll ans=0;
    for (int i=0;i<=m/g;++i){
        ans=(ans+dp[n][i])%mod;
    }
    return ans;
}


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    arr.resize(n);
    for (int i=0;i<n;++i){
        cin>>arr[i].f>>arr[i].s;
    }
    vi a(m+1);
    for (int i=1;i<=m;++i){
        a[i]=solve(i) % mod;
    }
    vi d(m+1);
    for (int i=m;i>=1;--i){
        d[i]=a[i];
        for (int j=2;j*i<=m;++j){
            d[i]=(d[i]-d[i*j]+mod)%mod;
        }
    }
    cout<<d[1]<<endl;



    return 0;
}

