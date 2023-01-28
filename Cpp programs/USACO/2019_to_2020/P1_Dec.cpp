#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vivi=vector<vi>;
using str = string;

const ll inf = 2 * 1e18;
vivi dp(305,vi(305));
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("pieaters.in","r",stdin);
    freopen("pieaters.out","w",stdout);

    int n,m;cin>>n>>m;

    vector<pair<int,pii>> a(m);

    for (int i=0;i<m;++i) {
        cin >> a[i].f >> a[i].s.f >> a[i].s.s;
    }
    // answer on range of the pies
    for (auto k:a) dp[k.s.f][k.s.s]=k.f;

    vector<vivi> x(305,vivi(305,vi(305)));
    for (auto i:a){
        int left=i.s.f;int right=i.s.s;
        for (int j=left;j<=right;++j){
            x[j][left][right]=max(x[j][left][right],i.f);
        }
    }
    for (int len=1;len<=n;++len){
        for (int i=1;i<=n;++i){
            int j=i+len-1;
            if (j>n) break;
            for (int k=i;k<=j;++k){
                x[k][i][j]=max(x[k][i][j],max(x[k][i+1][j],x[k][i][j-1]));
            }
        }
    }

    for (int i=n;i>=1;--i){
        for (int j=i;j<=n;++j){
            dp[i][j]=max(dp[i][j],max(dp[i+1][j],dp[i][j-1]));
            for (int k=i;k<=j;++k){
                dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+x[k][i][j]);
            }

        }
    }

    /*for (int i=n-1;i>=0;--i){
        for (int j=i;j<n;++j){
            for (auto x:a){

                if (!(x.s.f>j || x.s.s<i)){
                    int top=min(j,x.s.s);
                    int bot=max(i,x.s.f);
//                    cout<<i<<" "<<j<<" "<<x.s.f<<" "<<x.s.s<<" "<<bot<<" "<<top<<endl;
                    int c=0;
                    int d=0;
                    if (top!=j) c=dp[top+1][j];
                    if (bot!=i) d=dp[i][bot-1];
                    dp[i][j]=max(dp[i][j],c+d+x.f);
                }
            }
        }
    }
    for (int i=0;i<n;++i){
        if (i!=0) dp[i]=max(dp[i],dp[i-1]);

        for (auto j:a){
            if (j.s.f<=i && i<=j.s.s){
                int c=0;
                if (j.s.f>0) c=dp[j.s.f-1];

                dp[i]=max(dp[i],c+j.f);
            }
        }
    }*/

    cout<<dp[1][n]<<endl;



    return 0;
}

