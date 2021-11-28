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
ll mod=1e9+7;
vector<ll> factorial;
ll power(long long x,  int y, ll p)
{
    y=y%(p-1);
    ll res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res%p;
}
long long binomial_coefficient(int n, int k) {
    return factorial[n] * power(factorial[k]*factorial[n-k],mod-2,mod) % mod;
}
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    factorial.resize(2e5+5);
    factorial[0] = 1;
    for (int i = 1; i <2e5+5; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
    }

    int tc;cin>>tc;
    while (tc--){
        int n,k;
        cin>>n>>k;

        ll ans=0;

        ll same=0;
        for (int i=0;i<n;i+=2){
            same=(same+ binomial_coefficient(n,i))%mod;
        }
        if (n%2==1){
            same+=1;
        }
        bool win=false;
        if (n%2==0){
            win=true;
        }
        //cout<<same<<endl;
        ans+=power(same,k,mod);
        ans=ans%mod;

        if (win){
            for (int i=k-1;i>=0;--i){
                ll x=power(2,n*(i),mod) %mod;
                ll y=power(same,(k-1)-i,mod) %mod;
                ll sm=(x*y)%mod;
                ans=(ans+sm)%mod;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}

