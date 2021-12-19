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

    int r,n;cin>>r>>n;
    vector<pair<int,pii>> x;
    x.pb({0,{1,1}});
    for (int i=0;i<n;++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x.pb({a, {b, c}});
    }
    vi dp(n+1);
    vi prefmax(n+1);
    for (int i=1;i<=n;++i){
        for (int j=i-1;j>=i-(2*r+10) && j>=0;--j){
            int time=x[i].f-x[j].f;
            int needed=abs(x[j].s.f-x[i].s.f)+abs(x[j].s.s-x[i].s.s);
            if (time>=needed) {
                if (dp[j] > 0 || j == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ind=i-(2*r+10)-1;
        if (ind>=0){
            dp[i]=max(dp[i],prefmax[ind]+1);
        }
        prefmax[i]=max(prefmax[i-1],dp[i]);
    }
    cout<<prefmax[n]<<endl;


    return 0;
}

