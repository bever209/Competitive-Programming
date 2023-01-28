#include <bits/stdc++.h>
//#pragma GCC target ("avx2")
#define mp make_pair
#define pq priority_queue
#define pb push_back
#define f first
#define s second
//#pragma GCC optimize ("Ofast")

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

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);cin.tie(0);



    int n,a,b;cin>>n>>a>>b;

    vector<vi> x(n,vi(3));
    for (int i=0;i<n;++i) cin>>x[i][0]>>x[i][1]>>x[i][2];

    vector<vivi> dp(n+1,vivi(a+1,vi(b+1))); // dp[i][j][k] is max pop if we have
    // gone through first i and have j money and k cones

    for (int i=1;i<=n;++i){
        for (int j=0;j<=a;++j){
            for (int k=0;k<=b;++k){
                dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);

                int f=0; // number of cones used
                while (f<=k && f<=x[i-1][1]*x[i-1][2]){
                    if (j>=x[i-1][1]-f/x[i-1][2]){
                      dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-(x[i-1][1]-f/x[i-1][2])][k-f]+x[i-1][0]);
                    }
                    f+=x[i-1][2];
                }
            }
        }
    }
    cout<<dp[n][a][b]<<endl;



    return 0;
}


