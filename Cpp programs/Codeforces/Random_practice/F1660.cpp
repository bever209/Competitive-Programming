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
        int n;cin>>n;str s;cin>>s;
        ll ans=0;
        for (int i=0;i<n;++i){
            int sum=0;
            if (s[i]=='+') ++sum;
            else --sum;
            for (int j=i+1;j<n;++j){
                if (s[j]=='+') ++sum;
                else --sum;

                if (sum<=0 && sum%3==0) ++ans;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}

