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
        vi ans;
        for (int i=0;i<=29;++i){
            int a=0,b=0;
            for (int j=0;j<ans.size();++j){
                a=a+pow(2,j)*(1-ans[j]);
                if (ans[j]==1) b=b-pow(2,j);
            }
            ++a;
            b=pow(2,30)+b+pow(2,i);
            cout<<"? "<<a<<" "<<b<<endl;
            int x;cin>>x;
            if (x%((int)pow(2,i+1))==0){
                ans.pb(1);
            }
            else{
                ans.pb(0);
            }
        }
        ll x=0;
        for (int i=0;i<=29;++i){
            x=x+pow(2,i)*ans[i];
        }
        cout<<"! "<<x<<endl;
    }



    return 0;
}

