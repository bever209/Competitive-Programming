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
    while (tc--){
        int n;cin>>n;
        int arr[n];
        for (int i=0;i<n;++i){
            cin>>arr[i];
        }
        int even=0;int odd=0;
        vi leven;vi lodd;
        for (int i=0;i<n;++i){
            if (arr[i]%2==0){
                leven.pb(i);
                ++even;
            }
            else{
                ++odd;
                lodd.pb(i);
            }
        }
        if (n%2==0){
            if (even!=odd){
                cout<<-1<<"\n";
            }
            else{
                ll ans1=0;
                for (int i=0;i<lodd.size();++i){
                    ans1+=(abs(lodd[i]-2*i));
                }
                ll ans2=0;
                for (int i=0;i<leven.size();++i){
                    ans2+=(abs(leven[i]-2*i));
                }
                cout<<min(ans1,ans2)<<"\n";
            }
        }
        else{
            if (even>odd){
                if (even-1!=odd){
                    cout<<-1<<"\n";
                }
                else{
                    ll ans=0;
                    for (int i=0;i<leven.size();++i){
                        ans+=(abs(leven[i]-2*i));
                    }
                    cout<<ans<<"\n";
                }
            }
            else{
                if (odd-1!=even){
                    cout<<-1<<"\n";
                }
                else{
                    ll ans=0;
                    for (int i=0;i<lodd.size();++i){
                        ans+=(abs(lodd[i]-2*i));
                    }
                    cout<<ans<<"\n";
                }
            }
        }

    }

    return 0;
}

