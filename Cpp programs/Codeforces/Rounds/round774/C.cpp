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
    ll fact[19];
    ll p[50];
    fact[0]=p[0]=1;
    for (int i=1;i<19;++i){
        fact[i]=fact[i-1]*i;
    }
    for (int i=1;i<50;++i){
        p[i]=p[i-1]*2;
    }

    while (tc--) {
        ll n;
        cin >> n;
        set < pair<ll,int> > s;
        for (int i = 0; i < (1 << 15); ++i) {
            ll sum = 0;int c=0;
            for (int j = 0; j < 15; ++j) {
                if ((1 << j) & i) {
                    sum += fact[j];++c;
                }
            }
            s.insert({sum,c});
        }
        ll ans = 100;
        for (auto i:s) {
            if (i.f <= n) {
                ll val = n - i.f;
                ll x=0;
                for (int j=49;j>=0;--j){
                    if (p[j]<=val){
                        ++x;val-=p[j];
                    }
                }
                ans=min(ans,i.s+x);
            }
        }

        cout << ans << "\n";


    }


    return 0;
}

