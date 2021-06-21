#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair

using namespace std;
using ll = long long;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<ll> list;
    ll sum = 0;
    int left, right;
    for (int i = 0; i < n; ++i)
    {
       /* for (int j : list)
        {
            cout << j << " ";
        }
        cout << endl;*/
        if (arr[i] >= 0)
        {
            //list.pb(arr[i]);

            left = 0;
            right = list.size() - 1;
            if (right < left)
            {
                list.pb(arr[i]);
            }
            else
            {
                while (left < right)
                {
                    int mid = (left + right + 1) / 2;
                    if (list.at(mid) > arr[i])
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid;
                    }
                }
                if (list.at(left) >= arr[i])
                {
                    list.insert(list.begin() + left, arr[i]);
                }
                else
                {
                    list.insert(list.begin() + left + 1, arr[i]);
                }
            }
            sum += arr[i];
        }
        else
        {
            if (sum + arr[i] >= 0)
            {
                //list.pb(arr[i]);
                left = 0;
                right = list.size() - 1;
                if (right < left)
                {
                    list.pb(arr[i]);
                }
                else
                {
                    while (left < right)
                    {
                        int mid = (left + right + 1) / 2;
                        if (list.at(mid) > arr[i])
                        {
                            right = mid - 1;
                        }
                        else
                        {
                            left = mid;
                        }
                    }
                    if (list.at(left) >= arr[i])
                    {
                        list.insert(list.begin() + left, arr[i]);
                    }
                    else
                    {
                        list.insert(list.begin() + left + 1, arr[i]);
                    }
                }
                sum += arr[i];
            }
            else
            {
                if (list.size() > 0 && list.at(0) < arr[i])
                {
                    sum -= list.at(0);
                    sum += arr[i];
                    list.erase(list.begin());
                    //list.pb(arr[i]);
                    left = 0;
                    right = list.size() - 1;
                    if (right < left)
                    {
                        list.pb(arr[i]);
                    }
                    else
                    {
                        while (left < right)
                        {
                            int mid = (left + right + 1) / 2;
                            if (list.at(mid) > arr[i])
                            {
                                right = mid - 1;
                            }
                            else
                            {
                                left = mid;
                            }
                        }
                        if (list.at(left) >= arr[i])
                        {
                            list.insert(list.begin() + left, arr[i]);
                        }
                        else
                        {
                            list.insert(list.begin() + left + 1, arr[i]);
                        }
                    }
                }
            }
        }
    }
    cout << list.size() << endl;

    return 0;
}