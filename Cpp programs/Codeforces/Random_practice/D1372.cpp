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

int main() {

#define int ll
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    vi v;
    for (int i=0;i<n;i+=2){
        v.pb(arr[i]);
    }
    for (int i=1;i<n;i+=2){
        v.pb(arr[i]);
    }
    vi x;
    for (int i=0;i<2;++i){
        for (int j:v) x.pb(j);
    }
    int choose=(n+1)/2;
    int sum=0;
    for (int i=0;i<choose;++i){
        sum+=x[i];
    }

    int ans=sum;
    for (int i=choose;i<x.size();++i){
        int remove=i-choose;
        sum-=x[remove];sum+=x[i];
        ans=max(ans,sum);
    }
    cout<<ans<<endl;

    return 0;
}

