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
        int n,m;cin>>n>>m;

        str arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];
        if (arr[0][0]=='1'){
            cout<<-1<<endl;
        }
        else{
            int c=0;
            vector<array<int,4>> x;
            for (int i=n-1;i>=0;--i){
                for (int j=m-1;j>=1;--j){
                    if (arr[i][j]=='1'){
                        ++c;
                        x.pb({i+1,j,i+1,j+1});
                    }
                }
            }
            for (int i=n-1;i>=1;--i){
                if (arr[i][0]=='1'){
                    ++c;
                    x.pb({i,1,i+1,1});
                }
            }
            cout<<c<<endl;
            for (auto i:x){
                for (auto j:i) cout<<j<<" ";
                cout<<endl;
            }
        }
    }


    return 0;
}

