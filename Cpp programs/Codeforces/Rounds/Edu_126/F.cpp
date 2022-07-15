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
    ll arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    ll m;cin>>m;
    ll tot=0;
    for (int i=1;i<n;++i) tot=tot+pow(arr[i]-arr[i-1],2);

    pq<pair<ll,ll>> q;
    for (int i=1;i<n;++i) q.push({pow(arr[i]-arr[i-1],2)/2,1});

    ll ans=0;
    while (tot>m){
        auto x=q.top();q.pop();

    }

    return 0;
}

