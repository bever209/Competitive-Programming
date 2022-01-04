#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll=pair<ll,ll>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        ll arr[2*n][2*n];
        for (int i=0;i<2*n;++i) for (int j=0;j<2*n;++j) cin>>arr[i][j];
        ll ans=0;
        for (int i=n;i<2*n;++i){
            for (int j=n;j<2*n;++j) ans+=arr[i][j];
        }
        ll mn=min(arr[n][n-1],arr[n-1][n]);
        mn=min(mn,arr[2*n-1][n-1]);
        mn=min(mn,arr[n-1][2*n-1]);

        ll a=min(arr[2*n-1][0],arr[0][2*n-1]);
        ll b=min(arr[n][0],arr[0][n]);
        mn=min(mn,a);
        mn=min(mn,b);

        ans+=mn;
        cout<<ans<<"\n";
    }


    return 0;
}