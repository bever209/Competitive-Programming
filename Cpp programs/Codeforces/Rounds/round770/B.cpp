#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        ll n,x,y;cin>>n>>x>>y;
        vi arr(n);
        for (int i=0;i<n;++i) cin>>arr[i];

        int odd=0;
        for (int i:arr){
            if (i%2==1) ++odd;
        }
        if ((odd+x) % 2 == (y) % 2){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
        }

    }


    return 0;
}

