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
const ll mod=1e8;
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d;cin>>a>>b>>c>>d;

    int tot=a+b;

    vector<vector<vi>> dp(a+1,vector<vi>(b+1,vi(2)));
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    // check this

    for (int i=0;i<=a;++i){
        for (int j=0;j<=b;++j){
            if (!(i==0 && j==0)){
                for (int k=1;k<=c;++k){
                    if (i-k>=0)
                    dp[i][j][0]=(dp[i][j][0]+dp[i-k][j][1])%mod;
                }
                for (int k=1;k<=d;++k){
                    if (j-k>=0)
                    dp[i][j][1]=(dp[i][j][1]+dp[i][j-k][0])%mod;
                }
            }
        }
    }
    cout<<(dp[a][b][1]+dp[a][b][0]) % mod;


    return 0;
}

