#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int c0=0;
    int c1=0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '0')
        {
            ++c0;
            if (c0%2==0){
                cout<<"3 1\n";
            }
            else{
                cout<<"1 1\n";
            }
        }
        else
        {
            ++c1;
            int x=c1%4;
            if (x==0){x=4;}
            cout<<x<<" 3"<<"\n";
        }
    }
    

    return 0;
}