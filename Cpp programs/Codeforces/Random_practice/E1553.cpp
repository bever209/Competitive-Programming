#include <bits/stdc++.h> // FIX

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

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];--arr[i];
    }

    vector<int> rotk(n);
    for (int i=0;i<n;++i){
        int rot=(n+i-arr[i])%n;++rotk[rot];
    }
    vector<int> ans;
    for (int i=0;i<n;++i){
        int num=rotk[i];
        if (num>=n-2*m){
            int list[n];
            for (int j=0;j<n;++j){
                list[j]=(n-i+j)%n;

            }
            int loc[n];
            for (int j=0;j<n;++j){
                loc[arr[j]]=j;
            }
            vector<bool> vis(n,false);
            int cc=0;
            for (int j=0;j<n;++j){
                /*for (int k:list){
                    cout<<k<<" ";
                }

                cout<<endl;
                cout<<i<<endl;*/
                if (!vis[j]){
                    vis[j]=true;++cc;
                    int ind=j;
                    do{
                        ind=list[loc[ind]];
                        vis[ind]=true;
                    }
                    while(ind!=j);
                }
            }
            if (n-cc<=m){
                ans.pb(i);
            }
        }
    }
    cout<<ans.size()<<" ";
    for (int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

}

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin>>tc;
    while (tc--){
        solve();
    }


    return 0;
}

