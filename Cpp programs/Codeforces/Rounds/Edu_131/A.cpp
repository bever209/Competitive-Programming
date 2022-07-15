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
        int a,b,c,d;cin>>a>>b>>c>>d;

        if (a+b+c+d==4){
            cout<<2<<endl;
            continue;
        }
        else if (a+b+c+d==0){
            cout<<0<<endl;continue;
        }
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}

