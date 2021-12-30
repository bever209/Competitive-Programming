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

    int tc;
    cin>>tc;
    vi primes;
    primes.pb(2);
    primes.pb(3);
    primes.pb(5);
    for (int i=7;i<1000+20;++i){
        for (int j:primes){
            if (j>(int)sqrt(i)+2){
                primes.pb(i);
                break;
            }
            else if (i%j==0){
                break;
            }
        }
    }
    while (tc--){
        int n,e;cin>>n>>e;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        ll ans=0;
        for (int i=0;i<e;++i){
            int ind=0;
            while (ind*e+i<n){
                int x=ind*e+i;
                int num=arr[x];bool prime=true;
                for (int i:primes){
                    if (i>(int)sqrt(num)+2){
                        break;
                    }
                    else if (num%i==0 && num!=i){
                        prime=false;break;
                    }
                }
                if (prime && num!=1){
                    ll left=0;
                    ll right=0;
                    int c=1;
                    while ((ind-c)*e+i>=0 && arr[(ind-c)*e+i]==1){
                        ++left;++c;
                    }
                    c=1;
                    while ((ind+c)*e+i<n && arr[(ind+c)*e+i]==1){
                        ++right;++c;
                    }
                    ans+=(left*right+left+right);
                }
                ++ind;
            }

        }
        cout<<ans<<"\n";

    }

    return 0;
}

