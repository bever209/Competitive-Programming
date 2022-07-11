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

    double n;
    cin>>n;
    double ans=0;
    for (double i=1;i<n;++i){
        ans+=(n/(n-i));
    }
    cout<<fixed<<setprecision(20)<<ans;

    return 0;
}

