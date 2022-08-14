#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vivi = vector<vi>;
using vb = vector<bool>;
using vll = vector<ll>;
using vpii = vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    int x=pow(2,n-1)/2;

    int p=1;str fin;
    cout<<"0 1"<<endl;
    str s;cin>>s;fin=s;
    int t=x;
    int final_t=t;
    while (p<n){
        ++p;

        cout<<t<<" 1"<<endl;final_t=t;
        str ss;cin>>ss;fin=ss;

        if (ss==s){
            t+=x/2;
        }
        else t-=x/2;

        x=x/2;

    }
    int d=t;
    if (fin==s) ++d;
    cout<<d-1<<" 0"<<" "<<d<<" 2"<<endl;


    return 0;
}


