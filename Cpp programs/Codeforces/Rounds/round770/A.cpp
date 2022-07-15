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
        int n,k;str s;cin>>n>>k>>s;
        if (k==0){
            cout<<"1\n";continue;
        }
        str x="";
        for (char i:s){
            x=x+i;
        }
        reverse(x.begin(),x.end());
        if (x==s){
            cout<<"1\n";
        }
        else{
            cout<<"2\n";
        }

    }

    return 0;
}

