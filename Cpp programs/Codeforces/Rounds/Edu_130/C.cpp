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
        str s,t;cin>>s>>t;
        vi a1;
        vi a2;
        for (int i=0;i<n;++i){
            if (s[i]=='a') a1.pb(i);
            if (t[i]=='a') a2.pb(i);
        }
        vi c1;
        vi c2;
        for (int i=0;i<n;++i){
            if (s[i]=='c') c1.pb(i);
            if (t[i]=='c') c2.pb(i);
        }
        if (a1.size()!=a2.size() || c1.size()!=c2.size()){
            cout<<"NO"<<endl;continue;
        }
        bool check=true;
        for (int i=0;i<a1.size();++i){
            if (a1[i] > a2[i]){
                check=false;
            }
        }
        for (int i=0;i<c1.size();++i){
            if (c1[i]<c2[i]) check=false;
        }

        if (!check){
            cout<<"NO"<<endl;continue;
        }
        str ss="";
        str tt="";
        for (int i=0;i<n;++i){
            if (s[i]!='b') ss+=s[i];
            if (t[i]!='b') tt+=t[i];
        }
        if (ss==tt){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}

