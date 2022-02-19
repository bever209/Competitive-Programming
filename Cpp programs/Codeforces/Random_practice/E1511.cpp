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
#define int ll

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    ll arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    ll ans=0;ll num=(n*(n+1))/2;
    for (int i=0;i<n;++i){
        ans=ans+(arr[i]* (n-arr[i]+1));
    }
    for (int i=1;i<n;++i){
        ll a=arr[i];ll b=arr[i-1];
        if (a>b) swap(a,b);
        ans=ans-(a*(n-b+1));
    }
    cout<<ans<<endl;


    return 0;
}

