#include <bits/stdc++.h>
// how does this work????
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

    int n;cin>>n;
    int a[n];
    for (int i=0;i<n;++i){
        cin>>a[i];--a[i];
    }

    vi l(n,n+5);vi r(n);vi c(n);
    for (int i=0;i<n;++i){
        r[a[i]]=max(r[a[i]],i);
        l[a[i]]=min(l[a[i]],i);++c[a[i]];
    }

    vi dp(n+1); // maximum we can keep
    vi cc(n);
    for (int i=n-1;i>=0;--i){
        cc[a[i]]++;
        int x=a[i];
        dp[i]=dp[i+1];

        if (l[x]==i){
            dp[i]=max(dp[i],c[x]+dp[r[x]+1]);
        }
        else dp[i]=max(dp[i],cc[x]);
    }

    cout<<n-dp[0]<<endl;

    return 0;
}

