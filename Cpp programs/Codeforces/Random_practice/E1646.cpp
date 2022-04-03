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

    int n,m;cin>>n>>m;

    vi x(21); // the number of different numbers that appears in a a x m grid ->x[a]
    vector<bool> in(21*m+5);
    for (int i=1;i<21;++i){
        for (int j=1;j<=m;++j){
            if (!in[i*j]){
                x[i]++;in[i*j]=true;
            }
        }
        x[i]+=x[i-1];
    }
    ll ans=1;
    vector<bool> vis(n+1);vis[0]=vis[1]=true;
    for (ll i=2;i<=n;++i){
        if (!vis[i]){
            ll j=i;int c=0;
            while (j<=n){
                vis[j]=true;++c;
                j=j*i;
            }
            ans=ans+x[c];
        }
    }
    cout<<ans<<endl;


    return 0;
}

