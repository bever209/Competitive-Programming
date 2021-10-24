#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using str=string;

const ll inf=2*1e18;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while (t--){
        int n;cin>>n;
        bool found=false;
        int ans[n];int maxind;
        for (int i=1;i<n;i+=2){
            cout<<"? 1 "<<i<<" "<<i+1<<" "<<n-1<<endl;
            int r;cin>>r;
            if (r==n){
                maxind=i;found=true;break;
            }
            else if (r<n-1){
                continue;
            }
            else{
                cout<<"? 1 "<<i+1<<" "<<i<<" "<<n-1<<endl;
                int v;cin>>v;
                if (v==n){
                    maxind=i-1;found=true;break;
                }
            }

        }
        if (!found){
            maxind=n-1;
        }
        for (int i=1;i<=n;++i){
            if (i!=maxind+1) {
                cout << "? 2 " << i << " " << maxind+1 << " 1" << endl;
                int r;
                cin >> r;
                ans[i - 1] = r;
            }
        }
        ans[maxind]=n;
        cout<<"! ";
        for (int i:ans){
            cout<<i<<" ";
        }
        cout<<endl;


    }


    return 0;
}

