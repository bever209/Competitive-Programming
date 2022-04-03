#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using str = string;
const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
#define int ll
    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];
    vi tot(n);

    int q;cin>>q;
    map<pii,int> m;ll ans=0;
    for (int i:arr) ans+=i;
    while (q--){
        int a,b,c;cin>>a>>b>>c;
        --a;--c;

        if (m.count({a,b})){
            int x=m[{a,b}];
            m.erase({a,b});

            ans=ans-(max((ll)0,arr[x]-tot[x]));
            tot[x]--;
            ans=ans+(max((ll)0,arr[x]-tot[x]));
        }
        if (c>=0){
            m[{a,b}]=c;
            ans=ans-(max((ll)0,arr[c]-tot[c]));
            tot[c]++;
            ans=ans+(max((ll)0,arr[c]-tot[c]));
        }
        cout<<ans<<"\n";
    }


    return 0;
}

