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
const ll mod= 998244353;

ll fact[505];
template<class T> struct NT{
    T gcd(T a,T b){
        if (a==0) return b;
        if (b==0) return a;
        if (a>b) return gcd(a%b,b);
        else return gcd(b%a,a);
    }
    T lcm(T a,T b){
        return ((a/gcd(a,b)) * b);
    }
    ll binpow(ll x, ll n, ll m) {
        x %= m;
        ll res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = res * x % m;
            x = x * x % m;
            n /= 2;
        }
        return res;
    }
    ll inv(ll x,ll m){
        return binpow(x,m-2,m);
    }


};
NT<ll> nt;
ll choose(int i,int j){
    return (fact[i]*((nt.inv(fact[j]*fact[i-j] % mod,mod))) % mod);
}
int main() {
    fact[0]=1;
    for (int i=1;i<=503;++i){
        fact[i]=(fact[i-1]*i)%mod;
    }

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,x;cin>>n>>x;
    vector<vi> dp(n+1,vi(x+1));


    // number of ways to have one sole winner given x starting, y is max -> dp[x][y]
    vector<vi> c(n+1,vi(x+1));
    for (int i=0;i<=n;++i){
        for (int j=0;j<=x;++j){
            c[i][j]= choose(i,j) %mod;
        }
    }

    for (int i=1;i<=x;++i){
        dp[1][i]=i;
    }
    for (int i=2;i<=n;++i){
        for (int j=1;j<=x;++j){
            if (i>j){
                dp[i][j]=0;continue;
            }
            for (int k=1;k<=i;++k){ // number that is survived after
                dp[i][j] = (dp[i][j]+ (c[i][k]*nt.binpow(i-1,i-k,mod) % mod) * dp[k][j+1-i]) % mod;
            }
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;

    }


    ll a=nt.binpow(x,n,mod);
    cout<<(a-dp[n][x]+mod) % mod;




    return 0;
}

