#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];--arr[i];
    }
    Tree<int> t;
    vi last(n,-1);
    ll ans=0;
    for (int i=0;i<n;++i){
        if(last[arr[i]]==-1){
            ans+=t.size();
            last[arr[i]]=i;
        }
        else{
            ans+=(t.size()-t.order_of_key(last[arr[i]])-1);
            t.erase(last[arr[i]]);
            last[arr[i]]=i;
        }
        t.insert(i);
    }
    cout<<ans<<endl;


    return 0;
}

