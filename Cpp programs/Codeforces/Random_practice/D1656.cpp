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
        ll n;cin>>n;
        if (n%2==1){
            cout<<2<<endl;
        }
        else{
            ll x=1;
            while(n%2==0) n=n/2,x*=2;
            x*=2;
            if (n==1) cout<<-1<<endl;
            else cout<<min(n,x)<<endl;
        }
    }


    return 0;
}

