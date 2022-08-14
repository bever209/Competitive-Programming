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
using vivi = vector<vi>;
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
        vi b(n);
        for (int i=0;i<n;++i) cin>>a[i];
        for (int i=0;i<n;++i) cin>>b[i];

        map<int,int> m;
        vi aa;
        for (int i:a) aa.pb(i);
        sort(aa.begin(),aa.end());
        for (int i=0;i<n;++i) m[aa[i]]=i;

        for (int i=0;i<n;++i){
            a[i]=m[a[i]];
        }

        m.clear();
        vi bb;
        for (int i:b) bb.pb(i);
        sort(bb.begin(),bb.end());
        for (int i=0;i<n;++i) m[bb[i]]=i;

        for (int i=0;i<n;++i){
            b[i]=m[b[i]];
        }




        vector<pair<pii,int>> x;
        for (int i=0;i<n;++i){
            x.pb({{a[i],b[i]},i});
        }
        sort(x.begin(),x.end());
        reverse(x.begin(),x.end());

        vb ans(n);

        ans[x[0].s]=true;
        vi suff(n+1);
        for (int i=n-1;i>=0;--i){
            if (i<n-1) suff[i]=max(suff[i+1],x[i].f.s);
            else suff[i]=x[i].f.s;
        }

        int smin=n;
        for (int i=0;i<n;++i){
            if (smin<suff[i]) ans[x[i].s]=true;
            if (ans[x[i].s])
            smin=min(smin,x[i].f.s);
        }
        for (int i:ans){
            cout<<i;
        }
        cout<<endl;



        
    }


    return 0;
}


