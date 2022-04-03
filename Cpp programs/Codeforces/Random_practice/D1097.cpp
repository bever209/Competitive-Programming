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

const ll mod=1e9+7;
NT<ll> nt;
vi inv(100);

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,k;cin>>n>>k;

    vi p;vi q;
    for (ll i=2;i*i<=n;++i){
        if (n%i==0){
            p.pb(i);int d=0;
            while (n%i==0) {
                n /= i;++d;
            }
            q.pb(d);
        }
    }
    if (n>1){
        p.pb(n);q.pb(1);
    }
    for (int i=1;i<inv.size();++i){
        inv[i]=nt.inv(i,mod);
    }

    ll fin_ans=1;
    for (int a=0;a<p.size();++a){
        ll ans=0;
        int num=q[a];
        vector<vi> dp(k+1,vi(num+1));
        dp[0][num]=1;
        for (int i=0;i<k;++i){
            for (int j=num;j>=0;--j){
                for (int l=j;l>=0;--l){
                    dp[i+1][l]=(dp[i+1][l]+dp[i][j] * inv[j+1]) % mod;
                }
            }
        }

        ll x=1;
        ll pp=p[a];
        for (int i=0;i<=num;++i){
            ans=(ans+dp[k][i] * x)%mod;
            x=(x*pp)%mod;
        }
        fin_ans=(fin_ans*ans)%mod;
    }
    cout<<fin_ans;



    return 0;
}

