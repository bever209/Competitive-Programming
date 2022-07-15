#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {

#define int ll
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n,c,q;cin>>n>>c>>q;

        str s;cin>>s;
        vpii a(c);
        for (int i=0;i<c;++i){
            int b,d;cin>>b>>d;--b;--d;
            a[i]={b,d};
        }
        vpii act(c);int ri=n;
        for (int i=0;i<c;++i){
            act[i]={ri,ri+a[i].s-a[i].f};
            ri+=(a[i].s-a[i].f+1);
        }

        while (q--){
            int pos;cin>>pos;--pos;
            for (int i=c-1;i>=0;--i){
                if (act[i].f<=pos && act[i].s>=pos){
                    pos=(pos-act[i].f)+a[i].f;
                }
            }
            cout<<s[pos]<<endl;

        }

    }


    return 0;
}

