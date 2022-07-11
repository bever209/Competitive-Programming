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
vector<vi> adj;
pii dp[(int)2e5+5][2];// node and then if we dont take = 0 or take = 1
// size and then weight

void dfs(int node,int par){
    dp[node][1].f+=1;
    dp[node][1].s+=adj[node].size();
    for (int i:adj[node]){
        if (i!=par){
            dfs(i,node);
            pii x=dp[i][0];
            pii y=dp[i][1];


            dp[node][1].f+=x.f;dp[node][1].s+=x.s;

            if (y.f<x.f) swap(x,y);
            else if (x.f==y.f && x.s<y.s) swap(x,y);

            dp[node][0].f+=y.f;dp[node][0].s+=y.s;
        }
    }
}
vi ans;
void build(int node,int par, int take){
    if (take==0){
        ans[node]=1;
    }
    else{
        ans[node]=adj[node].size();
    }
    for (int i:adj[node]){
        if (i!=par){
            pii x=dp[i][0];
            pii y=dp[i][1];
            if (take==1 || y.f<x.f || x.f==y.f && x.s<y.s){
                build(i,node,0);
            }
            else{
                build(i,node,1);
            }

        }
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    adj.resize(n);ans.resize(n);

    for (int i=0;i<n-1;++i){
        int a,b;cin>>a>>b;--a;--b;adj[a].pb(b);adj[b].pb(a);
    }
    if (n==2){
        cout<<2<<" "<<2<<endl;
        cout<<"1 1";return 0;
    }
    dfs(0,-1);
//    for (int i=0;i<n;++i) for (int j=0;j<2;++j) cout<<dp[i][j].f<<" dp "<<dp[i][j].s<<endl;


    if (dp[0][0].f>dp[0][1].f || dp[0][0].f==dp[0][1].f && dp[0][0].s<dp[0][1].s){
        build(0,-1,0);
    }
    else{
        build(0,-1,1);

    }
    int a=0;
    for (int i=0;i<n;++i){
        ll x=0;
        for (int j:adj[i]) x+=ans[j];
        if (x==ans[i]) ++a;
    }
    ll sum=0;
    for (int i:ans) sum+=i;

    cout<<a<<" "<<sum<<endl;
    for (int i:ans) cout<<i<<" ";




    return 0;
}

