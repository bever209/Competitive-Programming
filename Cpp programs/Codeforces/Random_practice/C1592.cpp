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
vi vals;vi arr;vector<bool> chose;
int c;
void dfs(int node,int par,int goal){
    int x=0;
    for (int i:adj[node]){
        if (i!=par){
            dfs(i,node,goal);
            x^=vals[i];
            chose[node]=chose[node]|chose[i];
        }
    }
    x^=arr[node];
    vals[node]=x;
    if (x==goal && !chose[node]) {
        ++c;chose[node]=true;
    }
    else if (x==0 && chose[node]){
        ++c;
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n,k;cin>>n>>k;
        arr.clear();arr.resize(n);
        for (int i=0;i<n;++i) cin>>arr[i];
        adj.clear();chose.clear();
        adj.resize(n);c=0;vals.clear();vals.resize(n);chose.resize(n);
        for(int i=0;i<n-1;++i){
            int a,b;cin>>a>>b;--a;--b;
            adj[a].pb(b);adj[b].pb(a);
        }
        int x=0;
        for (int i:arr) x^=i;
        if (x==0){
            cout<<"YES"<<endl;
        }
        else{
            if (k-1==1){
                cout<<"NO"<<endl;continue;
            }
            dfs(0,-1,x);
            if (c>1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }


    return 0;
}

