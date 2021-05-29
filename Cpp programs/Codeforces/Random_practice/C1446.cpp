#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second

using namespace std;
using ll = long long;

int solve(int bit, vector<int> v)
{
    if (bit < 0)
    {
        return 0;
    }
    if (v.size() <= 3)
    {
        return v.size();
    }
    vector<int> a;
    vector<int> b;
    for (int i:v)
    {
        if (i & (1 << bit))
        {
            a.pb(i);
        }
        else
        {
            b.pb(i);
        }
    }

    if (b.size() == 0)
    {
        return solve(bit - 1, a);
    }
    if (a.size() == 0)
    {
        return solve(bit - 1, b);
    }

    return 1 + max(solve(bit - 1, a), solve(bit - 1, b));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        arr.pb(x);
    }

    cout << n - solve(30, arr);

    return 0;
}