// FIX LATER DOESN'T WORK


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
using vi = vector<ll>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;
const ll mx=1e9;
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
    ll inv(ll x,ll m){
        return binpow(x,m-2,m);
    }


};
NT<ll> nt;
int n,k;
ll f(int num,int min){
    vi dp(num+1);

    dp[0]=1;
//    cout<<1<<endl;
    for (int i=1;i<k;++i){
//        cout<<i<<endl;
        dp[i]=(dp[i-1]*(mx-min+1))%mod;
    }
    cout<<k<<" "<<num<<endl;
    ll xx=nt.binpow(mx-min+1,k-1,mod);

    for (int i=k;i<=num;++i){
//        cout<<i<<" "<<num<<endl;
        if (i==k){
            dp[i]=(nt.binpow(mx-min+1,k,mod)-nt.binpow(mx-min,k,mod)+mod)%mod;
        }
        else{
            dp[i]=(dp[i-1]+(mx-min+1)*(dp[i-1]-xx*dp[i-k-1] % mod) %mod + mod)%mod;
        }
    }
//    cout<<2<<"\n";
    return dp[num];

}

int main() {



    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("tracking2.in","r",stdin);
    freopen("tracking2.out","w",stdout);

    cin>>n>>k;

    vi c(n-k+2);
    for (int i=1;i<c.size();++i) cin>>c[i];
    // starting at i, minimum is c[i]
    vi ans(n+2,-1);
    ans[0]=0;ans[n+1]=0;


    for (int i=2;i<c.size();++i){
        if (c[i]!=c[i-1]){
            if (c[i]>c[i-1]) ans[i-1]=c[i-1];
            else ans[i+k-1]=c[i];
        }
    }
//    for (int i:ans) cout<<i<<" ";cout<<endl;
    ll prevnum=0;
    int cnt=0;
    ll a=1;
//    cout<<1<<endl;
    for (int i=1;i<=n+1;++i){

        if (ans[i]==-1) ++cnt;
        else{
            if (cnt<k){

                a=(a*nt.binpow(mx-max(prevnum,ans[i])+1,cnt,mod))%mod;
            }
            else{
//                cout<<i<<" "<<i-k+1<<" "<<c.size()<<endl;
//                cout<<c[i-k+1]<<endl;
//                cout<<i<<endl;
//                cout<<i-k+1<<" "<<c.size()<<endl;
                a=(a*f(cnt,c[i-k+1]))%mod;
            }
            prevnum=ans[i];cnt=0;
        }
    }
    cout<<a<<endl;



    return 0;
}

