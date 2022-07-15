#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll=pair<ll,ll>;
using vi = vector<int>;
using vb=vector<bool>;
using vll=vector<ll>;
using vpii=vector<pii>;
using str = string;

const ll inf = 2 * 1e18;
const ll mod=998244353;
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n,s;cin>>n>>s;

        vll a(n);vll b(n);
        for (int i=0;i<n;++i) cin>>a[i],--a[i];
        for (int i=0;i<n;++i) {
            cin >> b[i];
            if (b[i]>0) --b[i];
        }

        vb seen(n);
        for (int i:b) if (i>=0) seen[i]=true;

        vi left;
        for (int i=0;i<n;++i) if (!seen[i]) left.pb(i);

        vi match;
        for (int i=0;i<n;++i) if (b[i]==-1) match.pb(a[i]);
        sort(match.begin(),match.end());

        bool check=true;
        for (int i=0;i<n;++i){
            if (b[i]>=0){
                if (abs(a[i]-b[i])>s){
                    check=false;break;
                }
            }
        }
        if (!check){
            cout<<0<<endl;continue;
        }

        ll ans=1;
        int left_ind=0;
        int right_ind=0;
        for (int i=0;i<left.size();++i){
            while (right_ind<left.size() && match[right_ind]-left[i]<=s) ++right_ind;
            while (left_ind<left.size() && left[i]-match[left_ind]>s) ++left_ind;

            ll seen_before=i;
            ll choices=right_ind-left_ind;
            ll overlap=seen_before-left_ind;
//            cout<<left_ind<<" "<<right_ind<<endl;
//            cout<<choices<<" "<<overlap<<endl;
            ans=(ans*(choices-overlap+mod))%mod;

            if (abs(left[i]-match[left_ind])>s || choices<overlap) ans=0;
        }
        cout<<ans<<"\n";

//DEAL WITH LONG LONGS EVERYWHERE


    }


    return 0;
}

