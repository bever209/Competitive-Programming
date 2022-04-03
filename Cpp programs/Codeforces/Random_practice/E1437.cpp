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
int find_lis(vector<int> a) {
    vector<int> dp;
    for (int i : a) {
        int pos = upper_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == dp.size()) {
            // we can have a new, longer increasing subsequence!
            dp.push_back(i);
        } else {
            // oh ok, at least we can make the ending element smaller
            dp[pos] = i;
        }
    }
    return dp.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int arr[n+2];arr[0]=-2e8;arr[n+1]=1e9+1e8;
    for (int i=0;i<n;++i) cin>>arr[i+1];

    vi b(k+2);b[0]=0;b[k+1]=n+1;
    for (int i=0;i<k;++i){
        cin>>b[i+1];
    }
    int ans=0;
    for (int i=1;i<k+2;++i){
        vector<int> a;
        int low=b[i-1];int high=b[i];
        if (high-low>arr[high]-arr[low]){
//            cout<<high<<" "<<low<<" "<<arr[high]<<" "<<arr[low]<<endl;
            cout<<-1;return 0;
        }
        for (int i=low+1;i<high;++i){
            if (i-low<=arr[i]-arr[low] && high-i<=arr[high]-arr[i]){
                a.pb(arr[i]-i);
            }
        }
        ans+= high-low-1-find_lis(a);
    }
    cout<<ans;





    return 0;
}

