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

ll pref(ll x){
    return (x*(x+1)*(2*x+1))/6;
}

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);




    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);

    int n;
    cin>>n;
    ll c=0;
    vi arr(n);
    for (int i=0;i<n;++i){
        cin>>arr[i];
        c=max((ll)0,c+arr[i]-1);
    }

    ll ans=0;

    for (int i=0;i<n;++i){

        if (c==0){
            rotate(arr.begin(),arr.begin()+i,arr.end());
            break;
        }
        c=max((ll)0,c+arr[i]-1);
    }
    for (int i = 0; i < n; ++i) {
        int x=arr[i];
        ans+=pref(x+c-1)-pref(c-1);
        c=max((ll)0,x+c-1);

    }

    cout<<ans<<endl;


    return 0;
}