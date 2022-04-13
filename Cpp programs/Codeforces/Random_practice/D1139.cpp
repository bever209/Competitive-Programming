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
NT<ll> nt;
const ll mod=1e9+7;
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vi exp(n+1);
    for (int i=n;i>=2;--i){
        ll ans=1;
        ll num=(n/i) * nt.inv(n,mod) % mod;
        ans=num+num*(nt.inv(1-num+mod,mod)) % mod;
        for (int j=i+i;j<=n;j+=i){
            ans=(ans-exp[j]+mod)%mod;
        }
        exp[i]=ans;
    }
    ll ans=0;
    for (auto i:exp) ans=(ans+i) % mod;
    ans=ans+nt.inv(n,mod);
    cout<<ans%mod<<endl;



    return 0;
}

