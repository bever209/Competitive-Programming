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
        int a,b,c;cin>>a>>b>>c;
        if ((a+b+c)%9==0){
            int x=min(a,min(b,c));
            int num=(a+b+c)/9;
            if (x>=num){
                cout<<"yes"<<endl;continue;
            }

        }
        cout<<"no"<<endl;

    }


    return 0;
}

