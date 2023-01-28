#include <bits/stdc++.h>
#define mp make_pair
#define pq priority_queue
#define pb push_back
#define f first
#define s second
//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using str = string;
using vivi = vector<vi>;

using vll = vector<ll>;
using vpii = vector<pii>;
using vb = vector<bool>;
using vd=vector<double>;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);cin.tie(0);

    int n;cin>>n;
    vd x(n);
    for (int i=0;i<n;++i) cin>>x[i];

    vector<vd> ord(n);
    for (int i=0;i<n;++i){
        double prev=1e9+1;
        for (int j=i-1;j>=0;--j){
            double slope=(x[i]-x[j])/(i-j);
            if (slope<=prev){
                ord[i].pb(j);prev=slope;
            }
        }
    }

    int q;cin>>q;
    while (q--){
        int a,b;cin>>a>>b;--a;
        // index is a, increase amt is b
        x[a]+=b;

        ll ans=0;
        for (int i=0;i<a;++i) ans+=ord[i].size();

        for (int i=a;i<n;++i){ // poc
            double prev=1e9+1;ord[i].clear();
            for (int j=i-1;j>=0;--j){
                double slope=(x[i]-x[j])/(i-j);
                if (slope<=prev){
                    ord[i].pb(j);prev=slope;
                }
            }
        }



        for (int i=a;i<n;++i) ans+=ord[i].size();
        cout<<ans<<endl;

    }


    return 0;
}