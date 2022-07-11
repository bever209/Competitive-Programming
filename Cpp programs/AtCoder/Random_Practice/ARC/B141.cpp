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
const ll mod=998244353;


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;cin>>n>>m;
    vi p(65);
    p[0]=1;
    for (int i=1;i<65;++i) p[i]=(p[i-1]*2)%mod;

    int numbits=0;
    ll mm=m;
    while (mm>0) {
//        cout<<mm<<endl;
        mm /= 2;
        numbits++;
    }
    if (n>numbits){
        cout<<0;return 0;
    }

    vi cbit(numbits);
    for (int i=0;i<numbits;++i) {
        if (i == numbits - 1) {
            cbit[i] = m - p[i] + 1;
        } else {
            cbit[i] =p[i];
        }
        cbit[i]%=mod;
    }
//    for (int i:cbit) cout<<i<<" ";
//    cout<<endl;

    vector<vector<vi>> dp(numbits+1,vector<vi>(numbits+1,vi(numbits+1)));
    // dp[i][j][k] -> ith cyclic sum over numbers from indices from j to k
    // precondition is that i<=k-j+1

    for (int i=0;i<numbits;++i){
        ll sum=0;
        for(int j=i;j<numbits;++j){
            sum=(sum+cbit[j])%mod;
            dp[1][i][j]=sum;
        }
    }

    for (int i=2;i<=numbits;++i){
        for (int j=numbits-1;j>=0;--j){
            for (int k=i+j-1;k<numbits;++k){
                dp[i][j][k]=(cbit[j]*dp[i-1][j+1][k] % mod+dp[i][j+1][k])%mod;
            }
        }
    }

    cout<<dp[n][0][numbits-1]<<endl;


    return 0;
}

