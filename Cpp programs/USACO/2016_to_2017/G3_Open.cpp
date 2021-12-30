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

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("art2.in","r",stdin);
    freopen("art2.out","w",stdout);

    int n;cin>>n;
    vi arr(n+2);arr.pb(0);
    for (int i=0;i<n;++i) cin>>arr[i+1];
    arr.pb(0);

    vi start(n+1,1e9);vi fin(n+1,0);
    for (int i=0;i<n+2;++i){
        start[arr[i]]=min(start[arr[i]],i);
        fin[arr[i]]=max(fin[arr[i]],i);
    }
    stack<int> s;
    for (int i=0;i<n+2;++i){
        if (start[arr[i]]==i){
            s.push(arr[i]);
        }
        if (fin[arr[i]]==i){
            int x=s.top();
            s.pop();
            if (x!=arr[i]){
                cout<<-1;return 0;
            }
        }
    }
    int ans=0;int in=0;
    for (int i=0;i<n+2;++i){
        if (start[arr[i]]==i) {
            ++in;
        }
        ans=max(ans,in);
        if (fin[arr[i]]==i){
            --in;
        }

    }
    cout<<ans-1<<endl;

    return 0;
}

