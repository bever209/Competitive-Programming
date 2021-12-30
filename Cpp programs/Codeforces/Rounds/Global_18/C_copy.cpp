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

int compare(string a,str b){
    int ans=0;
    for (int i=0;i<a.size();++i){
        if (a.at(i)!=b.at(i)){
            ++ans;
        }
    }
    return ans;
}

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;cin>>tc;
    while (tc--) {
        int n;cin>>n;
        string a,b;cin>>a>>b;
        if (a==b){
            cout<<0<<"\n";continue;
        }
        int x=0,y=0;
        for (int i=0;i<n;++i){
            if (a.at(i)=='1') ++x;
            if (b.at(i)=='1') ++y;
        }
        if (x==y || n-x+1==y) {
            int same = 0;
            int diff = 0;int change_ind=-1;int best_ind=-1;
            for (int i = 0; i < n; ++i) {
                if (a.at(i)=='1') change_ind=i;
                if (a.at(i) != b.at(i)) {
                    ++diff;
                } else {
                    ++same;
                    if (a.at(i)=='1') best_ind=i;
                }
            }
            int ans=1e9;
            if (n-x+1==y) {
                if (best_ind >= 0) change_ind = best_ind;

                string t = "";

                for (int i = 0; i < n; ++i) {
                    if (i != change_ind) {
                        if (a.at(i) == '1') {
                            t += '0';
                        } else {
                            t += '1';
                        }
                    } else {
                        t += a.at(i);
                    }
                }
               ans=min(ans,1+compare(t,b));
            }
            if (x==y){
                ans=min(ans,diff);
            }
            cout<<ans<<"\n";
        }
        else{
            cout<<"-1\n";
        }

    }


    return 0;
}

