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
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        ll a=0;
        for (ll i:arr){
            a=gcd(i-arr[0],a);
        }
        if ((k-arr[0])%a==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


    }


    return 0;
}