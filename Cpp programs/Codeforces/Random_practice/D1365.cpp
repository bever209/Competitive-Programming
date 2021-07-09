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
vector<string> grid;
int num_g=0;
vector<vector<bool>> vis;
const int n,m;
void dfs(int r, int c){
    vis[r][c]=true;
    if (grid[r].at(c)=='G'){
        num_g++;
    }
    for (int a=-1;a<=1;++a){
        for (int b=-1;b<=1;++b){
            if ((a+2)%2!=(b+2)%2) {
                int ni = r + a;
                int nj = c + b;
                if (0 <= ni && 0 <= nj && ni < n && nj < m &&
                    grid[ni].at(nj) != '#' && !vis[ni][nj]) {
                    dfs(ni,nj);
                }
            }
        }
    }
}

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);



    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        cin>>n>>m;
        grid.resize(n);
        for (int i=0;i<n;++i){
            cin>>grid[i];
        }
        int need=0;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (grid[i].at(j)=='G'){
                    ++need;
                }
            }
        }

        bool check=true;
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                if (grid[i].at(j)=='B'){
                    for (int a=-1;a<=1;++a){
                        for (int b=-1;b<=1;++b){
                            if ((a+2)%2!=(b+2)%2) {
                                int ni = i + a;
                                int nj = j + b;
                                if (0 <= ni && 0 <= nj && ni < n && nj < m &&
                                    grid[ni].at(nj) != 'B') {
                                    if (grid[ni][nj]=='G' || (ni==n-1 && nj==m-1)){
                                        check=false;
                                    }
                                    grid[ni][nj] = '#';

                                }
                            }
                        }
                    }
                }
            }
        }
        num_g=0;
        vis.resize(n);
        for (int i=0;i<n;++i){
            vis[i].resize(m);
            for (int j=0;j<m;++j){
                vis[i][j]=false;
            }
        }
        dfs(n-1,m-1);

        if ((need==num_g && check)|| need==0)
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }



    return 0;
}