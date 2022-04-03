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

        if (k==n-1) {
            if (n == 4) {
                cout << -1 << "\n";
                continue;
            }
            else{
                vi a(n/2);vi b(n/2);
                for (int i=0;i<n/2;++i) a[i]=i;
                for (int i=0;i<n/2;++i) b[i]=n-1-i;

                swap(a[0],b[1]);
                swap(a[0],b[2]);
                for (int i=0;i<n/2;++i){
                    cout<<a[i]<<" "<<b[i]<<"\n";
                }
            }
            continue;
        }
        vi a(n/2);vi b(n/2);
        for (int i=0;i<n/2;++i) a[i]=i;
        for (int i=0;i<n/2;++i) b[i]=n-1-i;
//        cout<<"k "<<k<<" n/2 "<<n/2<<endl;
        if (k>=n/2){
            swap(a[0],b[n-k-1]);
        }
        else{
            swap(a[0],a[k]);
        }
        for (int i=0;i<n/2;++i){
            cout<<a[i]<<" "<<b[i]<<"\n";
        }
        
    }

    return 0;
}

