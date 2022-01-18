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
    int n;cin>>n;
    string s,t;cin>>s>>t;
    vector<char> v;
    int n1=0;int n2=0;
    for (int i=0;i<n;++i){
        if (s.at(i)!=t.at(i)){
            v.pb(s.at(i));
        }
        if (s.at(i)=='1') ++n1;
        if (t.at(i)=='1') ++n2;
    }
    if (n1!=n2){
        cout<<-1<<endl;
    }
    else{
        int ans=0;
        int c0=0;int c1=0; // ready for c0 (0) and c1 (1)
        for (int i=0;i<v.size();++i){
            if (v[i]=='0'){
                if (c0==0){
                    ++ans;++c1;
                }
                else{
                    --c0;++c1;
                }
            }
            else{
                if (c1==0){
                    ++ans;++c0;
                }
                else{
                    --c1;++c0;
                }
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}

