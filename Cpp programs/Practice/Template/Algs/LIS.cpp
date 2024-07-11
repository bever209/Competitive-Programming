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

int find_lis(vector<int> a) {
    vector<int> dp;
    for (int i : a) {
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == dp.size()) {
            // we can have a new, longer increasing subsequence!
            dp.push_back(i);
        } else {
            // oh ok, at least we can make the ending element smaller
            dp[pos] = i;
        }
    }
    return dp.size();
}

