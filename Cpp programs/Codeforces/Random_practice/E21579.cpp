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

const int N=2e5+5;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        vi arr(n);
        for (int i=0;i<n;++i) cin>>arr[i];

        Tree<pii> tree;map<int,int> m;
        ll ans=0;
        for (int i=0;i<n;++i){
            ll less=tree.order_of_key({arr[i],0});
            int num=0;
            if (m.count(arr[i])) num=m[arr[i]];

            ll greater=i-less-num;
            //cout<<less<<" "<<greater<<endl;
            ans+=min(greater,less);
            if (m.count(arr[i])) m[arr[i]]++;
            else m[arr[i]]=1;
            tree.insert({arr[i],m[arr[i]]});

        }

        cout<<ans<<"\n";
    }

    return 0;
}

