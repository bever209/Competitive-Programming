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
        str arr[n];bool ans=false;
        for (int i=0;i<n;++i){
            cin>>arr[i];
            if (arr[i][0]==arr[i][arr[i].size()-1]){
                ans=true;
            }
        }
        set<str> s;
        for (int i=0;i<n && !ans;++i){
            str x=arr[i];
            reverse(x.begin(),x.end());
            if (s.count(x)){
                ans=true;break;
            }
            if (arr[i].size()==3){
                str y="";y.pb(arr[i].at(2));y.pb(arr[i].at(1));
                if (s.count(y)){
                    ans=true;break;
                }

            }
            if (arr[i].size()==2){
                str y="";y.pb(arr[i][1]);y.pb(arr[i][0]);
                for (char a='a';a<='z';++a){
                    if (s.count(y+a)){
                        ans=true;break;
                    }
                }
            }
            s.insert(arr[i]);
        }
        if (ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}

