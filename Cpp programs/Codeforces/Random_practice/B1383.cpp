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


    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vi a(n);
        vi bits(31);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= 30; ++j) {
                if (a[i] & (int) (pow(2, j))) {
                    ++bits[j];
                }
            }
        }
        int ind = -1;
        for (int i = 30; i >= 0; --i) {
            if (bits[i] % 2 == 1) {
                ind = i;
                break;
            }
        }
        if (ind==-1){
            cout<<"DRAW"<<endl;continue;
        }
        int left=n-bits[ind];
        int num=bits[ind];

        if (num%4==3 && left%2==0){
            cout<<"LOSE"<<endl;
        }
        else{
            cout<<"WIN"<<endl;
        }
    }


    return 0;
}


