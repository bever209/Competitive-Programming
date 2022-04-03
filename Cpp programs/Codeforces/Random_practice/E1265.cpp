#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;
const ll mod=998244353;

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
int main() {

    NT<ll> x;
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    ll num=100;
    ll denom=arr[0];
    for (int i=1;i<n;++i){
        num=(num+denom)%mod;
        num=(num*100)%mod;
        denom=(arr[i]*denom)%mod;
    }

    ll ans=(num*(x.inv(denom,mod)))%mod;
    cout<<ans<<endl;




    return 0;
}

