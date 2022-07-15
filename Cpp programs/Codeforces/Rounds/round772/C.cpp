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
        for (int i=0;i<n;++i) cin>>arr[i];

        vector<pair<int,pii>> ans;
        bool check=true;
        for (int i=1;i<n;++i){
            if (arr[i-1]>arr[i]) {
                check=false;break;
            }
        }

        if (check){
            cout<<0<<"\n";
        }else{
            if (arr[n-1]<arr[n-2]){
                check=true;
            }
            else{
                if (arr[n-1]>=0){
                    for (int i=0;i<n-2;++i){
                        ans.pb({i,{n-2,n-1}});
                    }
                }
                else{
                    check=true;
                }
            }
            if (check){
                cout<<"-1\n";
            }
            else{
                cout<<ans.size()<<"\n";
                for (auto i:ans) cout<<i.f+1<<" "<<i.s.f+1<<" "<<i.s.s+1<<"\n";
            }
        }


    }


    return 0;
}

