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


    int tc;cin>>tc;
    while (tc--) {
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        ll ans=0;
        ll odd=0;ll even=0;ll c=0;ll mx=0;
        for (int i=1;i<n-1;++i){
            c = c+((arr[i]+1)/2);mx=max(mx,arr[i]);
            if (arr[i]%2==0){
                ++even;
            }
            else{
                ++odd;
            }
        }

        if (mx==1 || (odd==1 && n==3)){
            cout<<"-1\n";
        }
        else{
            cout<<c<<"\n";
        }
    }


    return 0;
}

