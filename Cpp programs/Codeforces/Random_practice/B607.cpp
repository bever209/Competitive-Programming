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

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vector<vi> dp(1+n, vi(1+n, 1e9));
    vector<vector<bool>> pal(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        pal[i][i] = true;dp[i][i]=1;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == arr[i + 1]) {
            pal[i][i + 1] = true;dp[i][i+1]=1;
        }
        else{
            dp[i][i+1]=2;
        }

    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            if (arr[i] == arr[j] && pal[i + 1][j - 1]) {
                pal[i][j] = true;
            }
        }
    }
    for (int i=0;i<=n;++i){
        for (int j=0;j<i;++j){
            dp[i][j]=0;
        }
    }
    for (int len=3;len<=n;++len){
        for (int i=0;i+len-1<n;++i){
            int j=i+len-1;

            for (int k=i;k<=j;++k){
                if (pal[i][k]){
                    dp[i][j]=min(dp[i][j],dp[k+1][j]+1);
                }
                if (arr[i]==arr[k] && k>i+1){
                    dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j]);
                }
            }
        }
    }
   /* for (int i=0;i<=n;++i){
        for (int j=0;j<=n;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[0][n-1]<<endl;


    return 0;
}

