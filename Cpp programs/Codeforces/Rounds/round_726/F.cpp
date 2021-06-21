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
    for (int vw=0;vw<t;++vw){
        int n,m;
        cin>>n>>m;
        ll v[n];
        ll t[n];
        for (int i=0;i<n;++i){
            cin>>v[i];
        }
        for (int i=0;i<n;++i){
            cin>>t[i];
        }
        for (int i=0;i<m;++i){
            int a,b;
            cin>>a>>b;
        }
        ll vsum=0;
        for (ll i:v){
            vsum=(vsum+i+1000000000)%2;
        }
        ll tsum=0;
        for (ll i:t){
            tsum=(tsum+i+1000000000)%2;
        }
        if (vsum%2==tsum%2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}