#include <bits/stdc++.h>

#define pb push_back
#define f first
//#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using str = string;

const ll inf = 2 * 1e18;

struct node {
    int a, b, c, ab, bc, abc;

    node() {
        a = b = c = ab = bc = abc = 0;
    }

    node(char x) {
        a = b = c = ab = bc = abc = 0;
        if (x == 'a') {
            a = 1;
        }
        if (x == 'b') {
            b = 1;
        }
        if (x == 'c') {
            c = 1;
        }
    }

    node(int q, int w, int e, int r, int t, int y) {
        a = q;
        b = w;
        c = e;
        ab = r;
        bc = t;
        abc = y;
    }

    node operator+(const node &o) const {
        node X;
        X.a = a + o.a;
        X.b = b + o.b;
        X.c = c + o.c;
        X.ab = min(ab + o.b, a + o.ab);
        X.bc = min(bc + o.c, b + o.bc);
        X.abc = min({a + o.abc, ab + o.bc, abc + o.c});
        return X;
    }
};

vector<node> st;
int n;
string s;

void comb(int x){
    st[x]=st[2*x+1]+st[2*x+2];
}

void update(int x, int l, int r, char val, int q) {
    if (l > q || r < q) {
        return;
    }
    if (q == l && q == r) {
        st[x] = node(val);
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= q) {
        update(x * 2 + 1, l, mid, val, q);
    } else {
        update(x * 2 + 2, mid + 1, r, val, q);
    }
    comb(x);
}

void update(int q,char val) {
    update(0, 0, n - 1, val, q);
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> n >> q;
    cin >> s;
    st.resize(4 * n + 10);
    for (int i = 0; i < n; ++i) {

        update(i, s.at(i));
    }
    while (q--) {
        int ind;
        char x;
        cin >> ind >> x;
        --ind;
        update(ind, x);
        cout << st[0].abc << "\n";
    }


    return 0;
}

