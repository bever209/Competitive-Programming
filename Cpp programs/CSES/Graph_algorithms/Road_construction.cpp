#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;


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

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    int mx=1;int num=n;
    for (int i=0;i<m;++i){
        int a,b;cin>>a>>b;
        --a;--b;
        if (!dsu.same_set(a,b)){
            --num;
        }
        dsu.unite(a,b);
        mx=max(mx,dsu.size(a));
        cout<<num<<" "<<mx<<endl;
    }

    return 0;
}
