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

        str a;cin>>a;
        int num=k;
        vi ans(n);
        for (int i=0;i<n;++i){
            if (k==0) break;
            if (a[i]=='1'){
                if (num%2==1) ans[i]=1,--k;
            }
            if (a[i]=='0'){
                if (num%2==0) ans[i]=1,--k;
            }
        }
        while (k>0){
            ans[n-1]+=2;k-=2;
        }
        if (k==-1){
            ans[n-1]-=1;
        }

        str aa="";
        for (int i=0;i<n;++i){
            if ((num-ans[i])%2==0){
                aa+=a[i];
            }
            else{
                if (a[i]=='1') aa+='0';
                else aa+='1';
            }
        }
        cout<<aa<<"\n";
        for (auto i:ans) cout<<i<<" ";
        cout<<"\n";
    }


    return 0;
}

