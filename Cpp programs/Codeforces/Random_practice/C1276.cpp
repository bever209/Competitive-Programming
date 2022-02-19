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
#define endl "\n"


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;++i) cin>>arr[i];
    map<int,int> m;
    for (int i:arr){
        m[i]++;
    }
    vi poss;
    for (auto i:m) poss.pb(i.s);
    sort(poss.begin(),poss.end());
    int vals[n+2];
    vals[n+1]=0;
    int ind=poss.size()-1;
    for (int i=n;i>=0;--i){
        vals[i]=(vals[i+1]+(poss.size()-1-ind));
        while (ind>=0 && i==poss[ind]){
            --ind;
        }
    }
//    for (int i:vals) cout<<i<<" ";cout<<endl;


    pii ans;int best=0;
    for (int i=1;i<sqrt(n)+1;++i){
        int num=n-vals[i];
        int higher=num/i;
        if (i<=higher && higher * i>best){
            best=higher*i;ans={i,higher};
        }
    }
    vector<pii> f;
    for (auto i:m){
        f.pb({i.s,i.f});
    }
    sort(f.rbegin(),f.rend());
    vi a;
    ind=0;int num=ans.f*ans.s;
    while (num>0){
        int choose=min(f[ind].f,ans.f);
        choose=min(choose,num);
        for (int t=0;t<choose;++t) a.pb(f[ind].s);
        ++ind;
        num-=choose;
    }
//    for (int i:a) cout<<i<<" ";

    int i=0,j=0;
    int x[ans.f][ans.s];bool vis[ans.f][ans.s];
    for (int i=0;i<ans.f;++i) for (int j=0;j<ans.s;++j) vis[i][j]=false;
    cout<<ans.f*ans.s<<endl<<ans.f<<" "<<ans.s<<endl;
    for (int k=0;k<ans.f*ans.s;++k){
        if (vis[i][j]) i=(i+1) % ans.f;
        x[i][j]=a[k];
        vis[i][j]=true;
        i=(i+1) % ans.f;j=(j+1) % ans.s;

    }

    for (int i=0;i<ans.f;++i){
        for (int j=0;j<ans.s;++j){
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

