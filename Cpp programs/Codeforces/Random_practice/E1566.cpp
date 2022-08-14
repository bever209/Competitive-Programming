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
using vivi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;
vector<vi> adj;vi bud;vi leaf;

void dfs(int node,int par){
    if (adj[node].size()==1 && node!=0){
        leaf[node]=true;return;
    }
    for (int i:adj[node]){
        if (i!=par){
            dfs(i,node);
        }
    }
    int b=0;int l=0;
    for (int i:adj[node]){
        if (i==par) continue;
        if (bud[i]) ++b;
        if (leaf[i]) ++l;
    }
    if (node==0) return;
    if (b==adj[node].size()-1){
        leaf[node]=true;return;
    }
    if (l+b==adj[node].size()-1){
        bud[node]=true;
    }

}
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        adj.clear();
        adj.resize(n);
        for (int i=0;i<n-1;++i){
            int a,b;cin>>a>>b;--a;--b;
            adj[a].pb(b);adj[b].pb(a);
        }
        leaf.clear();bud.clear();
        leaf.resize(n);bud.resize(n);
        dfs(0,-1);
//        for (int i:leaf) cout<<i<<" ";cout<<endl;
//        for (int i:bud) cout<<i<<" ";cout<<endl;
        int nl=0;
        for (int i:leaf) nl+=i;
        int nb=0;
        for (int i:bud) nb+=i;

        bool check=true;
        for (int i:adj[0]){
            check=check & (bud[i]==1);
        }
        if (check){
            cout<<nl-nb+1<<endl;
        }
        else{
            cout<<nl-nb<<endl;
        }

    }


    return 0;
}