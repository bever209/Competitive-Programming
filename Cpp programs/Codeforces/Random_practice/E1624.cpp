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
        int n,m;cin>>n>>m;
        string s;str arr[n];
        vector<str> make(m);

        for (int i=0;i<n;++i) cin>>arr[i];
        cin>>s;

        set<str> poss;
        map<str,pair<int,pii>> map;
        int c=0;
        for (auto j:arr) {
            for (int i = 0; i<=m-2; ++i) {
                poss.insert(j.substr(i,2));
                if (!map.count(j.substr(i,2))){
                    map[j.substr(i,2)]={c,{i,i+1}};
                }
                if (i+3<=m) {
                    poss.insert(j.substr(i, 3));
                    if (!map.count(j.substr(i,3))){
                        map[j.substr(i,3)]={c,{i,i+2}};
                    }
                }
            }
            ++c;
        }

        vector<bool> works(m);
        for (int i=m-2;i>=0;--i){
            if (poss.count(s.substr(i,2))){
                if (i+2==m) works[i]=true;
                else works[i]=works[i] | works[i+2];

                if (works[i]){
                    make[i]=s.substr(i,2);continue;
                }
            }
            if (i+3<=m && poss.count(s.substr(i,3))){
                if (i+3==m) works[i]=true;
                else works[i]=works[i]|works[i+3];

                if (works[i]){
                    make[i]=s.substr(i,3);continue;
                }
            }
        }


        if (works[0]){
            int ind=0;
            int ans=0;
            while (ind<m){
                str x=make[ind];
                auto a=map[x];
                ind+=(a.s.s-a.s.f+1);++ans;
            }
            cout<<ans<<endl;
            ind=0;
            while (ind<m){
                str x=make[ind];
                auto a=map[x];
                cout<<a.s.f+1<<" "<<a.s.s+1<<" "<<a.f+1<<endl;
                ind+=(a.s.s-a.s.f+1);
            }
        }
        else{
            cout<<-1<<endl;
        }
    }

    return 0;
}

