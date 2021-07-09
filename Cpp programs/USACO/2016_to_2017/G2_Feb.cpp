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

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("nocross.in","r",stdin);
    freopen("nocross.out","w",stdout);


    int maxn=1010;
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    int arr2[n];
    for (int i=0;i<n;++i){
        cin>>arr2[i];
    }

    int dp[n+1][n+1];
    for (int i=0;i<n+1;++i){
        for (int j=0;j<n+1;++j){
            dp[i][j]=0;
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<n+1;++j) {
            if (abs(arr[i - 1] - arr2[j - 1]) < 5) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    cout<<dp[n][n]<<endl;



    return 0;
}
