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
        int n,m;cin>>n>>m;
        int sum=0;
        for (int i=0;i<n;++i){
            int x;cin>>x;
            sum+=x;
        }
        cout<<max(0,sum-m)<<endl;
    }


    return 0;
}

