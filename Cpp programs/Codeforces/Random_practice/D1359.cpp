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

int max_sum(vi x){
    vi a(x.size());
    a[0]=x[0];
    for (int i=1;i<x.size();++i){
        a[i]=a[i-1]+x[i];
    }
    int mn=0;
    int ans=0;
    for (int & i : a){
        ans=max(ans,i-mn);
        mn=min(mn,i);
    }
    return ans;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];
    int ans=0;
    for (int mx=0;mx<=30;++mx){
        vi x;
        for (int i:arr){
            if (i>mx){
                x.pb(-31);
            }
            else x.pb(i);
        }
        ans=max(ans, max_sum(x)-mx);

    }
    cout<<ans<<endl;

    return 0;
}

