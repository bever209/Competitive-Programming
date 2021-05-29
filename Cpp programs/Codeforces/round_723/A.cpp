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
        int n;
        cin>>n;
        n*=2;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        if (n==2){
            cout<<arr[0]<<" "<<arr[1]<<endl;continue;
        }
        for (int i=1;i<n-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
        for (int i:arr){
            cout<<i<<" ";
        }
        cout<<endl;



    }


    return 0;
}