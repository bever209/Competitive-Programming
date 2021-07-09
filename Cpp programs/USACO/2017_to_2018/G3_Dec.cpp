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
using str=string;

const ll inf=2*1e9;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);

    int n;cin>>n;
    ll sum;cin>>sum;
    pair<ll,ll> arr[n];
    for (int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }
    int left=0;int right=0;
    ll ans=inf;ll rsum=0;
    multiset<int> st;
    while (left<n){
        while (rsum<sum && right<n) {
            st.insert(arr[right].s);
            rsum += arr[right].f;
            ++right;

        }
        if (rsum>=sum) {
            ans = min(ans, (ll)*st.rbegin());

        }
        st.erase(st.find(arr[left].s));
        rsum -= arr[left].f;
        ++left;


    }
    cout<<ans<<endl;
    return 0;
}

