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
vector<ll> cost;vi initial;vi final;vector<vi> adj;vi type1;vi type2;

void dfs(int node=0,int par=-1){
    if (initial[node]==0 && final[node]==1){
        type1[node]++;
    }
    else if (initial[node]==1 && final[node]==0){
        ++type2[node];
    }

    for (int i:adj[node]){
        if (i!=par){
            cost[i]=min(cost[i],cost[node]);
            dfs(i,node);
            type1[node]+=type1[i];
            type2[node]+=type2[i];
        }
    }
}
ll ans=0;
void dfs2(int node=0,int par=-1){
    type1[node]=0;type2[node]=0;
    if (initial[node]==0 && final[node]==1){
        type1[node]++;
    }
    else if (initial[node]==1 && final[node]==0){
        ++type2[node];
    }
    for (int i:adj[node]){
        if (i!=par){
            dfs2(i,node);
            type1[node]+=type1[i];
            type2[node]+=type2[i];
        }
    }
    int x=min(type1[node],type2[node]);
    ll num=cost[node]*x;
    ans+=num;
    type1[node]-=x;type2[node]-=x;

}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    cost.resize(n);
    initial.resize(n);
    final.resize(n);
    type1.resize(n);
    type2.resize(n);
    for (int i=0;i<n;++i){
        int a,b,c;cin>>a>>b>>c;
        cost[i]=a;initial[i]=b;final[i]=c;
    }
    adj.resize(n);
    for (int i=0;i<n-1;++i){
        int a,b;cin>>a>>b;
        --a;--b;
        adj[a].pb(b);adj[b].pb(a);
    }
    dfs();
    int t1=0;int t2=0;
    for (int i=0;i<n;++i){
        if (initial[i]==0 && final[i]==1){
            ++t1;
        }
        else if (initial[i]==1 && final[i]==0){
            ++t2;
        }
    }
    if (t1!=t2){
        cout<<-1;return 0;
    }
    dfs2();
    cout<<ans*2;


    return 0;
}

