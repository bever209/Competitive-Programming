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
int n;

vi near(int arr[]){
    stack<pii> s;
    vi ans(n);
    for (int i=0;i<n;++i){
        int a=0;
        while (!s.empty() && s.top().f>=arr[i]) s.pop();
        if (s.empty()) ans[i]=-1;
        else ans[i]=s.top().s;
        s.push({arr[i],i});
    }
    for (int i=0;i<n;++i) ans[i]=i-ans[i]-1;
    return ans;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    vi left=near(arr);
    int rev[n];
    for (int i=0;i<n;++i) rev[n-1-i]=arr[i];

    vi right=near(rev);

    reverse(right.begin(),right.end());

    vi ans(n+1);
    for (int i=0;i<n;++i){
        int a=left[i]+right[i]+1;
        ans[a]=max(ans[a],arr[i]);
    }
    for (int i=n-1;i>=0;--i){
        ans[i]=max(ans[i],ans[i+1]);
    }
    for (int i=1;i<=n;++i) cout<<ans[i]<<" ";



    return 0;
}

