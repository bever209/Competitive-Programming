#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;
const ll mod=998244353;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
#define int ll
    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        ll ans=0;
        vi t(n);// number split into
        vi v(n);// smallest
        ll c=0;
        for (int i=0;i<n;++i){
            v[i]=arr[i];
            t[i]=1;
            int new_t=-1,new_v=-1;
            for (int j=i-1;j>=0;--j){
                ll small=v[j+1];

                new_t=(arr[j]+small-1)/small;
                new_v=arr[j]/new_t;
                if (new_t==t[j]){
                    break;
                }
                else{
                    c=c-t[j]*(j+1);
                    c=c+new_t*(j+1);
                    c=(c+mod)%mod;
                    t[j]=new_t;v[j]=new_v;
                }

            }
            ans=(ans+c)%mod;
        }



        cout<<ans<<endl;

    }


    return 0;
}

