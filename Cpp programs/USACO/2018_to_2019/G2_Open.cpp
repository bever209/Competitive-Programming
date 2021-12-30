#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using str=string;

const ll inf=2*1e18;

int main()
{


    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    ll n,m;cin>>n>>m;

    ll mod=2019201997;ll first=2019201913;ll sec=2019201949;
    cout<<(sec*n+first*(m-1)) % mod<<endl;

    return 0;
}

