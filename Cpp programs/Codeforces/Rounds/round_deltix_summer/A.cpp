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
        ll c,d;
        cin>>c>>d;
        if (c==d && c==0){
            cout<<0<<"\n";continue;
        }
        if ((c+d)%2!=0){
            cout<<-1<<"\n";
        }
        else{
            if (-c==d || c==d){
                cout<<1<<"\n";
            }
            else{
                cout<<2<<"\n";
            }
        }

    }

    return 0;
}

