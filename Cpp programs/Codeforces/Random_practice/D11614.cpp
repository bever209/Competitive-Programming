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

#define int ll
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    vi count(5*1e6+10);
    for (int i:arr){
        count[i]++;
    }
    for (int i=1;i<count.size();++i){
        for (int j=2;j*i<count.size();++j){
            count[i]+=count[i*j];
        }
    }
    //cout<<count[1]<<endl;
    vi dp(5*1e6+10);
    for (int i=0;i<count.size();++i){
        dp[i]=i*count[i];
    }
    for (int i=dp.size()-1;i>=1;--i){
        for (int j=1;j*i<dp.size();++j){
            dp[i]=max(dp[i],dp[i*j]+i*(count[i]-count[i*j]));
        }
    }

    cout<<dp[1];


    return 0;
}

