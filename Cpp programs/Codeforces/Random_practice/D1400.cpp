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

int base=3500;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        vi a(n);
        for (int i=0;i<n;++i) cin>>a[i];
        int len=n+5;
        vector<vector<vpii>> p(len,vector<vpii>(len));
        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                p[a[i]][a[j]].pb({i,j});
            }
        }

        // p[i][j] holds all pairs of occurrences of i and j

        ll ans=0;
        for (auto & i : p){
            for (auto & j : i){
                sort(j.begin(),j.end());

                for (int k=0;k<j.size();++k){
                    pii aa={j[k].s+1,-1};
                    int x= lower_bound(j.begin(),j.end(),aa)-j.begin();
                    ans+=(j.size()-x);
                }
            }
        }
        cout<<ans<<endl;



    }


    return 0;
}


