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

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        string s;cin>>s;

        string t="";
        for (int i=0;i<n;++i){
            t+=s[i];
        }
        int ind=0;
        while (ind<n && t[ind]=='?'){
            if (ind%2==0){
                t[ind]='B';
            }
            else{
                t[ind]='R';
            }
            ++ind;
        }
        if (ind!=n){
            for (int i=ind-1;i>=0;--i) {
                if (t[i + 1] == 'B') {
                    t[i] = 'R';
                } else {
                    t[i] = 'B';
                }
            }

        }
        for (int i=ind=1;i<n;++i){
            if (t[i]=='?') {
                if (t[i - 1] == 'R') {
                    t[i] = 'B';
                } else {
                    t[i] = 'R';
                }
            }
        }
        cout<<t<<endl;

    }


    return 0;
}

