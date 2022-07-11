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

ll pw[(int)1e5+5];
const ll mod=1e9+7;
void precalc(){
    pw[0]=1;
    for (int i=1;i<1e5+5;++i){
        pw[i]=(2*pw[i-1])%mod;
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("help.in","r",stdin);
    freopen("help.out","w",stdout);

    precalc();

    ll ans=0;
    int n;cin>>n;
    pii arr[n];
    for (int i=0;i<n;++i) cin>>arr[i].f>>arr[i].s;

    vector<ll> a(2*n+1,0);
    for (int i=0;i<n;++i){
        a[arr[i].f]++;
        a[arr[i].s]--;
    }
    ll pref=0;
    for (long long & i : a){
        pref+=i;
        i=pref;
    }
    for (auto i:arr){
        ans=(ans+pw[n-1-a[i.f-1]])%mod;
    }
    cout<<ans%mod;



    return 0;
}

