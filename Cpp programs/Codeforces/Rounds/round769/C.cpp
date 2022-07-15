
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
        int a,b;cin>>a>>b;
        //  b is always greater than a

        int ans=b-a;
        for (int i=a;i<=b;++i){
            int num=i-a;
            int n=b|i;
            ans=min(ans,n-b+1+num);

        }
        cout<<ans<<endl;
    }


    return 0;
}

