#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue
#define endl "\n"

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;


const ll inf = 2 * 1e18;
int offset='0';
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin>>tc;
    while (tc--){
        string s;cin>>s;string ans="";
        int n=s.length();
        for (int i=n-2;i>=0;--i){
            int num=s[i]-offset + s[i+1]-offset;
            if ((num) >=10){
                ans=s.substr(0,i)+to_string(num)+s.substr(i+2);break;
            }
        }
        if (ans!=""){
            cout<<ans<<endl;
        }
        else{
            int n=s.at(0)-offset+s.at(1)-offset;
            cout<<n<<s.substr(2)<<endl;
        }

    }


    return 0;
}

