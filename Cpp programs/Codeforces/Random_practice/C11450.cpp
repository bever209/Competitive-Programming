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
        str arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];

        int c0=0;int c1=0;int c2=0;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if (arr[i][j]=='X'){
                    int m=(i+j)%3;
                    if (m==0) c0++;
                    else if (m==1) c1++;
                    else c2++;
                }
            }
        }
        vector<pii> a;
        a.pb({c0,0});a.pb({c1,1});a.pb({c2,2});
        sort(a.begin(),a.end());
        int num=a[0].s;
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if ((i+j)%3==num && arr[i][j]=='X'){
                    arr[i][j]='O';
                }
            }
        }
        for (str i:arr) cout<<i<<"\n";
    }

    return 0;
}

