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

    int n;cin>>n;

    if (n<=2){
        cout<<-1;return 0;
    }
    vector<vi> ans(n,vi(n));

    ans[0][0]=n*n-9+9;
    ans[1][0]=n*n-9+7;
    ans[2][0]=n*n-9+1;
    ans[0][1]=n*n-9+5;
    ans[1][1]=n*n-9+2;
    ans[2][1]=n*n-9+3;
    ans[0][2]=n*n-9+6;
    ans[1][2]=n*n-9+8;
    ans[2][2]=n*n-9+4;

    int c=1;
    for (int i=n-1;i>=3;--i){
        if ((n-3-i)%2==0){
            for (int j=0;j<=i;++j){
                ans[j][i]=c;++c;
            }
            for (int j=i-1;j>=0;--j){
                ans[i][j]=c;++c;
            }
        }
        else{
            for (int j=0;j<=i;++j){
                ans[i][j]=c;++c;
            }
            for (int j=i-1;j>=0;--j){
                ans[j][i]=c;++c;
            }
        }
    }




    for (auto i:ans){
        for (auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}

