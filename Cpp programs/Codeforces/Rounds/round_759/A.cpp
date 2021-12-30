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
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        int ans=1;
        for (int i=0;i<n;++i){
            if (arr[i]==0){
                if (i>0 && arr[i-1]==0){
                    ans=-1;break;
                }
            }
            else{
                if (i>0 && arr[i-1]==1){
                    ans+=5;
                }
                else{
                    ans+=1;
                }
            }


        }
        cout<<ans<<"\n";
    }


    return 0;
}

