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


    int t;
    cin>>t;
    while (t--){
        int n;cin>>n;
        int perm[n];
        for (int i=0;i<n;++i){
            int a;cin>>a;perm[i]=a-1;
        }
        int color[n];
        for (int i=0;i<n;++i){
            cin>>color[i];
        }
        vector<vi> cycles;
        vector<bool> visit(n,false);
        for (int i=0;i<n;++i){
            if (!visit[i]){
                vi cycle;
                int node=i;
                while (!visit[node]){
                    visit[node]=true;
                    cycle.pb(node);
                    node=perm[node];
                }
                cycles.pb(cycle);
            }
        }
       /* for (vi i:cycles){
            for (int j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }*/
        int ans=1e9;
        for (vi i:cycles){
            int m=i.size();
            for (int j=1;j<=m;++j){
                if (m%j==0){
                    for (int k=0;k<j;++k){
                        bool check=true;
                        for (int l=0;l<m/j;++l){
                            if (color[i[l*j+k]]!=color[i[k]]){
                                check=false;break;
                            }
                        }
                        if (check){
                            ans=min(ans,j);break;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

