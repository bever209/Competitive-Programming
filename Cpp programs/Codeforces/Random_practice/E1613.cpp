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
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};



int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        str arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        int lx, ly;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == 'L') {
                    lx = i;
                    ly = j;
                    break;
                }
            }
        }
        queue<pii> bfs;
        bfs.push({lx, ly});
        vector<vector<bool>> used(n, vector<bool>(m));
        vector<vi> out_deg(n, vi(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < 4; ++k) {
                    int new_x = dx[k] + i;
                    int new_y = dy[k] + j;
                    if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m) {
                        if (arr[new_x][new_y] != '#') ++out_deg[i][j];
                    }
                }

        used[lx][ly] = true;
        while (!bfs.empty()) {
            int x, y;
            tie(x, y) = bfs.front();
            bfs.pop();
            for (int i = 0; i < 4; ++i) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m) {
                    if (used[new_x][new_y] || arr[new_x][new_y] == '#') {
                        continue;
                    }
                    --out_deg[new_x][new_y];
                    if (out_deg[new_x][new_y] <= 1) {
                        used[new_x][new_y] = true;
                        bfs.push({new_x, new_y});
                    }
                }


            }

        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == 'L') {
                    cout << 'L';
                    continue;
                }
                if (arr[i][j] == '#') {
                    cout << '#';
                    continue;
                }
                if (used[i][j]) {
                    cout << '+';
                } else {
                    cout << '.';
                }
            }
            cout << "\n";
        }
    }


    return 0;
}

