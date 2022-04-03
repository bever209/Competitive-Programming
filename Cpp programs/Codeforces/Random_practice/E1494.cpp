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


    int n,mm;cin>>n>>mm;

    vector<vi> adj;
    map<pii,char> m;
    int c_same=0; // goes back and forth and has same letter
    int c_diff=0; // goes back and forth and has diff letter
    while (mm--){
        str s;cin>>s;
        if (s=="+"){
            int a,b;char c;
            cin>>a>>b>>c;--a;--b;
            m.insert({{a,b},c});
            if (m.count({b,a})){
                if (m[{b,a}]==c){
                    ++c_same;
                }
                else{
                    ++c_diff;
                }
            }
        }
        else if (s=="-"){
            int a,b;cin>>a>>b;
            --a;--b;
            char c=m[{a,b}];
            m.erase({a,b});
            if (m.count({b,a})){
                if (m[{b,a}]==c){
                    --c_same;
                }
                else{
                    --c_diff;
                }
            }
        }
        else if (s=="?"){
            int x;cin>>x;
            if (x%2==1){
                if ((c_same+c_diff)>0){
                    cout<<"YES";
                }
                else{
                    cout<<"NO";
                }
            }
            else{
                if (c_same>0){
                    cout<<"YES";
                }
                else{
                    cout<<"NO";
                }
            }
            cout<<endl;
        }
    }


    return 0;
}

