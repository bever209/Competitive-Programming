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
//    freopen("cardgame.in","r",stdin);
//    freopen("cardgame.out","w",stdout);

    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    vi there(2*n+1,false); //ignore 0
    for (int i:arr){
        there[i]=true;
    }
    vi bess;
    for (int i=1;i<2*n+1;++i){
        if (!there[i]){
            bess.pb(i);
        }
    }
    vi pref(n,0);
    set<int> set;
    for (int i:bess){
        set.insert(i);
    }
    for (int i=0;i<n;++i){
        auto x= set.upper_bound(arr[i]);
        if (i!=0){
            pref[i]=pref[i-1];
        }
        if (x!=set.end()){
            set.erase(*x);
            ++pref[i];
        }

    }
    set.clear();
    for (int i:bess){
        set.insert(i);
    }
    vi suff(n,0);
    for (int i=n-1;i>=0;--i){
        auto x= set.upper_bound(arr[i]);
        if (i!=n-1){
            suff[i]=suff[i+1];
        }

        if (x!=set.begin()){
            --x;
            set.erase(*x);
            ++suff[i];
        }
    }
    int ans=0;
    for (int i=0;i<n-1;++i){
        ans=max(ans,pref[i]+suff[i+1]);
    }
    ans=max(ans,suff[0]);
    ans=max(ans,pref[n-1]);
    cout<<ans<<endl;

    return 0;
}

