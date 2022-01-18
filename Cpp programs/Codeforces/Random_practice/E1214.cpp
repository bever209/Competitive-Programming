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

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    vector<pii> x;
    for (int i=0;i<n;++i){
        x.pb({arr[i],2*(i+1)});
    }
    sort(x.rbegin(),x.rend());
    vi a;
    for (auto i:x){
        a.pb(i.s);
    }
    vector<pii> ans;
    for (int i=1;i<n;++i){
        ans.pb({a[i],a[i-1]});
    }
    for (int i=0;i<n;++i){
        int forward=x[i].f;
        if (forward+i==a.size()){
            a.pb(x[i].s-1);
            ans.pb({a[a.size()-1],a[a.size()-2]});
        }
        else{
            ans.pb({x[i].s-1,a[i+forward-1]});
        }
    }
    for (auto i:ans){
        cout<<i.f<<" "<<i.s<<"\n";
    }


    return 0;
}

