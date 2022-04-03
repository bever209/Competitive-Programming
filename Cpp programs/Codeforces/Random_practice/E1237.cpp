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
const ll mod= 998244353;
ll f(int x){
    return 2*x+1;
}
ll solve(int x,int parity){
    if (x==1){
        if (parity==1) return 1;
        else return 0;
    }
    if (x==2){
        if (parity==0) return 1;
        else return 0;
    }
    if (x==3) return 0;

    int left=x;
    int p=1;
    while (p<=left){
        left-=p;
        p*=2;
    }
    p=1;
    while (f(p)<=x) p=f(p);

//    cout<<x<<" "<<left<<" "<<p<<endl;
    int num=p/2+1;
    int start=max(0,left-num);
    ll ans=0;
    for (int i=start;i<=left;++i) {
        if ((p / 2 + i + 1) % 2 == parity) {
//            cout<<i<<endl;
            ans = (ans + solve(p / 2 + i,1-parity) * solve(p / 2 + (left - i), (parity+p/2+1+i)%2)) % mod;

        }
    }

    return ans;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    int x=1;
    while (x<=n){
        if (n==x || n==x+1){
            cout<<1;return 0;
        }
        if (x%2==1){
            x=2*x+2;
        }
        else{
            x=2*x+1;
        }
    }
    cout<<0;


    return 0;
}

