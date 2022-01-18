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

ll g(ll a,ll b){
    if (a==0) return b;
    if (b==0) return a;
    if (a>b) return g(a%b,b);
    else return g(a,b%a);
}

const ll inf = 2 * 1e18;
int n;vector<ll> arr;vector<vi> adj;
ll ans=0;
const int mod=1e9+7;

void dfs(int node,int par,map<ll,int> rec){
    map<ll,int> x;
    for (auto i:rec){
        ll num=g(i.f,arr[node]);
        if (x.count(num)) x[num]+=i.s;
        else x.insert({num,i.s});
        ans=(ans+num*i.s)%mod;
    }
    if (x.count(arr[node])) x[arr[node]]+=1;
    else x[arr[node]]=1;
    ans=(ans+arr[node])%mod;

    for (int i:adj[node]){
        if (i!=par){
            dfs(i,node,x);
        }
    }
}


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    arr.resize(n);
    for (int i=0;i<n;++i) cin>>arr[i];
    adj.resize(n);

    for (int i=0;i<n-1;++i){
        int a,b;cin>>a>>b;--a;--b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1,{});

    cout<<ans<<"\n";



    return 0;
}

