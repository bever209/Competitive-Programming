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

    int q,a0,c0;
    cin>>q>>a0>>c0;
    vector<vi> blift;
    blift.pb(vi(22,-1));
    vi amt;
    vector<ll> cost;
    amt.pb(a0);cost.pb(c0);
    map<int,int> m;m[0]=0;
    int cnt=0;
    while (cnt<q){
        int type;cin>>type;++cnt;
        if (type==1){
            m[cnt]=amt.size();
            int a,b,c;cin>>a>>b>>c;a=m[a];
            amt.pb(b);
            cost.pb(c);
            vi lift(22,-1);
            lift[0]=a;
            for (int i=1;i<22;++i){
                if (lift[i-1]==-1) break;
                lift[i]=blift[lift[i-1]][i-1];
            }
            blift.pb(lift);
        }
        else{
            int tot=0;ll ans=0; // number and cost
            int a,b;cin>>a>>b;a=m[a];
            while (b>0 && amt[a]>0){
                int c=a;
                for (int i=21;i>=0;--i){
//                    cout<<c<<" "<<i<<endl;
//                    cout<<blift[c][i]<<endl;
//                    cout<<"hi"<<endl;
                    if (blift[c][i]!=-1){
                        if (amt[blift[c][i]]>0){
                            c=blift[c][i];
                        }
                    }
                }
                ll sub=min(amt[c],b);
                tot+=sub;ans+=sub * cost[c];
                b-=sub;amt[c]-=sub;
            }
            cout<<tot<<" "<<ans<<endl;

        }
    }


    return 0;
}

