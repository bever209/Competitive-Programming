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

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        int n;
        cin>>n;
        ll arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        ll ans=0;
        for (int i=0;i<n;++i){
            ll ind=i+1;
            ll mod=arr[i];
            ll strt_ind=((i+2)*mod-i-2)%mod;
            for (int j=strt_ind;j<n;j+=mod){
                if (arr[j]*arr[i]==i+j+2 && i<j){
                    ++ans;
                }
            }
        }
        cout<<(ans)<<endl;
    }

    return 0;
}
