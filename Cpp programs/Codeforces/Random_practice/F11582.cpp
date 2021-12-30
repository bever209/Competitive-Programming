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

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    vi dp(520,1e9);dp[0]=0;int c=520;
    for (int i=0;i<n;++i) for (int j=0;j<c;++j){
        if (dp[j]<arr[i]){
            dp[j^arr[i]]=min(dp[j^arr[i]],arr[i]);
        }
    }
    int ans=0;vi x;
    for (int i=0;i<c;++i){
        if (dp[i]!=1e9){
            x.pb(i);++ans;
        }
    }
    cout<<ans<<'\n';
    for (int i:x) cout<<i<<" ";


    return 0;
}

