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

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vi dp(1<<m,1e9);
    dp[0]=0;
    vector<vi> adj(26,vi(26));
    for (int i=0;i<s.size()-1;++i){
        adj[s[i]-'a'][s[i+1]-'a']++;
        adj[s[i+1]-'a'][s[i]-'a']++;
    }
    str first;
    for (char i ='a';i<(m+'a');++i){
        first+=(char)i;
    }



    int mx=1<<m;
    vi c(mx);
    for (int i=0;i<mx;++i){
        for (int j=0;j<m;++j){
            if (i & (1<<j)){
                ++c[i];
            }
        }
    }

    for (int i=1;i<mx;++i){
        for (int j=0;j<m;++j){
            if (i & (1<<j)){
                int x=i^(1<<j);int add=0;
                for (int k=0;k<m;++k){
                    if (x & (1<<k)){
                        add +=adj[j][k] * (c[i]);
                    }
                    else if (k!=j){
                        add -=adj[j][k] * (c[i]);
                    }
                }
                dp[i]=min(dp[i],dp[x]+add);
            }
        }
    }
//    for (int i:dp){
//        cout<<i<<" ";
//    }
//    cout<<endl;
    cout<<dp[mx-1];

    return 0;
}

