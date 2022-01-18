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

int max_sum(vi x){
    vi a(x.size());
    a[0]=x[0];
    for (int i=1;i<x.size();++i){
        a[i]=a[i-1]+x[i];
    }
    int mn=0;
    int ans=0;
    for (int & i : a){
        ans=max(ans,i-mn);
        mn=min(mn,i);
    }
    return ans;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    
    while (tc--){
        int n,k;cin>>n>>k;
        int numones=0;
        string s;cin>>s;
        int ans=1e9;
        vi t;
        for (char i:s){
            if (i=='1') {
                t.pb(1);
                ++numones;
            }
            else t.pb(-1);
        }
        for (int i=0;i<k;++i){
            vi x;
            for (int j=i;j<n;j+=k){
                x.pb(t[j]);
            }
            int num= max_sum(x);
            ans=min(ans,numones-num);
        }
        cout<<ans<<endl;
    }


    return 0;
}

