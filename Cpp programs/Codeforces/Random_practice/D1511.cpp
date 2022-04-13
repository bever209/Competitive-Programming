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

    int n, k;
    cin >> n >> k;
    char offset = 'a';

    str ans = "";
    int c = 0;
    while (c < n) {
        for (int i = 0; i < k; ++i) {
            if (c<n) {
                cout<<(char) (i + offset);++c;
            }
            for (int j = i + 1; j < k; ++j) {
                if (c<n){
                    cout<<(char) (i + offset);++c;
                }
                if (c<n){
                    cout<<(char) (j + offset);++c;
                }
            }
        }
    }


    /*str a=ans;
    while (ans.size()<n){
        ans=ans+a;
    }
    cout<<ans.substr(0,n);*/


    return 0;
}

