#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--) {
        int n;
        cin >> n;

        ll a[n];
        ll b[n];
        for (int i=0;i<n;++i) cin>>a[i];
        for (int i=0;i<n;++i) cin>>b[i];

        ll totsum=0;
        for (ll i:a) totsum+=i;
        for (ll i:b) totsum+=i;


        vector<vi> dp(n+1,vi(totsum+1));// dp[i][j] -> if we can form j using first i
        dp[0][0]=1;
        for (int i=1;i<=n;++i){
            for (int j=0;j<=totsum;++j){
                int t=j-a[i-1];
                int r=j-b[i-1];
                if (t>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][t]);
                }
                if (r>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][r]);
                }
            }
        }

        ll ans=0;
        ll diff=inf;
        ll num=0;
        for (int i=0;i<=totsum;++i){
            if (dp[n][i]){
                if (diff>abs(totsum-2*i)){
                    num=i;diff=abs(totsum-2*i);
                }
            }
        }
//        cout<<num<<endl;
        ans=ans+num*num+(totsum-num)*(totsum-num);
        ll sq=0;
        for (int i:a){
            sq+=i*i;
        }
        for (int i:b) sq+=i*i;

        ans+=(n-2)*sq;
        cout<<ans<<"\n";

    }


    return 0;
}

