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
        if (n%2==1){
            cout<<"Bob\n";continue;
        }
        int num=0;
        while (n%2==0){n/=2;++num;}
        if (n==1){
            if (num%2==1) cout<<"Bob\n";
            else cout<<"Alice\n";
        }
        else{
            cout<<"Alice\n";
        }
    }


    return 0;
}

