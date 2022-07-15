#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
#define int ll
    int tc;cin>>tc;
    while (tc--){
        ll n,m;cin>>n>>m;
        vi a(m);
        for (int i=0;i<m;++i) cin>>a[i],--a[i];
        vi x(n);
        for (int i:a) x[i]++;

        int low=0;
        int high=2*m;
        while (low<high){
            int mid=(low+high)/2; // check
            ll tot=0;
            for (int i=0;i<n;++i){
                ll same=min(mid,x[i]);
                ll diff=(mid-same)/2;
                tot+=(same+diff);
            }
            if (tot<m){
                low=mid+1;
            }
            else high=mid;

        }
        cout<<low<<endl;
    }


    return 0;
}

