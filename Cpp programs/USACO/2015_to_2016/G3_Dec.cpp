#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int mx=1e9;
int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("drean.in","r",stdin);
    freopen("dream.out","w",stdout);



    int n,m;
    cin>>n>>m;
    int arr[n+2][m+2];
    pii dp[n+2][m+2];
    for (int i=0;i<n+2;++i){
        for (int j=0;j<m+2;++j){
            arr[i][j]=0;dp[i][j]={mx,mx};
        }
    }
    
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin>>arr[i+1][j+1];
        }
    }
    if (arr[1][1]!=0){
        dp[1][1]={0,mx};
        if (arr[1][1]==2){
            dp[1][1]={0,0};
        }
    }

    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (!(i==1 && j==1)){
                if (arr[i][j]==0){
                    dp[i][j]={0,0};continue;
                }
               

            }
        }
    }


    cout<<dp[n][m]<<endl;
    

    


    return 0;
}