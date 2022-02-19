#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;

int main() {
#define int ll

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    pii arr[n];
    for (int i=0;i<n;++i) cin>>arr[i].f>>arr[i].s;
    sort(arr,arr+n);

    int mx=arr[0].f+arr[0].s;
    int ans=0;
    vi dp(n); // nondecreasing
    for (auto i:arr) ans+=i.s;
    for (int i=1;i<n;++i){
        dp[i]=(dp[i-1]+max((ll)0,arr[i].f-mx));
        mx=max(mx,arr[i].f+arr[i].s);
    }
    cout<<dp[n-1]+ans<<endl;


    return 0;
}

