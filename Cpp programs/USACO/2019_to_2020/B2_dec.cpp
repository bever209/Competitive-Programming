#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int n;
    cin >> n;
    string x;

    cin >> x;

    set<string> s;
    int ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        s.clear();
        int c = 0;
        for (int j = 0; j + i <= n; ++j)
        {
            s.insert(x.substr(j, i));
            ++c;
        }
        /*cout << s.size() << " " << c << "\n";
        for (string k : s)
        {
            cout << k << " ";
        }
        cout << "\n";*/

        if (s.size() == c)
        {
            ans = i;
            break;
        }
    }
    cout << ans;

    return 0;
}