#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll=pair<ll,ll>;
using vi = vector<int>;
using vb=vector<bool>;
using vll=vector<ll>;
using vpii=vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        int k;cin>>k;

        vi a(n);
        for (int i=0;i<n;++i) cin>>a[i];

        if (k==1) {
            cout<<((n-2)+1)/2<<endl;
            continue;
        }
        int c=0;
        for (int i=1;i<n-1;++i){
            if (a[i]>a[i-1]+a[i+1]) ++c;
        }
        cout<<c<<endl;
    }


    return 0;
}

