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
vector<ll> p(2e5+5);
vector<ll> pn(2e5+5);  // 2^n all to the power of k
const ll mod=1000000007;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    p[0]=1;
    for (int i=1;i<p.size();++i) p[i]=(p[i-1]*2)%mod;


    int tc;cin>>tc;
    while (tc--){
        int n,k;cin>>n>>k;
        if (k==0){
            cout<<1<<"\n";continue;
        }
        pn[0]=1;
        for (int i=1;i<pn.size();++i) pn[i]=(pn[i-1]*p[n])%mod;
        vi ans(k+1); // using 1 bit, 2 bits, etc. 0 is dummy

        ans[1]=p[n-1];

        if (n%2==1) ++ans[1];
        ll tie=ans[1];
        if (n%2==0) --tie;

        ll win=n%2==0;
        for (int i=2;i<ans.size();++i){
            ans[i]=(win*pn[i-1]+tie*ans[i-1])%mod;
        }
        cout<<ans[k]<<"\n";


    }


    return 0;
}

