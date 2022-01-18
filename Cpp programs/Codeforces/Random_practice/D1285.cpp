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

int solve(vi a,int bit){ // every value is less than 2^bit
    if (bit==0) return 0;
    if (a.size()==0) return 0;
    if (a.size()==1) return 0;
    vi small;
    vi large;
    for (int i=0;i<a.size();++i){
        if (a[i]&(int)pow(2,bit-1)) {
            large.pb(a[i]);
        }
        else {
            small.pb(a[i]);
        }
    }
    if (small.size()==0) return solve(large,bit-1);
    if (large.size()==0) return solve(small,bit-1);

    return (int)pow(2,bit-1)+min(solve(small,bit-1),solve(large,bit-1));
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    sort(arr,arr+n);

    vi a;
    for (int i:arr) a.pb(i);

    cout<<solve(a,30);


    return 0;
}

