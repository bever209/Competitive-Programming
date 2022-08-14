#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vivi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vpii a(n-1);
    for (int i=0;i<n-1;++i){
        int c,d;cin>>c>>d;--c;--d;
        a[i]={c,d};
    }
//    cout<<1<<endl;
    bool check=true;
    for (int i=0;i<n-1;++i){
        if (a[i].f!=n-1 && a[i].s!=n-1) check=false;
    }

    if (!check){
//        cout<<1<<endl;
        cout<<"NO";return 0;
    }

    vector<vi> adj(n);

    vi nums;
    for (int i=0;i<n-1;++i){
        if (a[i].f!=n-1) nums.pb(a[i].f);
        if (a[i].s!=n-1) nums.pb(a[i].s);
    }

    for (int i:nums){
        adj[n-1].pb(i);
        adj[i].pb(n-1);
    }

    vb used(n);
    used[n-1]=true;
    for (int i:nums) used[i]=true;

    vi c(n);
    for (int i=0;i<n-1;++i){
        c[a[i].f]++;c[a[i].s]++;
    }
    // number of times it appears

    for (int i=0;i<n-1;++i){
        c[i]--;
    }
    // number of numbers that should be between i and n-1

    for (int i=0;i<n-1;i++) {
        while (c[i]>0) {
            --c[i];
//            cout<<c[i]<<endl;
            int val = -1;
            for (int j = i - 1; j >= 0; --j) {
                if (!used[j]) {
                    val = j;
                    break;
                }
            }
            if (val==-1){
                cout<<"NO";
                return 0;
            }
            used[val]=true;
            int num =adj[i][0];
            adj[i].clear();
            adj[num].erase(remove(adj[num].begin(),adj[num].end(),i),adj[num].end());
            adj[i].pb(val);
            adj[val].pb(i);
            adj[num].pb(val);adj[val].pb(num);
        }

    }

    set<pii> ans;
    for (int i=0;i<n;++i){
        for (auto j:adj[i]){
            int cc=i,d=j;
            if (cc>d) swap(cc,d);
            ans.insert({cc,d});
        }
    }
    cout<<"YES"<<endl;
    for (auto i:ans){
        cout<<i.f+1<<" "<<i.s+1<<endl;
    }






    return 0;
}


