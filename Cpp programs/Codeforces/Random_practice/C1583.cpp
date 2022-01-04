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

    int n,m;cin>>n>>m;
    str arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    vector<vi> num(n,vi(m,0));
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (i-1>=0 && arr[i-1][j]=='X'){
                if (j-1>=0 && arr[i][j-1]=='X'){
                    num[i][j]=1;
                }
            }
        }
    }
    vector<vi> pref(n,vi(m));
    pref[0][0]=num[0][0];
    for (int i=1;i<n;++i){
        pref[i][0]=pref[i-1][0]+num[i][0];
    }
    for (int i=1;i<m;++i){
        pref[0][i]=pref[0][i-1]+num[0][i];
    }
    for (int i=1;i<n;++i) for (int j=1;j<m;++j){
        pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+num[i][j];
    }
    int q;cin>>q;
    while (q--){
        int a,b;cin>>a>>b;
        --a;--b;int x;
        if (a==0){
            x=pref[n-1][b];

        }
        else{
            x=pref[n-1][b]-pref[n-1][a];
        }
        if (a==b) x=0;
        if (x>0) cout<<"no\n";
        else cout<<"yes\n";
    }

    return 0;
}

