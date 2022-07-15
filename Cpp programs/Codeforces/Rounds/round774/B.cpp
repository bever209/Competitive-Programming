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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        ll arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        bool check=false;
        ll sum=0;
        ll tot=0;
        for (auto i:arr) tot+=i;
        ll other=arr[0];
        for (int i=n-1;i>=0;--i){
            sum+=arr[i];
            other+=arr[n-i];
            if (sum>other && i>(n-i)){
                check=true;break;
            }
        }
        if (check){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }


    return 0;
}

