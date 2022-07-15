#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
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
        int n;cin>>n;
        str s;str t;cin>>s>>t;

        if (s[0]!=t[0] || s[n-1]!=t[n-1]){
            cout<<-1<<endl;continue;
        }
        vpii as;
        vpii at;
        int start=-1;
        int rc=0;
        for (int i=0;i<n;++i){
            if (s[i]=='1'){
                if (rc==0) start=i,++rc;
                else ++rc;
            }
            else{
                if (rc>0){
                    as.pb({start,rc});
                    start=-1;rc=0;
                }
            }
            if (i==n-1){
                if (rc>0){
                    as.pb({start,rc});
                }
            }
        }
        start=-1;
        rc=0;
        for (int i=0;i<n;++i){
            if (t[i]=='1'){
                if (rc==0) start=i,++rc;
                else ++rc;
            }
            else{
                if (rc>0){
                    at.pb({start,rc});
                    start=-1;rc=0;
                }
            }
            if (i==n-1){
                if (rc>0){
                    at.pb({start,rc});
                }
            }
        }


//        cout<<as.size()<<" "<<at.size()<<endl;
        if (as.size()!=at.size()){
            cout<<-1<<endl;continue;
        }
        ll ans=0;
        for (int i=0;i<as.size();++i){
            ans+=(abs(as[i].f-at[i].f));ans+=(abs(as[i].f+as[i].s-(at[i].f+at[i].s)));

        }
        cout<<ans<<endl;

    }


    return 0;
}

