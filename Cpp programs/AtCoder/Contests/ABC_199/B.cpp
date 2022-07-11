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

    int n;
    cin>>n;
    int mx=0;
    for (int i=0;i<n;++i){
        int a;cin>>a;
        mx=max(mx,a);
    }
    int mn=1e9;
    for (int i=0;i<n;++i){
        int a;
        cin>>a;
        mn=min(mn,a);
    }
    cout<<max(0,mn-mx+1)<<endl;
    return 0;
}

