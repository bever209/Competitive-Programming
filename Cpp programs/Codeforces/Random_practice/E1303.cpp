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
const int maxn=405;
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        str a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        bool check = false;
        // need to calculate next char after or on index x
        vector<vi> ind(n, vi(26, -1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if (a.at(i) - 'a' == j)
                    ind[i][j] = i;
                else {
                    if (i < n - 1) ind[i][j] = ind[i + 1][j];
                }
            }
        }

        for (int aa = 0; aa < m && !check; ++aa) {
            str x;
            str y;
            for (int j = 0; j <aa; ++j) x += b.at(j);
            for (int j = aa; j < m; ++j) y += b.at(j);


            vector<vi> dp(maxn, vi(maxn, n +
                                       10));
            // dp[i][j] means minimum length needed to get prefix of length i and j from first two strings

            dp[0][0] = 0;
            for (int i = 0; i <= x.size(); ++i) {
                for (int j = 0; j <= y.size(); ++j) {
                    int len=dp[i][j];
                    if (len>=n) continue;

                    if (i!=x.size()) {
                        char xx = x[i];
                        if (ind[len][xx - 'a'] >= 0) {
                            int new_len = ind[len][xx - 'a'] + 1;
                            dp[i + 1][j] = min(dp[i + 1][j], new_len);
                        }
                    }

                    if (j!=y.size()) {
                        char yy = y[j];
//                        cout<<"made "<<i<<" "<<j<<" "<<len<<endl;
                        if (ind[len][yy - 'a'] >= 0) {
                            int new_len = ind[len][yy - 'a'] + 1;
                            dp[i][j + 1] = min(dp[i][j + 1], new_len);
                        }
                    }
                }
            }
//            for (int i=0;i<=x.size();++i){ for (int j=0;j<=y.size();++j) cout<<dp[i][j]<<" ";cout<<endl;}

            if (dp[x.size()][y.size()] <= n) check = true;
        }
        if (check) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }


    return 0;
}

