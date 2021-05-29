#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;
using ll = long long;

int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        int n;cin>>n;
        int r[n];
        int c[n];
        for (int i=0;i<n;++i){
            cin>>r[i];
        }
        for (int i=0;i<n;++i){
            cin>>c[i];
        }
        pair<int,int> arr[n+1];
        for (int i=0;i<n;++i){
            arr[i+1]=mp(r[i],c[i]);
        }
        arr[0]=mp(1,1);
        sort(arr,arr+n+1);
        ll ans=0;
        for (int i=1;i<=n;++i){
            int r1=arr[i-1].f;int c1=arr[i-1].s;
            int r2=arr[i].f;int c2=arr[i].s;

            if (r1-c1==r2-c2){
                if ((r1+c1)%2==0){
                    ans+=r2-r1;
                }
            }
            else{
                if ((r1+c1)%2==0){
                    ans+=((r2-r1+1)-(c2-c1+1))/2;
                }
                else{
                    ans+=((r2-r1+1)-(c2-c1+1)+1)/2;
                }
            }
        }
        cout<<ans<<endl;

    }



    return 0;
}