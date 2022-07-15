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
using vi = vector<ll>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
#define int ll
    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        vll a(n);
        for (int i=0;i<n;++i) cin>>a[i];

        int x=0;
        int sum=0;
        for (int i=0;i<n-1;++i){
            sum+=a[i];
            if (a[i]==0) ++x;
        }
        int pref=0;
        for (int i=0;i<n-1;++i){
            if (a[i]!=0) break;
            ++pref;
        }
        cout<<sum+x-pref<<endl;
    }

    return 0;
}

