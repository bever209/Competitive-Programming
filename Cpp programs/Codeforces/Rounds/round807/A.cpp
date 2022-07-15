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
        int n,x;cin>>n>>x;
        vi a(2*n);
        for (int i=0;i<2*n;++i) cin>>a[i];
        sort(a.begin(),a.end());
        bool check=true;
        for (int i=0;i<n;++i){
            if ((a[n+i]-a[i])<x){
//                cout<<x<<" "<<a[n+i]-a[i]<<endl;
                check=false;break;
            }
        }
        if (check){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }


    return 0;
}

