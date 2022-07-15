#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
#define int ll
    int tc;
    cin>>tc;
    while (tc--){
        int n;cin>>n;
        int k[n];
        for (int i=0;i<n;++i) cin>>k[i];
        int h[n];
        for (int i=0;i<n;++i){
            cin>>h[i];
        }
        vector<pii> start;
        for (int i=0;i<n;++i) {
            start.pb({k[i] - h[i] + 1, k[i]});
        }
        sort(start.begin(),start.end());
        ll ans=0;
        for (int i=0;i<n;){
            int first=start[i].f;
            int last=start[i].s;
            for (int j=i+1;j<n;++j){
                if (start[j].f<=last){
                    last=max(last,start[j].s);
                }
                else break;
            }


            ans=(ans+((last-first+1)*(last-first+2)) / 2);
            while (i<n && last>=start[i].f) ++i;
        }
        cout<<ans<<endl;


    }


    return 0;
}

