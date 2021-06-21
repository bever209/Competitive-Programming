#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }

        sort(arr,arr+n);
        int x=arr[0];
        int y=arr[n-1];
        if ((x>=0 && y>=0)){
            cout<<"YES"<<endl;
            if (x<0){
                cout<<"101"<<endl;
                for (int i=-100;i>=0;++i){
                    cout<<i<<" ";
                }
            }
            else{
                cout<<"101"<<endl;
                for (int i=0;i<=100;++i){
                    cout<<i<<" ";
                }
            }
            cout<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }



    return 0;
}