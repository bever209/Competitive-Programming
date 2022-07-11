#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;

map<ll,ll> m;vi ans;

int main() {

    m[-1]=0;
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
#define int ll

    int n, p;
    cin >> n >> p;swap(n,p);
    pair < pii, pii > arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i].f.f >> arr[i].f.s >> arr[i].s.f >> arr[i].s.s;


    ans.resize(n);

    vector<pair<pii, pii>> ends;
    for (int i = 0; i < n; ++i) {
        ends.pb({arr[i].f, {1, i}});
        ends.pb({arr[i].s, {-1, i}});
    }
    sort(ends.begin(), ends.end());

    for (auto i:ends) {
        auto x = i.f; // coordinates
        int index = i.s.s;
        if (i.s.f == 1) { // starting
            auto it = prev(m.upper_bound(x.s));
            ans[index] = i.f.s + i.f.f + it->s;
        } else { // ending
            int y = x.s;
            int val = ans[index] - x.f - x.s;
            auto it = prev(m.upper_bound(y));
            if (it->s <= val)
                continue;
            ++it;
//            cout<<1<<endl;
            while (it!=m.end() && it->s>val){
//                cout<<it->s<<endl;
                m.erase(it++);
            }
//            cout<<2<<endl;
            m[y]=val;

        }
    }

    int a=2*p;
    for (int i=0;i<ends.size();++i){
        int index=ends[i].s.s;
        a=min(a,ans[index]+(p-arr[index].s.s)+(p-arr[index].s.f));
    }
    cout<<a;


    return 0;
}

