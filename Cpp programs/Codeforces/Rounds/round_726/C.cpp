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
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        vi x;
        int mindiff=1e9;int minind=1;
        for (int i=1;i<n;++i){
            if (arr[i]-arr[i-1]<mindiff){
                mindiff=arr[i]-arr[i-1];
                minind=i;
            }

        }
        vi ans;
        for (int i=0;i<n;++i){
            if (i!=minind && i!=minind-1){
                x.pb(arr[i]);
            }
        }

        sort(x.begin(),x.end());
        for (int i:x){
            if (i>=arr[minind]){
                ans.pb(i);
            }
        }
        for (int i:x){
            if (i<arr[minind]){
                ans.pb(i);
            }
        }
        cout<<arr[minind-1]<<" ";
        for (int i:ans){
            cout<<i<<" ";
        }
        cout<<arr[minind]<<endl;
    }

    return 0;
}