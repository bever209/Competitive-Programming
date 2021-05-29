#include <bits/stdc++.h>
 
#define pb push_back
#define f first
#define s second
#define mp make_pair
 
using namespace std;
using ll = long long;
const int MOD = 998244353;
int main()
{
 
    
    ios::sync_with_stdio(false);
    cin.tie(0);
 
 
    int n;
    cin>>n;
 
    ll dp[1000090];
    memset(dp,0,sizeof(dp));
 
    for (int i=1;i<=1e6;++i){
        ll k=1;
        while (i*k<=1e6){
            dp[i*k]++;
            ++k;
        }
    }
    ll sum=0;
    for (int i=1;i<=1e6;++i){
        sum%=MOD;
        dp[i]%=MOD;
        dp[i]+=sum;
        sum+=dp[i];
        
    }
    cout<<dp[n]%MOD<<endl;
 
 
 
    return 0;
}