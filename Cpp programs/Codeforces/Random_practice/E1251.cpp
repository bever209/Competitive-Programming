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
        pii arr[n];
        for (int i=0;i<n;++i) cin>>arr[i].f>>arr[i].s;
        sort(arr,arr+n);

        vector<vi> a(n);
        for (auto i:arr){
            a[i.f].pb(i.s);
        }
        ll ans=0;
        multiset<int> m;
        int pref=n;int taken=0;
        for (int i=n-1;i>=0;--i){
            for (int j:a[i]){
                m.insert(j);
            }
            pref=pref-a[i].size();
            int need=max(0,i-pref);
            while (taken<need){
                ++taken;
                ans=ans+*(m.begin());
                m.erase(m.begin());
            }
        }

        cout<<ans<<endl;
    }


    return 0;
}

