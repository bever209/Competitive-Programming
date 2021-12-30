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
    cin>>tc;
    while (tc--){
        int n;cin>>n;
        ll arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        int num=0;

        for (int i=0;i<n;++i){
            while (arr[i]%2==0){
                arr[i]/=2;++num;
            }
        }
        sort(arr,arr+n);
        while (num>0){
            arr[n-1]*=2;--num;
        }
        ll sum=0;
        for (ll i:arr){
            //cout<<sum<<endl;
            sum+=i;
        }
        cout<<sum<<"\n";
    }

    return 0;
}

