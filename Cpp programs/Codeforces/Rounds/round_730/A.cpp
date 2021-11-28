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

    int t;cin>>t;
    for (int va=0;va<t;++va){
        ll a,b;
        cin>>a>>b;
        if (a==b){
            cout<<0<<" "<<0<<endl;continue;
        }
        if (b<a){
            swap(b,a);
        }
        ll ans=b-a;
        ll t=a%ans;
        ll ans2=min(t,ans-t);
        cout<<ans<<" "<<ans2    <<endl;
    }



    return 0;
}