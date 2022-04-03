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
#define int ll
    NT<ll> nt;
    ios::sync_with_stdio(false);
    cin.tie(0);
    const ll mod=1e9+7;
    int tc;cin>>tc;
    while (tc--){
        int n,m;cin>>n>>m;
        int ans=nt.binpow(2,n-1,mod);
        int x=0;
        for (int i=0;i<m;++i){
            int a,b,c;cin>>a>>b>>c;
            x=x|c;
        }
        cout<<(ans*x)%mod<<endl;
    }


    return 0;
}

