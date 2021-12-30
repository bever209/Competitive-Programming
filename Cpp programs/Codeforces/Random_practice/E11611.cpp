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

    int tc;cin>>tc;
    while (tc--){
        int n,k;cin>>n>>k;
        int arr[k];
        for (int i=0;i<k;++i){
            cin>>arr[i];--arr[i];
        }
        vector<vi> adj(n);
        for (int i=0;i<n-1;++i){
            int a,b;cin>>a>>b;--a;--b;
            adj[a].pb(b);adj[b].pb(a);
        }
        queue<int> q;
        vi dist(n,1e9);
        for (int i:arr) {q.push(i);dist[i]=0;}
        while (!q.empty()){
            int x=q.front();
            q.pop();
            for (int i:adj[x]){
                if (dist[i]==1e9){
                    dist[i]=dist[x]+1;
                    q.push(i);
                }
            }
        }
        queue<int> a;
        a.push(0);
        vi dist2(n,1e9);dist2[0]=0;
        while (!a.empty()){
            int x=a.front();a.pop();
            for (int i:adj[x]){
                if (dist2[i]==1e9){
                    dist2[i]=dist2[x]+1;
                    a.push(i);
                }
            }
        }


        bool check=false;
        for (int i=0;i<n;++i){
            if (adj[i].size()==1 && i!=0){
                if(dist2[i]<dist[i]) check=true;
            }
        }
        if (check){
            cout<<"yes\n";
        }
        else cout<<"no\n";
    }


    return 0;
}

