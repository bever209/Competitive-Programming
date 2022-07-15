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

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        ll arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];

        ll sum=0;
        for (int i:arr) sum+=i;

        ll b[n];
        for (int i=0;i<n;++i) {
            if (i % 2 == 0) b[i] = 1;
            else b[i] = arr[i];
        }
        ll diff=0;
        for (int i=0;i<n;++i){
            diff=(diff+abs(b[i]-arr[i]));
        }
        if (2*diff<=sum){
            for (int i:b) cout<<i<<" ";cout<<endl;
        }
        else{
            for (int i=0;i<n;++i) {
                if (i % 2 == 1) b[i] = 1;
                else b[i] = arr[i];
            }
            for (int i:b) cout<<i<<" ";cout<<endl;
        }


    }


    return 0;
}

