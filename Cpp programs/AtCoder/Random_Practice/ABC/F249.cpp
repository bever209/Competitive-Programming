#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using pll=pair<ll,ll>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;

    multiset<ll> a;
    // first is the smaller, second is the larger

    ll bsum=0;

    vector<pll> l;
    l.pb({1,0});
    for (int i=0;i<n;++i){
        ll x,y;cin>>x>>y;
        l.pb({x,y});
    }
    int num=k;
    vi cc;
    for (int i=l.size()-1;i>=0;--i){
        if (l[i].f==1){
            cc.pb(l[i].s+bsum);
            --num;
            if (num<0) break;
        }
        else{
            a.insert(l[i].s);
        }
        while (((a.size()>0 && *(a.rbegin())>=0))|| a.size()>num){
            ll x=*(a.rbegin());
            bsum+=x;
            a.erase(a.find(x));
        }

    }
    ll mx=cc[0];
    for (auto i:cc) mx=max(mx,i);
    cout<<mx<<endl;


    return 0;
}