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
map<pii,pii> ans;set<pii> con;
vector<pii> pts;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    for (int i=0;i<n;++i){
        pii a;cin>>a.f>>a.s;pts.pb(a);
        con.insert(a);
    }
    queue<pii> q;
    for (int i=0;i<n;++i){
        pii x=pts[i];
        for (int j=0;j<4;++j){
            int newx=x.f+dx[j];
            int newy=x.s+dy[j];
            if (!con.count({newx,newy})){
                ans[x]={newx,newy};q.push(x);
            }
        }
    }
    while (!q.empty()){
        pii top=q.front();q.pop();
        for (int j=0;j<4;++j){
            int newx=top.f+dx[j];
            int newy=top.s+dy[j];
            if (con.count({newx,newy}) && !ans.count({newx,newy})){
                ans[{newx,newy}]=ans[top];
                q.push({newx,newy});
            }
        }
    }

    vector<pii> vals(n);
    for (int i=0;i<n;++i) vals[i]=ans[pts[i]];
    for (auto i:vals){
        cout<<i.f<<" "<<i.s<<endl;
    }



    return 0;
}

