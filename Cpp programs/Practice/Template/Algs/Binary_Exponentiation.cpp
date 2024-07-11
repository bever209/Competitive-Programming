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




const ll mod=998244353; // subject to change
ll binpow(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1)
            res = (res*a) % mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

