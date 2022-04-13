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

    int n, k;
    cin >> n >> k;

    vector<pii> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i].f >> arr[i].s;

    vector<vector<bool>> dp(n + 1, vector<bool>(k));
    dp[0][0]=true;

    ll tot = 0;
    for (auto i:arr) tot+=(i.f+i.s);

    for (int i = 1; i <= n; ++i) {
        int a = arr[i - 1].f;
        int b = arr[i - 1].s;
        for (int j=0;j<k;++j){
            dp[i][j]=dp[i-1][(j-a%k+k)%k];
            for (int l=0;l<=min(k-1,a);++l){
                if ((a-l+k)%k + b >=k){
                    dp[i][j]=dp[i][j]|dp[i-1][(j-l+k)%k];
                }
            }
        }
    }
    ll a=0;
    for (int i=0;i<k;++i){
        if (dp[n][i]) a=max(a,(tot-i)/k);
    }
    cout<<a<<endl;


    return 0;
}

