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

int calc(vi x){
    stack<int> s;int ans=0;
    int n=x.size();
    for (int i=0;i<n;++i){
        while (!s.empty() && s.top()<x[i]) s.pop();
        if (!s.empty())ans=max(ans,s.top()^x[i]);

        s.push(x[i]);
    }
    return ans;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    vi x;
    for (int i:arr) x.pb(i);
    int ans=0;
    ans=max(ans,calc(x));
    reverse(x.begin(),x.end());
    ans=max(ans,calc(x));
    cout<<ans<<endl;



    return 0;
}

