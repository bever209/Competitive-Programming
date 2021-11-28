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
        if (n==1){
            cout<<"0"<<endl;
            continue;
        }
        ll d[n];
        for (int i=0;i<n;++i){
            cin>>d[i];
        }

        ll ans=0;
        vector<ll> list;
        for (int i=1;i<n;++i){
            list.pb(d[i]);

        }
        sort(list.begin(),list.end());

        ans+=list[0];
        for (int i=0;i<n-2;++i){
            ans+=(list[i+1]-list[i]);
        }
        for (int i:list){
            ans-=i;
        }
        ll pref[n-1];
        ll sum=0;
        for (int i=0;i<n-1;++i){
            sum+=list[i];
            pref[i]=sum;
        }
        for (int i=n-2;i>0;--i){
            ans+=(pref[i-1]-i*list[i]);
        }



        cout<<ans<<endl;
    }

    return 0;
}
