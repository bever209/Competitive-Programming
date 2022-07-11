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
using vb=vector<bool>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    str s;cin>>s;

    int mn=0;
    int mx=n;
    while (mn<mx){
        int mid=(mn+mx+1)/2;

        vector<vi> block(n+1,vi(k)); // max length we can place letter j starting from position i ->dp[i][j]
        for (int i=n-1;i>=0;--i){
            for (int j=0;j<k;++j){
                if (s[i]-'a'==j || s[i]=='?'){
                    block[i][j]=block[i+1][j]+1;
                }
                else{
                    block[i][j]=0;
                }
            }
        }
        vector<vi> close(n,vi(k,-1)); // STARTING POINT
        for (int i=n-1;i>=0;--i){
            for (int j=0;j<k;++j){
                if (block[i][j]>=mid) close[i][j]=i;
                else{
                    if (i<n-1) close[i][j]=close[i+1][j];
                }
            }
        }

        vi dp(1<<k,n+10); // dp[i] is shortest prefix needed if we want all blocks to have all letters with length at least mid
        dp[0]=0;
        for (int i=1;i<(1<<k);++i){
            for (int j=0;j<k;++j){
                if (i & (1<<j)){
                    int nn=i^(1<<j);
                    int upto=dp[nn];
                    if (upto>=n) continue;
                    int ex=close[upto][j];
                    if (ex>=0){
                        int xx=ex+mid;
                        dp[i]=min(dp[i],xx);
                    }
                }
            }
        }

        if (dp[(1<<k)-1]<=n){
            // works
            mn=mid;
        }
        else mx=mid-1;

    }

    cout<<mn<<endl;


    return 0;
}

