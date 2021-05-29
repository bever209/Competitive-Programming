#include <bits/stdc++.h>

#define pb push_back
#define f first
//#define s second

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    ll arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
        arr[i]=arr[i]%n;
    }
    ll pref[n];
    ll s=0;
    for (int i=0;i<n;++i){
        s=(s+arr[i])%n;
        pref[i]=s;
    }
    for (int i=0;i<n;++i){
        if (pref[i]==0){
            cout<<i+1<<endl;
            for (int j=1;j<=i+1;++j){
                cout<<j<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    int num[n];
    for (int i=0;i<n;++i){
        num[pref[i]]++;
    }
    int val;
    for (int i=0;i<n;++i){
        if (num[i]>1){
            val=i;break;
        }
    }
    int x1=-1,x2=-1;
    for (int i=0;i<n;++i){
        if (pref[i]==val){
            if (x1==-1){
                x1=i;
            }
            else{
                x2=i;
            }
        }
    }
    x1=x1+2;
    x2+=1;
    cout<<x2-x1+1<<endl;
    for (int i=x1;i<=x2;++i){
        cout<<i<<" ";
    }
    cout<<endl;



    return 0;
}