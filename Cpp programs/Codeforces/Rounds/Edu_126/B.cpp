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
    ll goal=32768;
    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];


    for (int i=0;i<n;++i){
        ll ans=4e5;
        if (arr[i]==0){
            cout<<0<<endl;continue;
        }
        ll x=arr[i]; // multiply first then add
        for (int j=0;j<=17;++j){
            if (x==0){
                ans=min(ans,(ll)j);
            }
            else{
                ans=min(ans,j+goal-x);
            }
            x=(x*2)%goal;
        }
        x=arr[i];
        for (int j=0;j<=15;++j){
            int p=pow(2,j);
            ll add=0;
            if (x%p!=0){
                add=(p-x%p);
            }
            ans=min(ans,add+15-j);
        }
        cout<<ans<<endl;
    }



    return 0;
}

