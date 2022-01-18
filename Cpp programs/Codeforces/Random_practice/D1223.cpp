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
vi first(3e5+5);
vi last(5+3e5);

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        int arr[n];for (int i=0;i<=n+1;++i){
            first[i]=1e9;last[i]=-1;
        }

        for (int i=0;i<n;++i) {
            cin >> arr[i];
            first[arr[i]]=min(first[arr[i]],i);
            last[arr[i]]=max(last[arr[i]],i);
        }



        vi x;
        for (int i:arr) x.pb(i);
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        int mx=0;
        vi dp(x.size());
        for (int i=0;i<dp.size();++i){
            if (i==0) dp[i]=1;
            else{
                if (first[x[i]]>last[x[i-1]]){
                    dp[i]=dp[i-1]+1;
                }
                else dp[i]=1;
            }
            mx=max(mx,dp[i]);
        }


        int t=x.size();
        cout<<t-mx<<endl;
    }


    return 0;
}

