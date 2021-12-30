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

    int tc;cin>>tc;
    while (tc--){
        int n,s;cin>>n>>s;
        int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];

        vi pref(n,arr[0]);
        for (int i=1;i<n;++i) pref[i]=pref[i-1]+arr[i];

        vi ans(n,0); // length if you start at index i
        int rsum=s;int right=0;
        for (int i=0;i<n;++i){
            if (right<i){
                rsum=s;right=i;
            }
            while (right<n && arr[right]+rsum>=0) {
                rsum += arr[right];++right;
            }
            ans[i]=right-i;
            if (right>i)
                rsum-=arr[i];

        }
        int mx=0;
        int left=0;int r=0;
        for (int i=0;i<n;++i){
            if (ans[i]>mx){
                mx=max(mx,ans[i]);
                left=i;r=ans[i]+i-1;
            }
        }
        if (mx==0){
            cout<<-1<<endl;
        }
        else{
            cout<<left+1<<" "<<r+1<<endl;
        }
    }


    return 0;
}

