#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll=pair<ll,ll>;
using vi = vector<int>;
using vb=vector<bool>;
using vll=vector<ll>;
using vpii=vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

vi q(int l,int r){
    cout<<"? "<<(l+1)<<" "<<(r+1)<<endl;
    vi a(r-l+1);
    for (int & i : a) cin>>i,--i;
    return a;
}
void ans(int x){
    ++x;
    cout<<"! "<<x<<endl;

}
// RESPONSES COME IN 1-INDEXED, BUT WE ARE DEALING WITH 0-INDEXED IN THE PROGRAM
int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;

    while (tc--){
        int n;cin>>n;
        int l=0;
        int r=n-1;
        while (l<r) {
            int mid = (l + r) / 2; // check
            vi a = q(l, mid);
            int diff = 0;
            int prop = 0;
            for (int i:a) {
                if (i <= mid && i >= l) ++prop;
                else ++diff;
            }
            if (prop%2==0){
                l=mid+1;
            }
            else r=mid;
        }
        ans(l);

    }


    return 0;
}

