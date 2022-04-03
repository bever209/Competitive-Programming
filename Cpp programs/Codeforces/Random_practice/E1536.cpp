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
const ll mod=1e9+7;


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
    ll inv(ll x,ll mod){
        return binpow(x,mod-2,mod);
    }


};
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    NT<ll> x;
    int tc;cin>>tc;
    while (tc--){
        int n,m;cin>>n>>m;
        str arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];

        int cn=0;
        int c0=0;
        for (auto i:arr){
            for (int j=0;j<m;++j){
                if (i[j]=='0')++c0;
                else ++cn;
            }
        }
        if (c0!=0){
            cout<<x.binpow(2,cn,mod);
        }
        else cout<<(x.binpow(2,cn,mod)-1+mod)%mod;

        cout<<endl;

    }


    return 0;
}

