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

#define int ll
    int n,q;cin>>n>>q;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];
    sort(arr,arr+n);
    int pref[n];
    pref[0]=arr[0];
    for (int i=1;i<n;++i) pref[i]=arr[i]+pref[i-1];
    while (q--){
        int x,y;cin>>x>>y;
        int low=n-x-1;
        int high=low+y;

        if (low<0){
            cout<<pref[high]<<endl;
        }
        else{
            cout<<pref[high]-pref[low]<<endl;
        }
    }

    return 0;
}

