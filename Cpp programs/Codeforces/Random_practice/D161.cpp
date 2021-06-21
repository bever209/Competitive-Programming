#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n,k;
vector<vector<int>> arr;
vector<vector<int>> dp;

ll sol;
void dfs(int c, int p) {
    dp[c][0] = 1;
    for (int i : arr[c]) {
        if (i != p) {
            dfs(i, c);
            for (int j = 0; j < k; ++j) {
                sol += dp[i][j] * dp[c][k - (j + 1)];
            }
            for (int j = 0; j < k; ++j) {
                dp[c][j + 1] += dp[i][j];
            }
        }
    }
}
int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin>>n>>k;
    arr.resize(n);
    dp.resize(n);
    for (int i=0;i<n;++i){
        dp[i].resize(k+2);
    }
    for (int i=0;i<n-1;++i){
        int a,b;
        cin>>a>>b;
        --a;--b;
        arr[a].pb(b);
        arr[b].pb(a);
    }
    dfs(0,0);
    cout<<sol<<endl;
    return 0;

}