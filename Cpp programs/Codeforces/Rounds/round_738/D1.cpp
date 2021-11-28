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
struct DSU {
    vector<int> e;
    DSU(int N) { e = vi (N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int m1;cin>>m1;
    DSU dsu1(n);

    DSU dsu2(n);
    int m2;cin>>m2;
    for (int i=0;i<m1;++i){
        int a,b;cin>>a>>b;--a;--b;
        dsu1.unite(a,b);
    }
    for (int i=0;i<m2;++i){
        int a,b;cin>>a>>b;--a;--b;
        dsu2.unite(a,b);
    }

    vector<pii> ans;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            if (!dsu1.same_set(i,j) && !dsu2.same_set(i,j)){
                ans.pb({i,j});
                dsu1.unite(i,j);dsu2.unite(i,j);
            }
        }
    }
    cout<<ans.size()<<"\n";
    for (auto i:ans){
        cout<<i.f+1<<" "<<i.s+1<<"\n";
    }


    return 0;
}

