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
        int n,k;cin>>n>>k;
        int tot=n*k;
        int odd=(tot+1)/2;
        if (odd%k!=0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            int c=0;
            for (int i=1;i<=tot;i+=2){
                ++c;
                if (c%k==0){
                    cout<<i<<"\n";
                }
                else{
                    cout<<i<<" ";
                }
            }
            c=0;
            for (int i=2;i<=tot;i+=2){
                ++c;
                if (c%k==0){
                    cout<<i<<"\n";
                }
                else{
                    cout<<i<<" ";
                }
            }
        }
    }


    return 0;
}

