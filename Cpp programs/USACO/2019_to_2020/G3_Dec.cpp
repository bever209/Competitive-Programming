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

    freopen("cowmbat.in","r",stdin);
    freopen("cowmbat.out","w",stdout);

    int n,m,k;cin>>n>>m>>k;
    string s;cin>>s;
    int matrix[m][m];
    for (int i=0;i<m;++i){
        for (int j=0;j<m;++j){
            cin>>matrix[i][j];
        }
    }
    for (int c=0;c<m;++c){
        for (int a=0;a<m;++a){
            for (int b=0;b<m;++b){
                matrix[a][b]=min(matrix[a][b],matrix[a][c]+matrix[c][b]);
            }
        }
    }
    vector<vi> change(n+1,vi(m));
    for (int c=0;c<m;++c){
        for (int i=1;i<=n;++i){
            change[i][c]=change[i-1][c]+matrix[s[i-1]-'a'][c];
        }
    }

    vector<vi> dp(n+1,vi (m,1e8)); // prefix length, final char
    for (int i=1;i<=n;++i){
        for (int c=0;c<m;++c) {
            dp[i][c] = min(dp[i - 1][c]+change[i][c]-change[i-1][c], dp[i][c]);
            if (i - k > 0) {
                for (int j = 0; j < m; ++j) {
                    dp[i][c] = min(dp[i][c], dp[i - k][j] + change[i][c] - change[i - k][c]);
                }
            }
            else if (i-k==0){
                for (int j = 0; j < m; ++j) {
                    dp[i][c] = min(dp[i][c], change[i][c] - change[i - k][c]);
                }
            }
        }
    }
    int ans=1e9;
    for (int i=0;i<m;++i){
        ans=min(ans,dp[n][i]);
    }
    cout<<ans<<endl;




    return 0;
}

