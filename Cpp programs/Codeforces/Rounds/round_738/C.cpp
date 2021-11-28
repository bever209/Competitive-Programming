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
        vi arr(n);bool no1=true;
        for (int i=0;i<n;++i){
            cin>>arr[i];
            if (arr[i]==1){
                no1=false;
            }
        }
        if (no1){
            for (int i=1;i<=n+1;++i){
                cout<<i<<" ";
            }
            cout<<endl;continue;
        }
        if (arr[0]==1){
            cout<<n+1<<" ";
            for (int i=1;i<=n;++i){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            int ind;
            for (int i=1;i<n;++i){
                if (arr[i-1]==0 && arr[i]==1){
                    ind=i;
                }
            }
            for (int i=1;i<=n;++i){
                if (i==ind){
                    cout<<i<<" "<<n+1<<" ";
                }
                else{
                    cout<<i<<" ";
                }
            }
            cout<<endl;
        }


    }

    return 0;
}

