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
        int n,k;cin>>n>>k;
        cout<<0<<endl;
        int x=2;
        while (true){
            int c;cin>>c;
            if (c==1) break;
            cout<<((x-1)^(x-2)) << endl;++x;
        }
    }


    return 0;
}

