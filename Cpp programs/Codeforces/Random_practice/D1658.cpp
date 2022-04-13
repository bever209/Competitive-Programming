#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue
 // FIX THIS, GET IT TO WORK
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;

int num(int n,int bit){
    // from 0 to n, how many times is bit "bit" set
    int mod=pow(2,bit+1);
    // remainder after mod should be greater or equal to 2^i
    int up=(n/mod) * mod + pow(2,bit);
    int ans=0;

    ans=(max(0,n-up+1));
    int x=(n/mod) * mod;
    return ans+x/2;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int l,r;cin>>l>>r;
        int len=r-l+1;
        int arr[len];
        for (int i=0;i<len;++i) cin>>arr[i];


        int ans=0;
        for (int i=18;i>=0;--i){

            int n=num(r,i)-num(l-1,i);
            int c=0;
            for (int j:arr){
                if (j & (int)(pow(2,i))){
                    ++c;
                }
            }
            if (c>len-c && n<len-n){
                ans=ans+pow(2,i);
            }
            else if (c<len-c && n>len-n){
                ans=ans+pow(2,i);
            }


        }
        cout<<ans<<endl;

    }


    return 0;
}

