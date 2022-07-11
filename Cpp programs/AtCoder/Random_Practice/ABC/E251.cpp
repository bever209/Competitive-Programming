#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    ll arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];
    if (n==2){
        cout<<min(arr[0],arr[1])<<endl;return 0;
    }

    ll ans=1e18;

    ll a1=arr[0];
    vector<vi> dp(n,vi(2));
    dp[1][1]=arr[1];
    dp[1][0]=0;
    for (int i=2;i<n;++i){
        dp[i][1]=min(dp[i-1][0],dp[i-1][1])+arr[i];
        dp[i][0]=dp[i-1][1];
    }
    a1+=min(dp[n-1][0],dp[n-1][1]);

    // above is take a1

    // below is dont take a1, so you must take a2 and an

    vector<vi> dp2(n,vi(2));
    ll a2=arr[1];
    for (int i=2;i<n;++i){
        dp2[i][1]=min(dp2[i-1][0],dp2[i-1][1])+arr[i];
        dp2[i][0]=dp2[i-1][1];
    }
    a2+=dp2[n-1][1];

    cout<<min(a1,a2);


    return 0;
}

