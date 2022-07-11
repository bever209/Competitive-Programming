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
ll n,k;
ll bsearch(){
    ll mn=1;ll mx=n/2; // for even
    while (mn<mx){
        ll mid=(mn+mx+1)/2;

        // now find number of paths mid is in
        ll x=mid*2;ll p=1;ll ans=0;
        for (int i=0;i<61 && x<=n;++i){
            // so we are going to multiply mid by 2 i times here and then see how many times we can add
            ll sub=n-x;
            ll num=2*p-1;

            ans=ans+min(sub,num)+1;
            x*=2;p*=2;
        }
        if (ans<k) mx=mid-1;
        else mn=mid;
    }
    return 2*mn;
}
ll odd_b(){
    ll mn=1;ll mx=(n+1)/2; // for even
    while (mn<mx){
        ll mid=(mn+mx+1)/2;

        // now find number of paths mid is in
        ll x=mid*2-1;ll p=1;ll ans=0;
        for (int i=0;i<61 && x<=n;++i){
            // so we are going to multiply mid by 2 i times here and then see how many times we can add
            ll sub=n-x;
            ll num=p-1;
            ans=ans+min(sub,num)+1;
            x*=2;p*=2;
        }
        if (ans<k) mx=mid-1;
        else mn=mid;
    }
    return 2*mn-1;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
// two bsearches, one for odds and one for evens
    if (k==n){
        cout<<1<<endl;return 0;
    }

    ll a=bsearch();
    ll b=odd_b();
    cout<<max(a,b)<<endl;


    return 0;
}

