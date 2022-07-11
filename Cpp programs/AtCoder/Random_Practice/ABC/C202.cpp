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
using str=string;

const ll inf=2*1e18;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vi a(n);vi b(n);vi c(n);
    for (int i=0;i<n;++i){
        cin>>a[i];
    }
    for (int i=0;i<n;++i){
        cin>>b[i];
    }
    for (int i=0;i<n;++i){
        cin>>c[i];
    }
    vector<vector<int>> locb(n+1);
    for (int i=0;i<n;++i){
        int x=b[i];
        int ind=i+1;
        locb[x].pb(ind);
    }
    vector<vector<int>> locc(n+1);
    for (int i=0;i<n;++i){
        int x=c[i];
        int ind=1+i;
        locc[x].pb(ind);
    }
    ll ans=0;

    vector<ll> mem(n+5,-1);
    for (int i=0;i<n;++i){
        int x=a[i];
        if (mem[x]<0) {
            ll num=0;
            for (int j:locb[x]) {
                num += (ll) locc[j].size();
            }
            mem[x]=num;
        }
        ans+=mem[x];
    }
    cout<<ans<<endl;

    return 0;
}

