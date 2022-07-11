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
# define int long long
    int n;
    cin>>n;
    vector<ll> arr(n+5,0);

    for (int i=1;i<arr.size();++i){
        int x=i;
        while (x<arr.size()){
            ++arr[x];x+=i;
        }
    }
    ll ans=0;
    for (int i=1;i<=n;++i){
        ans+=i*arr[i];
    }
    cout<<ans;

    return 0;
}

