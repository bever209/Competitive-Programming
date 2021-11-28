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
        ll x,y;cin>>x>>y;
        if (x>y){
            cout<<x+y<<"\n";continue;
        }
        if (x==y){
            cout<<x<<"\n";continue;
        }
        ll num=y-y%x;
        cout<<(num+y)/2<<"\n";

    }

    return 0;
}

