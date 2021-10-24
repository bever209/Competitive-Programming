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
vi num;vi good;vi p;vi h;

void dfs(int node,int parent){
    num[node]=p[node];
    for (int i:adj[node]){
        if (i!=parent){
            dfs(i,node);
            num[node]+=num[i];
        }
    }
}
bool dfs2(int node,int parent){
    bool check=true;
    for (int i:adj[node]){
        if (i!=parent){
            check=check && dfs2(i,node);
            if (good[node]<good[i]){
                check=false;break;
            }
        }
    }
    return check;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        adj.clear();num.clear();good.clear();p.clear();h.clear();

        int n,m;
        cin>>n>>m;

        p.resize(n);h.resize(n);
        for (int i=0;i<n;++i){
            cin>>p[i];
        }
        for (int i=0;i<n;++i){
            cin>>h[i];
        }
        adj.resize(n);
        for (int i=0;i<n-1;++i){
            int a,b;cin>>a>>b;--a;--b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        num.resize(n);
        dfs(0,-1);
        good.resize(n);
        for (int i=0;i<n;++i){
            good[i]=h[i]+num[i];
        }
        bool check1=true;bool check2=true;bool check3=true;
        for (int i=0;i<n;++i){
            if (good[i]%2==1){
                check1=false;break;
            }
            int x=good[i]/2;
            if (!(x>=0 && x<=num[i])){
                check2=false;break;
            }
        }

        check3=dfs2(0,-1);
        // cout<<check1<<check2<<check3<<endl;
        if (check1 && check2 && check3){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }



    }


    return 0;
}
