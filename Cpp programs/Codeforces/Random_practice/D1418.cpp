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

    int n, q;
    cin >> n >> q;
    set<int> s;
    multiset<int> m;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
        arr[i] = x;
    }
    sort(arr, arr + n);
    for (int i = 1; i < n; ++i) m.insert(arr[i] - arr[i - 1]);

    if (m.size() <= 1)
        cout << 0 << endl;
    else
        cout << *(--s.end()) - *s.begin() - *(--m.end()) << endl;

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {

            s.insert(b);
            auto i =s.find(b);
            if (i!=s.begin()){
                m.insert(b-*prev(i));
            }
            if (next(i)!=s.end()){
                m.insert(*next(i)-b);
                if (i!=s.begin()){
                    m.erase(m.find(*next(i)-*prev(i)));
                }
            }

        }
        else{
            auto i=s.find(b);
            if (next(i)!=s.end()){
                m.erase(m.find(*next(i)-b));
            }
            if (i!=s.begin()){
                m.erase(m.find(b-*prev(i)));
                if (next(i)!=s.end()){
                    m.insert((*next(i)-*prev(i)));
                }
            }
            s.erase(b);

        }

        if (m.size() <= 1)
            cout << 0 << endl;
        else
            cout << *(--s.end()) - *s.begin() - *(--m.end()) << endl;
    }


    return 0;
}

