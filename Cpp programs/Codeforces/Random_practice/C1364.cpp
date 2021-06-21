#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;

int main()
{

    
    ios::sync_with_stdio(false);
    cin.tie(0);



    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }

    int ans[n];
    vector<int> num_missing;
    for (int i=0;i<arr[0];++i){
        num_missing.pb(i);
    }
    for (int i=1;i<n;++i){
        for (int j=arr[i]-1;j>arr[i-1];--j){
            num_missing.pb(j);
        }
    }
    int cnt=0;
    while (num_missing.size()!=n){
        num_missing.pb(1e6-cnt);
        ++cnt;
    }

    ans[0]=num_missing.at(0);
    num_missing.erase(num_missing.begin());

    for (int i=1;i<n;++i){
        if (arr[i]==arr[i-1]){
            ans[i]=num_missing.at(0);
            num_missing.erase(num_missing.begin());
        }
        else{
            ans[i]=arr[i-1];
        }
    }

    bool check=true;
    for (int i=0;i<n;++i){
        if (arr[i]>i+1){
            check=false;
        }
    }
    if (check){
        for (int i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }


    return 0;
}