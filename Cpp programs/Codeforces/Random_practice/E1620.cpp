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
    int ind=0;vector<vi> p(5e5+5);
    int q;cin>>q;
    while (q--){
        int t;cin>>t;

        if (t==1){
            int a;cin>>a;
            p[a].pb(ind);++ind;
        }
        else{
            int a,b;cin>>a>>b;
            if (a==b) continue;
            if (p[a].size()>=p[b].size()) swap(p[a],p[b]);

            for (int i:p[a]) p[b].pb(i);
            p[a].clear();
        }


    }
    vi ans(ind);
    for (int i=0;i<p.size();++i){
        for (int j:p[i]){
            ans[j]=i;
        }
    }
    for (int i:ans) cout<<i<<" ";
    return 0;
}

