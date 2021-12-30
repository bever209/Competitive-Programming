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


    int n,q;cin>>n>>q;
    string s;cin>>s;
    int start[n];int c=0;
    for (int i=0;i<n;++i){
        start[i]=0;
        if (i+2<n && s[i]=='a' && s[i+1]=='b' && s[i+2]=='c'){
            start[i]=1;++c;
        }
    }
    while (q--){
        int a;char b;cin>>a>>b;
        --a;
        s[a]=b;
        if (a-2>=0){
            if (s[a-2]=='a' && s[a-1]=='b' && s[a]=='c'){
                c+=(1-start[a-2]);start[a-2]=1;
            }
            else{
                c+=(0-start[a-2]);start[a-2]=0;
            }

        }
        if (a-1>=0 && a+1<n){
            if (s[a-1]=='a' && s[a]=='b' && s[a+1]=='c'){
                c+=(1-start[a-1]);start[a-1]=1;
            }
            else{
                c+=(0-start[a-1]);start[a-1]=0;
            }
        }
        if (a+2<n){
            if (s[a]=='a' && s[a+1]=='b' && s[a+2]=='c'){
                c+=(1-start[a]);start[a]=1;
            }
            else{
                c+=(0-start[a]);start[a]=0;
            }
        }
        cout<<c<<"\n";
    }


    return 0;
}

