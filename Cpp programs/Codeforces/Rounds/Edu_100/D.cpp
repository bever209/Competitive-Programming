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
        for (int i=0;i<n;++i) {
            cin >> arr[i];
            --arr[i];
        }

        bool in[2*n];
        for (int i=0;i<2*n;++i) in[i]=false;
        for (int i:arr) in[i]=true;

        int mn=0;int num=0;
        for (int i=0;i<2*n;++i){
            if (in[i]) ++num;
            else --num;

            mn=max(mn,num);
        }
        int mx=0;num=0;
        for (int i=2*n-1;i>=0;--i){
            if (in[i]) ++num;
            else --num;

            mx=max(mx,num);
        }
        mx=n-mx;
        cout<<mx-mn+1<<endl;
    }


    return 0;
}

