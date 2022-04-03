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
ll fact[(int)1e5+8];
ll invfact[(int)1e5+8];
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
    fact[0]=1;
    for (int i=1;i<1e5+8;++i){
        fact[i]=(fact[i-1]*i)%mod;
    }
    invfact[0]=1;
    for (int i=1;i<1e5+8;++i){
        invfact[i]=(invfact[i-1]*x.inv(i,mod))%mod;
    }


    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    ll sum=0;
    for (int i:arr) sum+=i;
    if (sum%n!=0){
        cout<<0;return 0;
    }
    ll goal=sum/n;
    int l=0;int h=0;
    for (int i:arr){
        if (i<goal) ++l;
        else if (i>goal) ++h;
    }
    map<int,int> m;
    for (int i:arr) m[i]++;

    if (h<=1 || l<=1){
        ll ans=1;
        ans=ans*fact[n];
        for (auto i:m){
            ans=(ans*(invfact[i.s])) % mod;
        }
        cout<<ans;
    }
    else{
        ll ans=2;
        vi lower;vi higher;int eq=0;
        for (auto i:m){
            if (i.f>goal) higher.pb(i.s);
            else if (i.f<goal) lower.pb(i.s);
            else if (i.f==goal) eq=i.s;
        }
        int sum1=0;
        int sum2=0;
        for (int i:higher){
            sum1+=i;
            ans=(ans*invfact[i])%mod;
        }
        ans=(ans*fact[sum1])%mod;
        for (int i:lower){
            ans=(ans*invfact[i])%mod;sum2+=i;
        }
        ans=(ans*fact[sum2])%mod;

        int tot=sum1+sum2;
        for (int i=0;i<eq;++i){
            ans=(ans*(tot+1+i))%mod;
        }

        ans=(ans*invfact[eq])%mod;
        cout<<ans;


    }


    return 0;
}

