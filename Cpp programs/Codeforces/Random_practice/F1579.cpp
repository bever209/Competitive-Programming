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
        int n,d;cin>>n>>d;
        int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];

        vector<bool> vis(n);int mx=-1;
        for (int i=0;i<n;++i){
            if (!vis[i]){
                vi a;
                while (!vis[i]){
                    vis[i]=true;a.pb(arr[i]);
                    i+=d;i%=n;
                }
                vi ind0;
                for (int j=0;j<a.size();++j) if (a[j]==0) ind0.pb(j);
                if (ind0.empty()) mx=1e9;
                else{
                    int num=ind0[0];
                    for (int j=0;j<ind0.size();++j){
                        ind0[j]-=num;
                    }
                    ind0.pb(a.size());
                    for (int j=1;j<ind0.size();++j){
                        mx=max(mx,ind0[j]-ind0[j-1]-1);
                    }
                }
            }
        }
        if (mx==1e9) cout<<-1<<endl;
        else cout<<mx<<endl;
    }


    return 0;
}

