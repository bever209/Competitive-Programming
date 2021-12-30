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
    while (tc--) {
        int n;cin>>n;
        string a,b;cin>>a>>b;
        if (a==b){
            cout<<0<<"\n";continue;
        }
        int x=0,y=0;
        for (int i=0;i<n;++i){
            if (a.at(i)=='1') ++x;
            if (b.at(i)=='1') ++y;
        }
        if (x==y || n-x+1==y) {
            int same = 0;
            int diff = 0;
            for (int i = 0; i < n; ++i) {
                if (a.at(i) != b.at(i)) {
                    ++diff;
                } else {
                    ++same;
                }
            }
            int ans = 1e9;
            if (same % 2 == 1) {
                ans = min(ans, same);
            }
            if (diff % 2 == 0) {
                ans = min(ans, diff);
            }
            if (ans == 1e9) {
                cout << "-1\n";
            } else {
                cout << ans << "\n";
            }
        }
        else{
            cout<<"-1\n";
        }

    }


    return 0;
}

