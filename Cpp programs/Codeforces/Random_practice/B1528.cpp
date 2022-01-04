
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
const ll mod=998244353;

vi findDivisors(int n)
{

    // Array to store the count
    // of divisors
    vi div(n+1);

    // For every number from 1 to n
    for (int i = 1; i <= n; i++) {

        // Increase divisors count for
        // every number divisible by i
        for (int j = 1; j * i <= n; j++)
            div[i * j]++;
    }
    return div;
}


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;

    vi dp(n+1);
    dp[0]=1;dp[1]=1;
    ll rsum=2;
    vi x= findDivisors(1e6+5);
    for (int i=2;i<dp.size();++i){
        int num= x[i]-1;
        dp[i]=rsum+num;
        rsum=(rsum+dp[i])%mod;
    }
    cout<<dp[n];


    return 0;
}

