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

    string a,b;cin>>a>>b;
    int n=a.size(),m=b.size();

    vector<vector<vi>> dp(205,vector<vi>(205,vi(405,500)));
    vector<vector<vector<pair<pii,char>>>> val(205,vector<vector<pair<pii,char>>>(205,vector<pair<pii,char>>(405)));
//    dp[i][j][k] means minimum length necessary if we have processed first i and first j from the first two strings respectively
//    and the balance is currently k


    dp[0][0][0]=0;
    for (int i=0;i<=n;++i){
        for (int j=0;j<=m;++j){
            for (int k=0;k<=400;++k){
                int x=i;int y=j;
                if (i<n && a[i]=='(') ++x;
                if (j<m && b[j]=='(') ++y;
                if (dp[x][y][k+1]>dp[i][j][k]+1) {
                    dp[x][y][k + 1] = min(dp[x][y][k + 1], dp[i][j][k] + 1);
                    val[x][y][k+1]={{i,j},'('};
                }
                if (k>0) {
                    x = i;
                    y = j;
                    if (i<n && a[i] == ')') ++x;
                    if (j<m && b[j] == ')') ++y;
                    if (dp[x][y][k - 1] > dp[i][j][k] + 1) {
                        dp[x][y][k - 1] = min(dp[x][y][k -1], dp[i][j][k] + 1);
                        val[x][y][k-1]={{i,j},')'};
                    }
                }
            }
        }
    }
    int ind1=n;int ind2=m;int bal=0;str ans="";
    for (int i=0;i<=400;++i){
        if (bal+dp[n][m][bal]>i+dp[n][m][i]) bal=i;
    }
    for (int i=0;i<bal;++i) ans+=')';

    while (ind1>0 || ind2>0 ||bal>0){
//        cout<<ind1<<" "<<ind2<<" "<<bal<<endl;
        auto xx=val[ind1][ind2][bal];
        char aa=xx.s;

        if (aa==')') ++bal;
        else --bal;
        ans=aa+ans;
        ind1=xx.f.f;ind2=xx.f.s;

    }

    cout<<ans<<endl;



    return 0;
}