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

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    string grid[n];
    for (int i=0;i<n;++i){
        cin>>grid[i];
    }
    int sr,sc,er,ec;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (grid[i].at(j)=='A'){
                sr=i;sc=j;
            }
            if (grid[i].at(j)=='B'){
                er=i;ec=j;
            }
        }
    }
    bool vis[n][m];
    string prev_move[n][m];
    string moves="RLUD";
    int dist[n][m];
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    queue<pii> q;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            vis[i][j]=false;
            prev_move[i][j]="X";
            dist[i][j]=0;
        }
    }

    q.push({sr,sc});
    while (!q.empty()){
        pii x=q.front();
        q.pop();
        int a,b;
        a=x.f;b=x.s;
        for (int i=0;i<4;++i){
            int nr=a+dx[i];
            int nc=b+dy[i];
            if (0<=nr && nr<n && 0<=nc && nc<m && grid[nr].at(nc)!='#' && !vis[nr][nc]){
                vis[nr][nc]=true;
                prev_move[nr][nc]=moves.at(i);
                dist[nr][nc]=dist[a][b]+1;
                q.push({nr,nc});
            }
        }
    }
    if (dist[er][ec]>0){
        cout<<"YES"<<endl;
        cout<<dist[er][ec]<<endl;
        string ans="";
        int r=er,c=ec;

        while (!(r==sr && c==sc)){
            string x=prev_move[r][c];
            ans+=x;
            if (x=="R"){
                --c;
            }
            if (x=="L"){
                ++c;
            }
            if (x=="U"){
                ++r;
            }
            if (x=="D"){
                --r;
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


    return 0;
}