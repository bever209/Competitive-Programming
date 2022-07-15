#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll=pair<ll,ll>;
using vi = vector<int>;
using vb=vector<bool>;
using vll=vector<ll>;
using vpii=vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        vi a(n);
        for (int i=0;i<n;++i) cin>>a[i];

        sort(a.begin(),a.end());
        if (a[n-1]>0 && a[n-2]>0 && a[n-3]>=0){
            cout<<"NO"<<endl;continue;
        }
        if (a[0]<0 && a[1]<0 && a[2]<=0){
            cout<<"NO"<<endl;continue;
        }
        int n0=0;
        vi arr;
        for (int i:a) {
            if (i == 0) ++n0;
            else arr.pb(i);
        }
        n0=min(n0,3);
        for (int i=0;i<n0;++i) arr.pb(0);

        bool check=true;
        for (int i=0;i<arr.size() && check;++i){
            for (int j=i+1;j<arr.size() && check;++j){
                for (int k=j+1;k<arr.size();++k){
                    int nn=arr[i]+arr[j]+arr[k];
                    bool c=false;
                    for (int l=0;l<arr.size();++l){
                        if (nn==arr[l]){
                            c=true;break;
                        }
                    }
                    if (!c){
                        check=false;break;
                    }
                }
            }
        }
        if (check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }



    return 0;
}

