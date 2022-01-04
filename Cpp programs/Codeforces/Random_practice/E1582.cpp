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

vi pref;
ll query(int l,int r){
    if (l==0) return pref[r];
    else return pref[r]-pref[l-1];
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];

        pref.resize(n);
        pref[0]=arr[0];
        for (int i=1;i<n;++i) pref[i]=pref[i-1]+arr[i];

        // maybe #define int ll
        vector<vi> dp(n+1,vi(500,-1)); // neg, then impossible

        for (int i=n-1;i>=0;--i){
           //cout<<"i "<<i<<endl;
            for (int j=1;j<490;++j){
                dp[i][j]=dp[i+1][j];
                if (i+j-1<n) {
                    ll x = query(i, i + j - 1);
                    if (query(i, i + j - 1) < dp[i + j][j - 1] || j==1) {
                        dp[i][j] = max(dp[i][j], x);
                    }
                }
                else break;
            }
        }

        int ans=0;
        for (int i=499;i>=0;--i){
            if (dp[0][i]>0){
                ans=i;break;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}

