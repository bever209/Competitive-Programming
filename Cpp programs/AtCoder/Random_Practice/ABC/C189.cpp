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
# define int long long

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    ll ans=0;
    for (int left=0;left<n;++left){
        int mn=1e9;
        for (int right=left;right<n;++right){
            mn=min(mn,arr[right]);
            int len=right-left+1;
           // cout<<len*mn<<endl;
            ans=max(ans,(ll)len*mn);
        }
    }
    cout<<ans;


    return 0;
}

