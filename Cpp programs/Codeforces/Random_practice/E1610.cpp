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
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);


    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        vi a(n);
        for (int i=0;i<n;++i) cin>>a[i];

        if (n==2){
            cout<<0<<endl;continue;
        }
        int ans=2;

        for (int i=0;i<n-2;++i){
            int ind=i;int c=0;
            if (i!=0 && a[i]==a[i-1]) continue;
            while (ind<n){
                ++c;
                ind= lower_bound(a.begin()+ind+1,a.end(),2*a[ind]-a[i])-a.begin();
            }
            ans=max(ans,c);
        }
        cout<<n-ans<<endl;
    }


    return 0;
}

