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
        int highestpw=1;
        while (highestpw<=(n-1)){
            highestpw*=2;
        }
        highestpw/=2;
        vi ans(n);
        for (int i=0;i<n;++i) ans[i]=i;
        swap(ans[highestpw-1],ans[0]);
        for (int i:ans) cout<<i<<" ";
        cout<<endl;
    }


    return 0;
}

