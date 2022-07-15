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
        vi a(n+1);
        for (int i=0;i<n;++i) cin>>a[i+1]; // check indexes


        vpii b(n+1);
        for (int i=1;i<=n;++i){
            b[i].f=i/(a[i]+1)+1;
            if (a[i]!=0)
                b[i].s=i/a[i];
            else b[i].s=n;
        }

        vi ans(n+1);
        vector<pair<pii,int>> x;
        for (int i=1;i<=n;++i){
            x.pb({{b[i].f,b[i].s},i});
//            cout<<b[i].f<<" "<<b[i].s<<" "<<i<<endl;
        }
//        for (auto i:x) cout<<i.f.f<<" "<<i.f.s<<" "<<i.s<<endl;

        vector<vpii> c(n+1);
        for (int i=0;i<n;++i){
//            cout<<x[i].f.f<<" "<<x[i].f.s<<" "<<x[i].s<<endl;
            c[x[i].f.f].pb({x[i].f.s,x[i].s});
        }
        set<pii> s;
        for (int i=1;i<=n;++i){
            for (auto j:c[i]) s.insert(j);
            pii top=*(s.begin());
            s.erase(s.find(top));

            ans[top.s]=i;
        }
        for (int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<endl;



    }



    return 0;
}

