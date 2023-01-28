#include <bits/stdc++.h>
#define mp make_pair
#define pq priority_queue
//#pragma GCC target ("avx2")
#define pb push_back
#define f first
#define s second
//#pragma GCC optimize ("Ofast")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using str = string;
using vivi = vector<vi>;

using vll = vector<ll>;
using vpii = vector<pii>;
using vb = vector<bool>;
using vd=vector<double>;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);cin.tie(0);

    int n;cin>>n;
    vd x(n);
    for (int i=0;i<n;++i) cin>>x[i];

    vector<vd> ord(n);
    for (int i=0;i<n;++i){
        double prev=1e9+1;
        for (int j=i-1;j>=0;--j){
            double slope=(x[i]-x[j])/(i-j);
            if (slope<=prev){
                ord[i].pb(j);prev=slope;
            }
        }
        reverse(ord[i].begin(),ord[i].end());
    }

    int q;cin>>q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a;
        // index is a, increase amt is b
        x[a] += b;

        ll ans = 0;
        for (int i = 0; i < a; ++i) ans += ord[i].size();

        ord[a].clear();
        double prev = 1e9 + 1; // RECALCULATING FOR A
        for (int i = a - 1; i >= 0; --i) {
            double slope = (x[a] - x[i]) / (a - i);
            if (slope <= prev) {
                ord[a].pb(i);
                prev = slope;
            }
        }
        reverse(ord[a].begin(), ord[a].end());
        if (a + 1 != n) {
            ord[a + 1].clear(); // edge case if a=n-1
            prev = 1e9 + 1; // RECALCULATING FOR A+1
            for (int i = a; i >= 0; --i) {
                double slope = (x[a + 1] - x[i]) / (a + 1 - i);
                if (slope <= prev) {
                    ord[a + 1].pb(i);
                    prev = slope;
                }
            }
            reverse(ord[a + 1].begin(), ord[a + 1].end());
        }

        for (int i = a + 2; i < n; ++i) {
            ord[i].clear();
            if (x[i]<x[i-1]) {
                double slope = (x[i] - x[i - 1]) / (1);
                int ind = i - 1;
                ord[i].pb(ind);
                while (ind > 0) {
                    int low = 0;
                    int high = ord[ind].size() - 1;
                    while (low < high) {
                        int mid = (low + high + 1) / 2;
                        if ((x[ind] - x[mid]) / (ind - mid) <= slope) {
                            low = mid;
                        } else high = mid - 1;
                    }
                    if ((x[ind] - x[low]) / (ind - low) <= slope) {
                        slope = (x[ind] - x[low]) / (ind - low);
                        ind = low;
                        ord[i].pb(ind);
                    } else break;
                }
            }
            else{
                prev=1e9+1;
                for (int j=i-1;j>=0;--j){
                    double slope=(x[i]-x[j])/(i-j);
                    if (slope<=prev){
                        ord[i].pb(j);prev=slope;
                        if (x[j]>x[i]){
                            double slope = (x[i] - x[j]) / (1);
                            int ind = j;
                            ord[i].pb(ind);
                            while (ind > 0) {
                                int low = 0;
                                int high = ord[ind].size() - 1;
                                while (low < high) {
                                    int mid = (low + high + 1) / 2;
                                    if ((x[ind] - x[mid]) / (ind - mid) <= slope) {
                                        low = mid;
                                    } else high = mid - 1;
                                }
                                if ((x[ind] - x[low]) / (ind - low) <= slope) {
                                    slope = (x[ind] - x[low]) / (ind - low);
                                    ind = low;
                                    ord[i].pb(ind);
                                } else break;
                            }
                        }
                    }
                }
            }
            reverse(ord[i].begin(),ord[i].end());
        }

//        for (auto i:ord) {
//            for (int j:i) cout << j << " ";
//            cout << endl;
//        }


        for (int i = a; i < n; ++i) ans += ord[i].size();
        cout << ans << endl;

    }


    return 0;
}


