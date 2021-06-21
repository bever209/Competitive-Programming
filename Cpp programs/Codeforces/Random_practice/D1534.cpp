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

    vector<pii> ans;
    int n;
    cin>>n;
    cout<<"? 1"<<endl;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];

    }
    vi odd;
    vi even;
    for (int i=1;i<n;++i){
        if (arr[i]%2==0){
            even.pb(i+1);
        }
        else{
            odd.pb(i+1);
        }
    }
    if (even.size()>odd.size()){
        even.pb(1);
        swap(even,odd);
    }
    else{
        for (int i=1;i<n;++i){
            if (arr[i]==1){
                ans.pb({1,i+1});
            }
        }
    }

    for (int i:even){
        cout<<"? "<<i<<endl;
        int list[n];
        for (int j=0;j<n;++j){
            cin>>list[j];
        }
        for (int j=0;j<n;++j){
            if (list[j]==1){
                ans.pb({j+1,i});
            }
        }
    }
    cout<<"!"<<endl;
    for (pii i:ans){
        int a,b;
        tie(a,b)=i;
        cout<<a<<" "<<b<<endl;
    }

    return 0;
}