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
const ll m1=1e9+9;
const ll p=9973;

ll h[1000][501];
ll pw[501];

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    pw[0]=1;
    for (int i=1;i<=500;++i) pw[i]=(pw[i-1]*p)%m1;

    int n,m;cin>>n>>m;
    str arr[n*2];
    for (int i=0;i<2*n;++i) cin>>arr[i];

    for (int i=0;i<2*n;++i){
        for (int j=1;j<=m;++j){
            h[i][j]=(h[i][j-1]*p+arr[i][j-1])%m1;
        }
    }

int left=1;int right=m;
    while (left<right){
        int len=(right+left)/2;
        bool check=false;
        for (int i=0;i+len-1<m;++i){
            bool works=true;
            unordered_set<ll> s; // maybe change
            for (int j=0;j<n;++j){
                s.insert(((h[j][i+len]-h[j][i]*pw[len])%m1 +m1)%m1);
            }
            for (int j=n;j<2*n;++j){
                if(s.count(((h[j][i+len]-h[j][i]*pw[len])%m1 +m1)%m1)){
                    works=false;break;
                }
            }
            if (works){
                check=true;break;
            }
        }
        if (check){
            right=len;
        } else left=len+1;

    }
    cout<<left<<"\n";

    return 0;
}

