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
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];

    map<int,int> m;
    int f[n]; // furthest one to the right of same type

    for (int i=n-1;i>=0;--i){
        f[i]=i;
        if (m.count(arr[i])){
            f[i]=m[arr[i]];
        }
        else{
            m[arr[i]]=i;
        }
    }
    int pref[n];
    pref[0]=m[arr[0]];
    for (int i=1;i<n;++i){
        pref[i]=max(pref[i-1],m[arr[i]]);
    }

    int num=0;
    for (int i=0;i<n;){
        ++num;
        if (pref[i]==i) ++i;
        else i=pref[i];
    }
    cout<<n-num<<endl;




    return 0;
}

