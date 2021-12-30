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

ll gcd(ll a,ll b){
    if (a==0) return b;
    if (b==0) return a;

    if (a>b){
        return gcd(a%b,b);
    }
    return gcd(b%a,a);
}

bool solve(ll a,ll b,ll x){
    if (a<x && b<x) return false;
    if (x%gcd(a,b) !=0) return false;

    if (a>b) swap(a,b);
    if (x%a==b%a) return true;
    return solve(b%a,a,x);

}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);int tc;cin>>tc;

    while (tc--){
        ll a,b,x;cin>>a>>b>>x;
        if (solve(a,b,x)) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}

