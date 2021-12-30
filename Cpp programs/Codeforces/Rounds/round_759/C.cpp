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
        int n,k;cin>>n>>k;
        ll arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        vector<ll> pos;vector<ll> neg;
        for (ll i:arr){
            if (i>0){
                pos.pb(i);
            }
            else if (i<0){
                neg.pb(-i);
            }
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        ll pos_ans=0;
        for (int i=pos.size()-1;i>=0;i-=k){
            pos_ans+=pos[i]*2;
        }
        ll neg_ans=0;
        for (int i=neg.size()-1;i>=0;i-=k){
            neg_ans+=neg[i]*2;
        }
        if (neg.size()==0 && pos.size()==0){
            cout<<pos_ans+neg_ans<<"\n";continue;
        }
        else if (pos.size()==0){
            cout<<pos_ans+neg_ans-neg[neg.size()-1]<<"\n";continue;
        }
        else if (neg.size()==0){
            cout<<pos_ans+neg_ans-pos[pos.size()-1]<<"\n";continue;
        }

        if (neg[neg.size()-1]>pos[pos.size()-1]){
            cout<<pos_ans+neg_ans-neg[neg.size()-1];
        }
        else{
            cout<<pos_ans+neg_ans-pos[pos.size()-1];
        }
        cout<<"\n";



    }


    return 0;
}

