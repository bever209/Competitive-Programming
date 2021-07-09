#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }


    bool a[2 * n];
    for (int i=0;i<2*n;++i){
        a[i]=false;
    }

    for (int i : arr)
    {
        a[i - 1] = true;
    }

    vector<int> not_used;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (!a[i])
        {
            not_used.pb(i + 1);
        }
    }



    int ans = 0;
    vector<int> first;
    for (int i=0;i<n/2;++i){
        first.pb(arr[i]);
    }

    sort(first.rbegin(),first.rend());
    int ind=n-1;
    for (int i=0;i<first.size();++i){
        if (not_used[ind]>first[i]){
            --ind;++ans;
        }
    }

    vector<int> second;
    for (int i=n/2;i<n;++i){
        second.pb(arr[i]);
    }
    sort(second.begin(),second.end());
    ind=0;
    for (int i=0;i<second.size();++i){
        if (not_used[ind]<second[i]){
            ++ind;++ans;
        }
    }

    cout << ans << endl;

    return 0;
}