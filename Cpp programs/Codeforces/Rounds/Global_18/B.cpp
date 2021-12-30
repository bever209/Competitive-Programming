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

    vector<vi> bit(20,vi(2e5+5,0));
    for (int i=0;i<20;++i){
        for (int j=0;j<2e5+5;++j){
            if (j!=0){
                if (((int)pow(2,i) & j)>0) {
                    bit[i][j] = bit[i][j - 1]+1;
                }
                else{
                    bit[i][j]=bit[i][j-1];
                }
            }
        }
    }

    int tc;cin>>tc;
    while (tc--) {
        int l,r;cin>>l>>r;
        int ans=r-l+1;
        int dist=r-l+1;
        for (int i=0;i<20;++i){
            ans=min(ans,dist-(bit[i][r]-bit[i][l-1]));
        }
        cout<<ans<<"\n";

    }


    return 0;
}

