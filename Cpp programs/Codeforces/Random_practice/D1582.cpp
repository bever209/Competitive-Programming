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
    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];vi ans(n);
        if (n%2==0){
            for (int i=0;i<n;i+=2){
                ans[i]=-arr[i+1];ans[i+1]=arr[i];
            }
        }
        else{
            for (int i=0;i<n-3;i+=2){
                ans[i]=-arr[i+1];ans[i+1]=arr[i];
            }
            if (arr[n-1]+arr[n-2]!=0){
                ans[n-3]=-(arr[n-1]+arr[n-2]);ans[n-2]=ans[n-1]=arr[n-3];
            }
            else if (arr[n-1]+arr[n-3]!=0){
                ans[n-2]=-(arr[n-1]+arr[n-3]);ans[n-1]=ans[n-3]=arr[n-2];
            }
            else if (arr[n-2]+arr[n-3]!=0){
                ans[n-1]=-(arr[n-2]+arr[n-3]);ans[n-2]=ans[n-3]=arr[n-1];
            }
        }
        for (int i:ans) cout<<i<<" ";
        cout<<endl;

    }


    return 0;
}

