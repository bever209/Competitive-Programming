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
int n;
bool check(int arr[]){
    int c=0;
    for (int i=0;i<n;++i){
        if (arr[i]==1) ++c;
    }
    if (c!=1) return false;
    for (int i=1;i<n;++i){
        if ((arr[i]-arr[i-1])>1) return false;
    }
    if (arr[0]-arr[n-1] >1) return false;
    return true;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        cin>>n;
        int arr[n];
        for (int i=0;i<n;++i) cin>>arr[i];
        if (check(arr)){
            cout<<"yes";

        }
        else cout<<"no";
        cout<<endl;

    }


    return 0;
}

