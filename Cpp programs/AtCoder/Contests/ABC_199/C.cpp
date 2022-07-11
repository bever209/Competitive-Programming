#include <bits/stdc++.h>

#define pb push_back
//#define f first
//#define s second
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

    int n;string s;
    cin>>n>>s;
    int q;
    cin>>q;bool check=false;
    while (q--){
        int t,a,b;
        cin>>t>>a>>b;--a;--b;
        if (t==1){
            if (check){
                if (a>=n){a-=n;}
                else{a+=n;}
                if (b>=n){b-=n;}
                else{b+=n;}
            }
            char x=s[a];
            char y=s[b];

            s[a]=y;s[b]=x;

        }
        else{
            check=!check;
        }
    }
    if (check){
        for (int i=n;i<2*n;++i){
            cout<<s[i];
        }
        for (int i=0;i<n;++i){
            cout<<s[i];
        }
        return 0;
    }
    cout<<s;



    return 0;
}

