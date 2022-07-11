#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using str=string;

const ll inf=2*1e18;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin>>n;
    ll ans=1;
    while (true){
        ll len=0;
        ll x=ans;
        while (x>0){
            x/=10;++len;
        }
        ll num=ans+(ll)pow(10,len)*ans;
        if (num>n){
            cout<<ans-1<<endl;
            break;
        }
        ++ans;
    }


    return 0;
}

