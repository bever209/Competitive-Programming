#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<ll>;
using str = string;

const ll inf = 2 * 1e18;
const int maxn=5005;
const ll mod=998244353;
int main() {
    vector<vi> choose(maxn,vi(maxn));
    for (int i=0;i<maxn;++i) choose[i][0]=choose[i][i]=1;
    for (int i=1;i<maxn;++i){
        for (int j=1;j<i;++j){
            choose[i][j]=choose[i-1][j-1]+choose[i-1][j];
            choose[i][j]%=mod;
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;str s;cin>>s;
    //vi ones;ones.pb(-1);
    ll ans=0;
    int nn=0;
    for (int i=0;i<n;++i) if (s[i]=='1') ++nn;
    if (nn<k){
        cout<<1;return 0;
    }

    for (int i=0;i<n;++i){
        int c=0;
        if (s[i]=='1') ++c;
        for (int j=i+1;j<n;++j){
            if (s[j]=='1') ++c;
            if (c>k) break;
            int len=j-i+1;
            int num1=c;
            int num0=len-c;
            if (s[i]=='1') --num0;
            else --num1;
            if (s[j]=='1') --num0;
            else --num1;
            if (num0<0 || num1<0) continue;

            ans=(ans+choose[num0+num1][num0])%mod;
        }
    }
    ++ans;
    cout<<ans%mod<<endl;




    return 0;
}

