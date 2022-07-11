#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;

int main() {

#define int ll
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;

    pair<pii,ll> arr[m];
    for (int i=0;i<m;++i) cin>>arr[i].f.f>>arr[i].f.s>>arr[i].s;


    map<int,int> mm;
    set<int> s;
    for (int i=0;i<m;++i){
        s.insert(arr[i].f.f);s.insert(arr[i].f.s);
    }
    int c=0;
    for (int i:s){
        mm[i]=c;++c;
    }

    for (int i=0;i<m;++i) arr[i].f.f=mm[arr[i].f.f],arr[i].f.s=mm[arr[i].f.s];

    // finished coordinate compressing
    vi dp(2*m+5,-1e18);
    sort(arr,arr+n);

    vi over(2*m+5);
    for (int i=0;i<m;++i){
        over[arr[i].f.f]+=arr[i].s;
        over[arr[i].f.s+1]-=arr[i].s;
    }
    for (int i=1;i<over.size();++i) over[i]=over[i-1]+over[i];

    vi nxt(2*m+5,-1);int ind=0;
    for (int i=0;i<nxt.size();++i){
        if (ind==m) break;
        while (ind<m && arr[ind].f.f<=i) ++ind;
        if (ind!=m) nxt[i]=ind;
    }

    for (int i=2*m+2-1;i>=0;--i){
        dp[i]=max(dp[i],dp[i+1]);
        if (nxt[i]!=-1){
            dp[i]=max(dp[i],over[i]+dp[nxt[i]]);
        }
    }
//    for (auto i:arr) cout<<i.f.f<<" "<<i.f.s<<endl;
    int ans=0;
    for (int i:dp) ans=max(ans,i);

    cout<<ans<<endl;
// issue, dp call could count some segments twice, one during over and another in dp[nxt[i]] if the segment runs past nxt[i]
// need to fix
    return 0;
}

