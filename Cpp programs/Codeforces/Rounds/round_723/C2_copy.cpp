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


    ll n;
    cin>>n;
    ll arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }

    priority_queue<ll> list;
    ll sum=0;
    for (int i=0;i<n;++i){
        if (arr[i]>=0){
            list.push(-arr[i]);
            sum+=arr[i];
        }
        else{
            if (sum+arr[i]>=0){
                list.push(-arr[i]);
                sum+=arr[i];
            }
            else{
                if (list.size()>0 && -list.top()<arr[i]){
                    sum+=list.top();
                    sum+=arr[i];
                    list.pop();
                    list.push(-arr[i]);

                }
            }
        }
        //sort(list.begin(),list.end());
    }
    cout<<list.size()<<endl;

    return 0;
}