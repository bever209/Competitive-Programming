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

ll solve(vector<ll> arr){
    int odd=0;
    for (auto i:arr) if (i%2==1) ++odd;

    ll sum=0;
    for (auto i:arr) sum+=i;
    ll num=2 * (sum/3);


    if (sum%3==1) ++num;
    else if (sum%3==2) num+=2;

    ll ans=max((ll)2*odd-1,num);
    return ans;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--){
        int n;cin>>n;
        vector<ll> arr(n);
        for (int i=0;i<n;++i) cin>>arr[i];

        sort(arr.begin(),arr.end());

        ll x=arr[n-1];
        for (int i=0;i<n;++i){
            arr[i]=x-arr[i];
        }
        // how many we need

        ll ans=solve(arr);
        for (int i=0;i<n;++i) arr[i]++;
        ans=min(ans,solve(arr));


        cout<<ans<<endl;




    }


    return 0;
}

