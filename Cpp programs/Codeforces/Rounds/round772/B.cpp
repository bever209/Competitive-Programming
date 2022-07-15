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

        int c=0;
        int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];
        vector<bool> m(n);
        for (int i=1;i<n-1;++i){
            if (arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                m[i]=true;
            }
        }
        for (int i=1;i<n-1;++i){
            if (m[i] && (i+2<n) && m[i+2]){
                ++c;
                arr[i+1]=max(arr[i],arr[i+2]);
                m[i+2]=false;
            }
            else if (m[i]){
                arr[i-1]=arr[i];++c;
            }
            m[i]=false;
        }

        cout<<c<<"\n";
        for (int i:arr) cout<<i<<" ";
        cout<<"\n";


    }


    return 0;
}

