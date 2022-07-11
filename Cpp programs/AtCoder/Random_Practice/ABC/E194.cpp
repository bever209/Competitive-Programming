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

    int n,m;cin>>n>>m;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    vector<vi> num(15*1e5+5);
    for (int i=0;i<num.size();++i){
        num[i].pb(-1);
    }
    for (int i=0;i<n;++i){
        num[arr[i]].pb(i);
    }
    for (int i=0;i<num.size();++i){
        num[i].pb(n);
    }
    int ans;
    for (int i=0;i<num.size();++i){
        for (int j=1;j<num[i].size();++j){
            if (num[i][j]-num[i][j-1]>m){
                cout<<i<<endl;return 0;
            }
        }
    }


    return 0;
}

