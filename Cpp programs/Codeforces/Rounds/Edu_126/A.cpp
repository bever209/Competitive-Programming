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

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        ll a[n];
        ll b[n];
        for (int i=0;i<n;++i) cin>>a[i];
        for (int i=0;i<n;++i) cin>>b[i];

        ll ans=0;
        for (int i=1;i<n;++i){
            ll x=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
            ll y=abs(b[i]-a[i-1])+abs(a[i]-b[i-1]);
            ans=ans+min(x,y);
        }
        cout<<ans<<endl;

    }


    return 0;
}

