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


int N=2e7+5;
vector<int> mind(N, -1), val(N);



int main() {

#define int ll
    ios::sync_with_stdio(false);
    cin.tie(0);
    mind[1] = 1;
    for (int i = 2; i < N; ++i) if (mind[i] == -1)
            for (int j = i; j < N; j += i) if (mind[j] == -1)
                    mind[j] = i;
    for (int i = 2; i < N; ++i) {
        int j = i / mind[i];
        val[i] = val[j] + (mind[i] != mind[j]);
    }


    int tc;cin>>tc;
    while (tc--){
        int c,d,x;cin>>c>>d>>x;
        int g=gcd(c,gcd(x,d));
        c/=g;d/=g;x/=g;

        vi f;
        for (int i=1;i<(int)sqrt(x)+1;++i){
            if (x%i==0){
                f.pb(i);
                if (i!=x/i){
                    f.pb(x/i);
                }
            }
        }
        int ans=0;
        for (int i:f){
            int n=d*i+x;
            if (n%c==0){
                int lcm=n/c;
                int gcd=i;
                if (lcm%gcd==0){
                    lcm/=gcd;
                    ans=ans+(1<<val[lcm]);
                }
            }
        }


        cout<<ans<<"\n";
    }


    return 0;
}

