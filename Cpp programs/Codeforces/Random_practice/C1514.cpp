#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    vector<int> ans;

    int x;
    cin >> x;
    int p = 1;
    for (int i = 1; i < x; ++i)
    {
        if (gcd(i, x) == 1)
        {
            ans.push_back(i);
            p = (1LL * p * i) % x;
        }
    }
    vector<int> final;
    int c = 0;
    for (int i : ans)
    {

        if (!(p != 1 && p == i))
        {
            final.push_back(i);
            c++;
        }
    }
    cout << c << "\n";
    for (int i : final)
    {
        cout << i << " ";
    }
}