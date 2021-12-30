#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using str=string;

const ll inf=2*1e18;


typedef tree<
        int,
        null_type,
        less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);


    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    ordered_set order;
    int ind=n-1;
    order.insert(arr[ind]);
    --ind;
    while (ind>=0 && arr[ind]<arr[ind+1]){
        order.insert(arr[ind]);--ind;
    }
    vi not_there;
    for (int i=0;i<=ind;++i){
        not_there.pb(arr[i]);
    }
    int num=1;
    cout<<not_there.size()<<endl;
    vi x;
    for (int i:not_there){
        x.pb(order.order_of_key(i)+not_there.size()-num);
        order.insert(i);
        ++num;
    }
    for (int i=0;i<x.size();++i){
        if (i==x.size()-1){
            cout<<x[i]<<endl;
        }
        else{
            cout<<x[i]<<" ";
        }
    }



    return 0;
}

