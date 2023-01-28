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

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    vector<vi> dp(n+1,vi(n+1));
    for (int len=1;len<=n;++len){
        for (int s=0;s+len-1<n;++s){
            int end=s+len-1;
            dp[s][end]=n+5;
            if (len==1) dp[s][end]=1;
            else{
                for (int j=s;j<end;++j) {
                    // note that the final move does not disjointly split: ISSUE
                    if (arr[s] == arr[end]) {
                         dp[s][end] = min(dp[s][end], dp[s][j]+dp[j+1][end]-1);
                    }
                    else dp[s][end] = min(dp[s][end], dp[s][j]+dp[j+1][end]);
                }

            }
        }
    }
    cout<<dp[0][n-1]<<endl;

   /* for (int i=0;i<=n;++i){
        for (int j=0;j<=n;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
*/

    return 0;
}

