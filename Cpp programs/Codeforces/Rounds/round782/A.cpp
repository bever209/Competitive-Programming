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
        int n;cin>>n;
        int r,b;cin>>r>>b;
        str a="";str xx="";
        for (int i=0;i<r;++i) a+='R';
        for (int i=0;i<b;++i) xx+='B';

        int ans=(r-1)/(b+1);
        ++ans;
        str t="";int need_r=r;int need_b=b;
        while (need_r>0 && need_b>0){
            // number left is need_b+1
            int rem=min(ans,need_r-need_b);

            need_r-=rem;need_b-=1;
            for (int i=0;i<rem;++i) t+='R';
            t+='B';

        }
        for (int i=0;i<need_r;++i) t+='R';
        for (int i=0;i<need_b;++i) t+='B';
        cout<<t<<endl;
    }


    return 0;
}

