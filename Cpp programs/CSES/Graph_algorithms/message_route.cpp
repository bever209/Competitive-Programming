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

int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for (int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        --a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int parent[n];
    parent[0]=-1;
    vi dist(n,1e6);
    queue<int> q;
    q.push(0);
    dist[0]=0;
    while (!q.empty()){
        int node=q.front();
        q.pop();
        for (int i:adj[node]){
            if (dist[i]==1e6){
                q.push(i);
                dist[i]=dist[node]+1;
                parent[i]=node;
            }
        }
    }
    if (dist[n-1]==1e6){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dist[n-1]+1<<endl;
        int num=parent[n-1];
        vi ans;
        while (num>=0){
            ans.pb(num);
            num=parent[num];
        }
        reverse(ans.begin(),ans.end());

        for (int i:ans){
            cout<<i+1<<" ";
        }
        cout<<n<<" ";
        cout<<endl;
    }


    return 0;
}