#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vivi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
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
const int len=5e5;

vll fact(len+5);
const ll mod=1e9+7;

ll choose(int a,int b){
    if (a<b) return 0;
    return (fact[a]*(nt.inv((fact[a-b]*fact[b])%mod,mod)))%mod;
}
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0]=1;
    for (int i=1;i<fact.size();++i){
        fact[i]=(fact[i-1]*i)%mod;
    }

    ll ans=0;
    int n;cin>>n;
    vi a(n+1);
    for (int i=0;i<=n;++i) cin>>a[i];

    for (int i=0;i<=n;++i){
        ans=(ans+choose(a[i]+i,i+1))%mod;
    }
    cout<<ans<<endl;



    return 0;
}


