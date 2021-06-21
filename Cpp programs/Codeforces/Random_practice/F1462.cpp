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
        pii arr[n];
        for (int i=0;i<n;++i){
            int a,b;
            cin>>a>>b;
            arr[i]={a,b};
        }
        vi left;
        vi right;
        for (pii i:arr){
            left.pb(i.f);
            right.pb(i.s);
        }
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());

        int ans=n-1;
        for (pii i:arr){
            int a=i.f;
            int b=i.s;
            int rr= (int)(lower_bound(right.begin(),right.end(),a)-right.begin());
            int ll=max(0,n-(int)(upper_bound(left.begin(),left.end(),b)-left.begin()));
            ans=min(ans,ll+rr);
        }
        cout<<ans<<endl;
    }

    return 0;
}