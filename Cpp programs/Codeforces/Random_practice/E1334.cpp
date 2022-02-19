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
#define endl "\n"

const ll mod=998244353;
ll binpow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1)
            res = (res*a) % mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}


const ll inf = 2 * 1e18;

int main() {

#define int ll
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll fact[100];
    fact[0]=1;

    for (int i=1;i<100;++i){
        fact[i]=(i*fact[i-1]) % mod;
    }
    ll invfact[100];
    invfact[99]=binpow(fact[99],mod-2);
    for (int i=98;i>=0;--i){
        invfact[i]=(invfact[i+1] * (i+1)) % mod;
    }


    int d;cin>>d;

    vi primes;
    for (int i=2;i<(int)sqrt(d)+1;++i){
        if (d%i==0){
            primes.pb(i);
            while (d%i==0) d/=i;
        }
    }
    if (d>1) primes.pb(d);
    // up to here, good
    int q;cin>>q;
    while (q--){
        int a,b;cin>>a>>b;ll g=gcd(a,b);
        a/=g;b/=g;
        vi afactors;vi bfactors;
        for (int i:primes){
            int c=0;
            if (a%i==0){
                while (a%i==0){
                    a/=i;++c;
                }
                afactors.pb(c);
            }
            int e=0;
            if (b%i==0){
                while (b%i==0){
                    ++e;b/=i;
                }
                bfactors.pb(e);
            }
        }
        int asum=0;int bsum=0;
        for (int i:afactors) asum+=i;
        for (int i:bfactors) bsum+=i;

        ll ans=1;
        ans = (ans*fact[asum] * fact[bsum]) % mod;
        for (int i:afactors) ans=(ans*invfact[i]) % mod;
        for (int i:bfactors) ans = (ans * invfact[i]) % mod;
        cout<<ans<<endl;
    }


    return 0;
}

