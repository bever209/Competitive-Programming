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

    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);

    int n,k;cin>>n>>k;int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    vi dp(n,0);
    for (int i=0;i<n;++i){
        int mx=-1;
        for (int j=i;j>=0 && i-j+1<=k;--j) {
            mx = max(mx, arr[j]);
            if (j - 1 == -1) {
                dp[i] = max(dp[i], mx * (i - j + 1));
            } else {
                dp[i] = max(dp[i], dp[j - 1] + mx * (i - j + 1));
            }
        }
    }
    cout<<dp[n-1];

    return 0;
}

