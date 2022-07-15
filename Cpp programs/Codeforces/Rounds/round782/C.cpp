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
        //use lls
        ll n,a,b;cin>>n>>a>>b;swap(a,b);
        ll arr[n+1];
        for (int i=0;i<n;++i) cin>>arr[i+1];
        arr[0]=0;
        ll ans=0;ll cap=0;
        for (int i=1;i<=n;++i){
            ans=ans+a*(arr[i]-arr[cap]);
            if (b<(n-i)*a){
                ans=ans+b*(arr[i]-arr[cap]);
                cap=i;
            }
//            cout<<ans<<" in"<<endl;
        }
        cout<<ans<<"\n";

    }


    return 0;
}

