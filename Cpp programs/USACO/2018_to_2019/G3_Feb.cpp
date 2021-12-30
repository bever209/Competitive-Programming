#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using str=string;

const ll inf=2*1e18;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("taming.in","r",stdin);
    freopen("taming.out","w",stdout);

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<vi> dp(n+1,vi(n+1,1e4));
    dp[0][0]=0;
    dp[1][1]=1;
    if (arr[0]==0){
        dp[1][1]=0;
    }
    for (int i=1;i<n;++i){
        dp[i+1][1]=dp[i][1]+1;
        if (arr[i]==i){
            dp[1+i][1]--;
        }
    }
    for (int j=1;j<n;++j) {
        for (int i = 1; i <= n; ++i) {

            int num = 0;
            int c = 0;
            for (int k = i + 1; k <= n; ++k) {
                ++num;
                if (arr[k-1] == c) {
                    --num;
                }
                ++c;
                dp[k][j + 1] = min(dp[k][j + 1], dp[i][j] + num);
            }
        }
    }
    for (int i=1;i<=n;++i){
        cout<<dp[n][i]<<endl;
    }


    return 0;
}

