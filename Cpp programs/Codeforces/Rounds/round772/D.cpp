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
const ll mod=1e9+7;
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    vi r(2e5+5);
    r[0]=1;
    r[1]=1;
    for (int i=2;i<r.size();++i) r[i]=(r[i-1]+r[i-2])%mod;

    ll pref=0;
    for (int i=0;i<r.size();++i){
        r[i]=(r[i]+pref)%mod;
        pref=r[i] % mod;
    }

    int n,p;cin>>n>>p;
    ll arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    sort(arr,arr+n);
    set<ll> s;

    for (ll i:arr){
        ll x=i;
        if (s.count(i)){
            continue;
        }
        bool check=true;
        while (i%4!=2 && i>0){
            if (i%4==0) {
                i /= 4;
            }
            else{
                i=(i-1)/2;
            }
            if (s.count(i)){
                check=false;
            }
        }
        if (check){
            s.insert(x);
        }


    }


    ll ans=0;
    for (int i:s){
        int c=0;
        int q=1;
        while (q<=i){
            ++c;q*=2;
        }
        int num=p-c;
        if (num>=0){
            ans=(ans+r[num])%mod;
        }
    }
    cout<<ans<<"\n";



    return 0;
}

