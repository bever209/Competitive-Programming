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

    string s;cin>>s;
    int n=s.length();


    set<char> st;
    for (int i=0;i<n;++i) st.insert(s[i]);
    vector<char> x;
    for (char i:st) x.pb(i);

    // x contains all the unique chars

    vi dp(1<<x.size(),n);
    dp[0]=1;

    vector<vi> adj(26,vi(26));
    for (int i=0;i<n-1;++i){
        adj[s.at(i)-'a'][s.at(i+1)-'a']++;
    }

    for (int i=1;i<1<<x.size();++i){
        for (int j=0;j<x.size();++j){
            if (1<<j & i){
                int d=i^(1<<j);int sum=0;
                for (int k=0;k<x.size();++k){
                    if (1<<k & i){
                        sum+=adj[x[j]-'a'][x[k]-'a'];
                    }
                }
                dp[i]=min(dp[i],dp[d]+sum);
            }
        }
    }
    cout<<(dp[(1<<x.size())-1]);
    


    return 0;
}

