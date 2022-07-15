#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;

        vi ans(n);vb seen(n+1);
        int ind=0;
        for (int i=1;i<=n;++i){
            if (seen[i]) continue;
            ans[ind]=i;seen[i]=true;
            ++ind;
            int x=i;
            while (2*x<=n){
                ans[ind]=2*x;seen[2*x]=true;
                x*=2;
                ++ind;
            }
        }


        cout<<2<<endl;
        for (int i:ans) cout<<i<<" ";
        cout<<endl;
    }


    return 0;
}

