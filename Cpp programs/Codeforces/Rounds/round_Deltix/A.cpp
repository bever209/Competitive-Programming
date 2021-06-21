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

    int t;
    cin >> t;
    for (int v = 0; v < t; ++v)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        bool check = false;
        for (int i = 0; i < n; ++i)
        {
            if (s.at(i) == '1')
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            int first=-1;int last=-1;
            for (int i=0;i<n;++i){
                if (s.at(i)=='1'){
                    if (first==-1){
                        first=i;
                    }
                    last=i;
                }
            }
            for (int i=first-1;i>=0;--i){
                if (first-i<=m){
                    s.at(i)='1';
                }
            }
            for (int i=last+1;i<n;++i){
                if (i-last<=m){
                    s.at(i)='1';
                }
            }
            int cnt = 0;
            int start_ind;
            int end_ind;
            for (int i = first; i <= last; ++i)
            {
                if (s.at(i) == '1')
                {
                    end_ind = i - 1;
                    int num = min(cnt / 2, m);
                    for (int i = start_ind; i <= end_ind; ++i)
                    {
                        if (i - start_ind+1 <= num || end_ind - i+1 <= num)
                        {
                            s.at(i) = '1';
                        }
                    }
                    cnt = 0;
                }
                else
                {
                    if (cnt == 0)
                    {
                        start_ind = i;
                    }
                    ++cnt;
                }
            }

            cout << s << endl;
        }
        else
        {
            cout << s << endl;
        }
    }

    return 0;
}