#include <bits/stdc++.h>

//#define pb push_back
//#define f first
//#define s second
//#define mp make_pair
//#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;


string nextWord(string s)
{
    int i = s.length() - 1;
    while (s[i] == 'z' && i >= 0)
        i--;
    // If all characters are 'z', append
    // an 'a' at the end.
    if (i == -1) {
        string t = "";
        for (int j=0;j<=s.length();++j){
            t+="a";
        }
        return t;

    }
        // If there are some non-z characters
    else {
        s[i]++;

        return s;
    }
}

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin>>t;
    for (int v=0;v<t;++v){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string a="a";
        while (true) {

            if (s.find(a) != std::string::npos) {
                a = nextWord(a);
            } else {
                cout << a << endl;
                break;
            }
        }
    }


    return 0;
}

