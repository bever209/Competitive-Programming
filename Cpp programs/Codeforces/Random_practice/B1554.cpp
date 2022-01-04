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
    #define int ll

    int tc;cin>>tc;
    while (tc--){
        int n,k;cin>>n>>k;
        int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];

        int ind=max((ll)0,n-2*k-5);
        int ans=-1e9;
        for (int i=ind;i<n;++i) for (int j=i+1;j<n;++j){
            ans=max(ans,(i+1)*(j+1)-k*(arr[i]|arr[j]));
        }
        cout<<ans<<endl;
    }


    return 0;
}

