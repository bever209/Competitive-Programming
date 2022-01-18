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


    int a,b,c;cin>>a>>b>>c;
    int n=a+b+c;

    vi pos(n);
    for (int i=0;i<a;++i){
        int q;cin>>q;--q;pos[q]=0;
    }
    for (int i=0;i<b;++i){
        int q;cin>>q;--q;pos[q]=1;
    }
    for (int i=0;i<c;++i) {
        int q;cin>>q;--q;pos[q]=2;
    }

    vector<vi> dp(n,vi(3,1e9));
    for (int i=0;i<3;++i){
        if (pos[0]==i){
            dp[0][i]=0;
        }
        else dp[0][i]=1;
    }

    for (int i=1;i<n;++i){
        for (int j=0;j<3;++j){
            int add=1;
            if (pos[i]==j) add=0;
            for (int k=j;k>=0;--k){
                dp[i][j]=min(dp[i][j],add+dp[i-1][k]);
            }
        }
    }
    int ans=1e9;
    for (int i=0;i<3;++i) ans=min(ans,dp[n-1][i]);

    cout<<ans<<endl;

    return 0;
}

