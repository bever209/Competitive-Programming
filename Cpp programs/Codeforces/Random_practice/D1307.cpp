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
vi dist0;
vi distn;
vector<vi> adj;
void bfs0(int node=0){
    queue<int> q;
    q.push(node);
    while (!q.empty()){
        int n=q.front();q.pop();
        for (int t:adj[n]){
            if (dist0[t]==1e9){
                dist0[t]=dist0[n]+1;
                q.push(t);
            }
        }
    }
}
void bfsn(int node){
    queue<int> q;
    q.push(node);
    while (!q.empty()){
        int n=q.front();q.pop();
        for (int t:adj[n]){
            if (distn[t]==1e9){
                distn[t]=distn[n]+1;
                q.push(t);
            }
        }
    }
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;cin>>n>>m>>k;
    vi special;
    for (int i=0;i<k;++i){
        int a;cin>>a;--a;special.pb(a);
    }

    adj.resize(n);
    for (int i=0;i<m;++i){
        int a,b;cin>>a>>b;--a;--b;
        adj[a].pb(b);adj[b].pb(a);
    }
    dist0.resize(n,1e9);
    distn.resize(n,1e9);
    dist0[0]=0;
    distn[n-1]=0;
    bfs0(0);
    bfsn(n-1);

    vector<pii> opt;
    for (int i:special){
        opt.pb({dist0[i]-distn[i],i});
    }
    sort(opt.begin(),opt.end());
    int best=0;
    int mx=-1e9;
    for (pii j:opt){
        int i=j.s;
        best=max(best,mx+distn[i]);
        mx=max(mx,dist0[i]);
    }

    cout<<min(best+1,dist0[n-1])<<endl;

// final part basically just copied from editorial
    return 0;
}

