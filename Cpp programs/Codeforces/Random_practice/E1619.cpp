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
#define int ll
    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];

        vi ans(n+1);
        vi count(n+1,0);
        for (int i: arr) count[i]++;

        stack<int> extra;

        for (int i=0;i<=n;++i){
            if (i==0) ans[i]=count[i];
            else{
                if (count[i-1]>0){
                    ans[i]=ans[i-1]-count[i-1]+count[i];
                }
                else{
                    if (extra.size()==0){
                        for (int j=i;j<=n;++j) ans[j]=-1;
                        break;
                    }
                    int a=extra.top();extra.pop();
                    ans[i]=ans[i-1]+i-1-a + count[i];
                }
            }
            for (int j=0;j<count[i]-1;++j) extra.push(i);
        }
        for (int i:ans) cout<<i<<" ";
        cout<<"\n";
    }



    return 0;
}

