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
        ll n,s;cin>>n>>s;
        pair<ll,ll> arr[n];
        for (int i=0;i<n;++i) cin>>arr[i].f>>arr[i].s;



        ll low=0;
        ll high=1e9+1;
        while (low<high){
            bool check=true;
            ll mid=(low+1+high)/2;
            ll x=(n)/2;ll tot=0;int h=0;int l=0;
            for (int i=0;i<n;++i){
                if (arr[i].f>mid) {
                    tot += arr[i].f;
                    ++h;
                }
            }
            for (int i=0;i<n;++i){
                if (arr[i].s<mid){
                    ++l;tot+=arr[i].f;
                }
            }
            vi a;
            for (int i=0;i<n;++i){
                if (mid>=arr[i].f && mid<=arr[i].s){
                    a.pb(arr[i].f);
                }
            }
            sort(a.rbegin(),a.rend());
            for (int i=0;i<a.size();++i){
                if (h<(n+1)/2){
                    ++h;tot+=mid;
                }
                else{
                    ++l;tot+=a[i];
                }
            }
            if (tot>s) check=false;
            if (h<(n+1)/2) check=false;
            if (check){
                low=mid;
            }
            else{
                high=mid-1;
            }
        }
        cout<<low<<endl;

    }


    return 0;
}

